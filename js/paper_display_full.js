var html = ""

window.onload = function() {
    var url = "paper.json"
    var request = new XMLHttpRequest();
    request.open("get", url);
    request.send(null);
    request.onload = function() {
        if(request.status == 200) {
            var obj = JSON.parse(request.responseText);
            obj.sort(function(a, b) { return (b.year || 0) - (a.year || 0); });

            var lastYear = "";
            for(var i=0; i<obj.length; i++) {
                var e = obj[i];
                var title = e.title
                var author = e.author
                var link = e.url
                var publisher = e.publisher
                var year = e.year
                var volume = e.volume
                var page = e.page
                var equal = e.equal
                var tier = e.tier
                var highlight = e.highlight
                var corresponding = e.corresponding

                if (year != lastYear) {
                    html += '<tr class="year-row"><td>' + year + '</td></tr>';
                    lastYear = year;
                }

                var equal_str = ""
                if(equal == true) {
                    equal_str = " † Equal contribution"
                }

                for(var j=0 ; j<author.length ; j++){
                    var is_yang = (author[j] == "Yibiao Yang" || author[j] == "Yibiao Yang*" || author[j] == "杨已彪" || author[j] == "杨已彪*");
                    var bare = author[j].replace("*", "");
                    var is_corr = false;
                    if(corresponding === true) {
                        is_corr = is_yang;
                    } else if(Array.isArray(corresponding)) {
                        is_corr = (corresponding.indexOf(bare) >= 0);
                    }
                    if(is_yang) {
                        author[j] = "<b>" + bare + (is_corr ? "*" : "") + "</b>";
                    } else if(is_corr) {
                        author[j] = bare + "*";
                    }
                }
                var author_str = author.join(', ');

                var meta = e.meta
                var meta_array = []
                for(let key in meta){
                    if(meta[key] != false){
                        meta_array.push('<a href="' + meta[key] + '">' + key + '</a>')
                    }
                }
                var meta_str = meta_array.join('  /  ')

                var title_str = title;
                if(link != "" && link != null) {
                    title_str = '<a href="' + link + '" class="paper-title">' + title + '</a>';
                }

                var suffix = publisher + ", " + year;
                if(volume != "" && volume != null) {
                    suffix += ", Vol. " + volume;
                }
                if(page != "" && page != null) {
                    suffix += ", pp. " + page;
                }

                var tier_str = "";
                if(tier != "" && tier != null) {
                    var cls = (tier.indexOf("CCF-A") >= 0) ? 'venue-ccf-a' : '';
                    tier_str = '(<span class="' + cls + '">' + tier + '</span>)';
                }

                var row_class = (highlight == true) ? 'publication-row highlight' : 'publication-row ';

                html +=
                '<tr class="' + row_class + '">' +
                    '<td>' +
                        '<p class="publication-item">' +
                            title_str + '<br>' +
                            author_str + '<br>' +
                            '<em>' + suffix + ' ' + tier_str + equal_str + '</em>' +
                            (meta_str != "" ? '<br>' + meta_str : '') +
                        '</p>' +
                    '</td>' +
                '</tr>';
            }
            document.getElementById("paper").innerHTML = '<table class="publications-table"><tbody>' + html + '</tbody></table>';
        }
    }
}
