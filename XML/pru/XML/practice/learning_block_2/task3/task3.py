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
    idlist = [] # 存储所有的id
    # 统计所有id
    for i in range(len(Handler.list)):
        idlist.append(Handler.list[i]['id'])
    idset = set(idlist) # 去重
    idrepeat = [] # 用于存储所有重复的id元素
    # 统计所有重复的id
    for i in idset:
        if idlist.count(i) > 1: # 判断某个元素的id是否重复
            idrepeat.append(i)
    # 输出重复
    for i in idrepeat:
        print("Inconsistent articles:")
        for j in range(len(Handler.list)):
            if Handler.list[j]['id'] == i:
                print("ID:", Handler.list[j]['id'], " Name:", Handler.list[j]['name'], " Price:", Handler.list[j]['price'], " Supplier:", Handler.list[j]['supplier'])
        print(" ")
        