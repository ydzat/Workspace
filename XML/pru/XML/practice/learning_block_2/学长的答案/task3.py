'''
Author: your name
Date: 2021-12-05 14:07:40
LastEditTime: 2021-12-05 15:46:20
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block2\task1.py
'''
import xml.sax

class Deliveries( xml.sax.ContentHandler ):
    list = []
    def __init__(self):
        self.CurrentData = ""
        self.article = ""
        self.name = ""
        self.price = ""
        self.supplier = ""

    def startElement(self, tag, attributes):
        self.CurrentData = tag
        
        if tag == "deliveries":
            # print(tag)
            xmlns = attributes["xmlns"]
            xmlns_xsi = attributes["xmlns:xsi"]
            xsi_schemaLocation = attributes["xsi:schemaLocation"]
            print(tag + " xmlns:" + xmlns + " xmlns:xsi:" + xmlns_xsi + " xsi:schemaLocation:" + xsi_schemaLocation)

        if tag == "article":
            id = attributes["id"]
            if(id not in Deliveries.list):
                Deliveries.list.append(id)
                print("   " + tag + " id:", id)
            else:  
                print("   " + tag + " id: detects consistency problems")

        elif tag == "name" or tag == "supplier":
            print("   " + tag)
        elif tag == "price":
            unitprice = attributes["unitprice"]
            print("   " + tag + " unitprice:",unitprice)
        
        
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

    def characters(self, content):
        if self.CurrentData == "article":
            self.article = content
        elif self.CurrentData == "name":
            self.name = content
        elif self.CurrentData == "price":
            self.price = content
        elif self.CurrentData == "supplier":
            self.supplier = content
        
        

parser = xml.sax.make_parser()
parser.setFeature(xml.sax.handler.feature_namespaces, 0)

Handler = Deliveries()
parser.setContentHandler( Handler )

parser.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block2\\deliveries.xml")