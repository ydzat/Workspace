'''
Author: your name
Date: 2021-12-05 14:07:40
LastEditTime: 2021-12-05 15:34:04
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block2\task1.py
'''
import xml.sax

class Deliveries( xml.sax.ContentHandler ):
    def __init__(self):
        self.CurrentData = ""
        self.html = ""
        self.head = ""
        self.title = ""
        self.body = ""
        self.h1 = ""
        self.table = ""
        self.tr = ""
        self.td = ""

    def startElement(self, tag, attributes):
        self.CurrentData = tag
        
        if tag == "html":
            print(tag)
        if tag == "head":
            print("   " + tag)
        elif tag == "title":
            print("      " + tag)

        elif tag == "body":
            print("   " + tag)
        elif tag == "h1":
            print("      " + tag)
        elif tag == "hr":
            print("      " + tag)
        elif tag == "table":
            border = attributes["border"]
            print("      " + tag + " border:" + border)
        elif tag == "tr":
            print("         tr")
        elif tag == "th":
            print("            th")
        elif tag == "td":
            print("            td")
        
    def endElement(self, tag):
        if self.CurrentData == "head":
            print("   head: ", self.head)
        
        elif self.CurrentData == "title":
            print("      title: ",self.title)
        elif self.CurrentData == "body":
            print("   body:", self.body)
        elif self.CurrentData == "h1":
            print("      h1: ",self.h1)
        # elif self.CurrentData == "hr":
        #     print("      hr:", self.hr)
        elif self.CurrentData == "table":
            print("      table:", self.table)
        elif self.CurrentData == "tr":
            print("         tr", self.tr)
        elif self.CurrentData == "th":
            print("            th:",self.th)
        elif self.CurrentData == "td":
            print("            td:",self.td)
        self.CurrentData = ""

    def characters(self, content):
        if self.CurrentData == "head":
            self.head = content
        elif self.CurrentData == "title":
            self.title = content
        elif self.CurrentData == "body":
            self.body = content
        elif self.CurrentData == "h1":
            self.h1 = content
        elif self.CurrentData == "hr":
            self.hr = content
        elif self.CurrentData == "table":
            self.table = content
        elif self.CurrentData == "tr":
            self.tr = content
        elif self.CurrentData == "th":
            self.th = content
        elif self.CurrentData == "td":
            self.td = content
        
        

parser = xml.sax.make_parser()
parser.setFeature(xml.sax.handler.feature_namespaces, 0)

Handler = Deliveries()
parser.setContentHandler( Handler )

parser.parse("deliveries.xml")