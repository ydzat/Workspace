'''
Author: your name
Date: 2022-02-13 18:54:34
LastEditTime: 2022-02-13 19:13:00
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\XML - Gaedke\ws16-17\task5.py
'''
import xml.sax
import copy

class Collection(xml.sax.ContentHandler):
    def __init__(self):
        self.current = ""
        self.pos = ""
        self.coll = {}
        self.list = []
    def startElement(self, tag, attrs):
        self.current = tag
        
        if self.current == "collection":
            self.coll[attrs["shelf"]] = []
            self.pos = attrs["shelf"]
        if self.current == "book":
            self.coll[self.pos].append(attrs["title"])
    def characters(self, content):
        if self.current == "author":
            self.coll[self.pos].append(content)
    def endElement(self, tag):
        if tag == "collection":
            temp = copy.deepcopy(self.coll)
            self.list.append(temp)
        self.current=""

if(__name__ == "__main__"):
    parser = xml.sax.make_parser()
    parser.setFeature(xml.sax.handler.feature_namespaces, 0)
    Handler = Collection()
    parser.setContentHandler(Handler)
    parser.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\XML - Gaedke\\ws16-17\\task5.xml")

    print(Handler.list)