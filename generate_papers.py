import json

with open("paper.json", encoding="utf-8") as f:
    papers = json.load(f)

html = ""

def is_top_conf(tier):
    return any(x in tier for x in ["POPL", "PLDI", "SOSP", "OSDI", "ASPLOS", "ATC", "OOPSLA"])

for entry in papers:
    if "CCF-A" not in entry["tier"] or entry.get("highlight") == False:
        continue

    title = entry["title"]
    url = entry["url"] or "https://yangyibiao.github.io"
    authors = entry["author"]

    corr = entry.get("corresponding")

    def is_corr(a):
        bare = a.replace("<b>", "").replace("</b>", "")
        if corr is True:
            return "Yibiao Yang" in bare or "杨已彪" in bare
        if isinstance(corr, list):
            return bare in corr
        return False

    authors = [
        f"<b>{a}</b>" if "Yibiao Yang" in a or "杨已彪" in a else a
        for a in authors
    ]
    authors = [a + "*" if is_corr(a) else a for a in authors]
    author_str = ", ".join(authors)

    equal_str = " († Equal contribution)" if entry.get("equal") else ""

    meta_links = [
        f'<a href="{value}">{key}</a>'
        for key, value in entry.get("meta", {}).items()
        if value
    ]
    meta_str = " / ".join(meta_links)

    bgcolor = "#ffffd0" if is_top_conf(entry["tier"]) else "#ffffff"
    tier_str = f"<b>{entry['tier']}</b>" if is_top_conf(entry["tier"]) else entry["tier"]

    html += f"""
<tr bgcolor="{bgcolor}">
  <td width='60%' valign='middle'>
    <p>
      <a href="{url}" style='font-size:18px'>{title}</a><br>
      {author_str}<br>
      <em>{entry['publisher']}, {entry['year']} (<span style='color:red;'>{tier_str}</span>){equal_str}</em><br>
      {meta_str}
    </p>
  </td>
</tr>
<br>
"""

with open("papers.html", "w", encoding="utf-8") as f:
    f.write(html)

print("生成完成 → papers.html")
