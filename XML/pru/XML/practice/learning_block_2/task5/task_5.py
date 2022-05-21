# -*- coding: UTF-8 -*-

'''
DOM：按照要求解析XML并输出 2
'''

from xml.dom.minidom import parse
import xml.dom.minidom as xdm

DOMTree = parse("deliveries.xml")
deliveries = DOMTree.documentElement

articles = deliveries.getElementsByTagName("article")

for article in articles:
    supplier = article.getElementsByTagName('supplier')[0]
    name = article.getElementsByTagName('name')[0]
    print("%s" % supplier.childNodes[0].data + " supplies: %s" % name.childNodes[0].data)
    