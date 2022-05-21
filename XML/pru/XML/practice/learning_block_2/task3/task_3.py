# -*- coding: UTF-8 -*-
import xml.sax
class Deliveries(xml.sax.ContentHandler):
    # list作为全局变量收集id用以检测id一致性
    list = []
    def __init__(self):
        self.CurrentData = ""
        self.name = ""
        self.price = ""
        self.supplier = ""
    def startElement(self, tag, attributes):
        self.CurrentData = tag  
        if tag == "deliveries":
            print(tag)

        if tag == "article":
            id = attributes["id"]
            if(id not in Deliveries.list):
                Deliveries.list.append(id)
                print("   " + tag + " id:", id)
            else:  
                print("   " + tag + " id: detects consistency problems")
        elif tag == "price":
            unitprice = attributes["unitprice"]
            print("      unitprice:" + unitprice)  
    def characters(self, content):
        if self.CurrentData == "article":
            self.article = content
        elif self.CurrentData == "name":
            self.name = content
        elif self.CurrentData == "price":
            self.price = content
        elif self.CurrentData == "supplier":
            self.supplier = content
    def endElement(self, tag):
        if self.CurrentData == "article":
            print("   article: ", self.article)
        
        elif self.CurrentData == "name":
            print("      name: ",self.name)
        elif self.CurrentData == "price":
            print("      price:", self.price)
        elif self.CurrentData == "supplier":
            print("      supplier: ",self.supplier)
        self.CurrentData = ""       
if(__name__ == "__main__"):
    # 创建一个 XMLReader
    parser = xml.sax.make_parser()
    # turn off namepsaces
    parser.setFeature(xml.sax.handler.feature_namespaces, 0)
    # 重写 ContextHandler
    Handler = Deliveries()
    parser.setContentHandler(Handler)
    parser.parse("deliveries.xml")