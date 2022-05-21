# -*- coding: UTF-8 -*-

import xml.dom.minidom

domtree = xml.dom.minidom.parse("deliveries.xml") # 生成dom树
group = domtree.documentElement # 所有树的根

# 输出
print("<html><head><title>" + "Deliveries" + "</title></head>")
print("<body><h1>Deliveries</h1><hr>")
print('<table border="1"><tr><th>Number</th><th>Article</th><th>Price</th><th>Supplier</th></tr>')

articles = group.getElementsByTagName("article")
for article in articles:
    print("<tr>", end="")
    if article.hasAttribute("id"):
        print("<td>%s</td>" % article.getAttribute("id"), end="")
    print("<td>%s</td>" % article.getElementsByTagName('name')[0].childNodes[0].data, end="")
    print("<td>%s</td>" % article.getElementsByTagName('price')[0].childNodes[0].data, end="")
    print("<td>%s</td>" % article.getElementsByTagName('supplier')[0].childNodes[0].data, end="")
    print("</tr>")
print("</table></body></html>")
