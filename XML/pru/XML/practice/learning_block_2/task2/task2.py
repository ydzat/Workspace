# -*- coding: UTF-8 -*-
import xml.sax
class DeliveriesHandler(xml.sax.ContentHandler):
    def __init__(self):
        self.a = {}     # 用于存储子节点
        self.list = []  # 用于存储子节点集
        self.i = -1     # 计数
        self.g = 0      # ariticle字典的id
    def startElement(self, tag, attrs): # 元素开始事件内处理
        self.current = tag
        if self.current == "article":
            self.a = {}                 # 每次遇到新的article都会重置字典a，即编辑新的article节点
            self.a['g'] = None
            self.a['id'] = None
            self.a['name'] = None
            self.a['price'] = None
            self.a['supplier'] = None
            # 将计数赋值给article字典的id，并获取article节点的id属性
            self.i = self.i + 1
            self.a['g'] = self.i
            id = attrs['id']
            self.a['id'] = id
    # 内容事件处理
    def characters(self, content):
        if self.current == "name":
            self.name = content
        elif self.current == "price":
            self.price = "price"
        elif self.current == "supplier":
            self.supplier = "supplier"
     # 元素结束事件处理
    def endElement(self, tag):
        if self.current == "name":
            self.a["name"] = self.name
        elif self.current == "price":
            self.a["price"] = self.price
        elif self.current == "supplier":
            self.a["supplier"] = self.supplier
        if len(self.list) == 0:
            self.list.append(self.a)
        elif self.list[self.g]["g"] != self.a["g"]:
            self.g = self.g + 1
            self.list.append(self.a)
        self.current = ""

if(__name__ == "__main__"):
    # 创建一个 XMLReader
    parser = xml.sax.make_parser()
    # turn off namepsaces
    parser.setFeature(xml.sax.handler.feature_namespaces, 0)
    # 重写 ContextHandler
    Handler = DeliveriesHandler()
    parser.setContentHandler(Handler)
    parser.parse("deliveries.xml")
    label = ['id', 'name', 'price', 'supplier']
    print("<html><head><title>" + "Deliveries" + "</title></head>")
    print("<body><h1>Deliveries</h1><hr>")
    print('<table border="1"><tr><th>Number</th><th>Article</th><th>Price</th><th>Supplier</th></tr>')
    for i in range(len(Handler.list)):
        print("<tr>", end="")
        for j in label:
            if Handler.list[i][j] != None:
                print("<td>", Handler.list[i][j], "</td>",end="")
            else:
                print("<td> N/A </td>")
        print("</tr>")
    print("</table></body></html>")
