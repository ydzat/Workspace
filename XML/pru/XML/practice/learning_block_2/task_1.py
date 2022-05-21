# -*- coding: UTF-8 -*-

'''
SAX：按照要求解析XML并输出，每一层空三格
'''

import xml.sax

class DeliveriesHandler(xml.sax.ContentHandler):
    def __init__(self):
        self.CurrentData = ""
        self.name = ""
        self.price = ""
        self.supplier = ""

    # 元素开始时间内处理
    def startElement(self, tag, attributes):
        self.CurrentData = tag
        if tag == "deliveries":
            print("Deliveries")
        elif tag == "article":
            id = attributes["id"]
            print("   article id=" + id)
        elif tag == "price":
            unitprice = attributes["unitprice"]
            print("      unitprice:" + unitprice)
    
    # 元素结束事件处理
    def endElement(self, tag):
        if self.CurrentData == "name":
            print("      name:" + self.name)
        elif self.CurrentData == "price":
            print("      price:" + self.price)
        elif self.CurrentData == "supplier":
            print("      supplier:" + self.supplier)
        self.CurrentData = ""
    
    # 内容事件处理
    def characters(self, content):
        if self.CurrentData == "name":
            self.name = content
        elif self.CurrentData == "price":
            self.price = content
        elif self.CurrentData == "supplier":
            self.supplier = content

if(__name__ == "__main__"):

    # 创建一个 XMLReader
    parser = xml.sax.make_parser()
    # turn off namepsaces
    parser.setFeature(xml.sax.handler.feature_namespaces, 0)

    # 重写 ContextHandler
    Handler = DeliveriesHandler()
    parser.setContentHandler(Handler)

    parser.parse("deliveries.xml")
