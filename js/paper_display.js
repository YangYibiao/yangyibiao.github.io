var html = ""

window.onload = function() {
    var url = "../paper.json"
    var request = new XMLHttpRequest();
    request.open("get", url);
    request.send(null);
    request.onload = function() {
        if(request.status == 200) {
            var obj = JSON.parse(request.responseText);
            console.log(obj);
            for(var i=0; i<obj.length; i++) {
                var title = obj[i].title
                var author = obj[i].author
                var url = obj[i].url
                var publisher = obj[i].publisher
                var year = obj[i].year
                var equal = obj[i].equal
                var tier = obj[i].tier
                var highlight = obj[i].highlight

                var equal_str = ""
                if(equal == true) {
                    equal_str = "  (* Equal contribution)"
                }

                for(var j=0 ; j<author.length ; j++){
                    if(author[j] == "Yibiao Yang" || author[j] == "Yibiao Yang*"){
                        author[j] = "<b>" + author[j] + "</b>";
                    }
                }
                var author_str = author.join(', ');

                var meta = obj[i].meta
                
                var meta_array = []
                for(let key in meta){
                    if(meta[key] != false){ 
                        meta_array.push("<a href=" + meta[key] + ">" + key + "</a>")
                    }
                }
                var meta_str = meta_array.join('  /  ')
            

                if (highlight == true) {
                    html += 
                    "\
                    <tr bgcolor='#ffffd0'>\
                        <td width='60%' valign='middle'>\
                        <p>\
                            <a href=" + url + " style='font-size:18px'>" + title + "</a>\
                            <br>" + author_str + 
                            "<br>\
                            <em>"+ publisher + "  " + year + " (" + "<span style='color: red;'>" + tier + "</span>" + ")" + equal_str + "</em>\
                            <br>\
                            " + meta_str + " <br> \
                        </font>\
                            <br>\
                        </td>\
                    </tr>\
                    "
                } else {
                    html += 
                    "\
                    <tr bgcolor='#ffffff'>\
                        <td width='60%' valign='middle'>\
                        <p>\
                            <a href=" + url + " style='font-size:18px'>" + title + "</a>\
                            <br>" + author_str + 
                            "<br>\
                            <em>"+ publisher + "  " + year + " (" + "<span style='color: red;'>" + tier + "</span>" + ")" + equal_str + "</em>\
                            <br>\
                            " + meta_str + " <br> \
                        </font>\
                            <br>\
                        </td>\
                    </tr>\
                    "
                }
            }
            document.getElementById("paper").innerHTML = html;
        }
    }
}
