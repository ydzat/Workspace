'''
Author: your name
Date: 2021-12-05 15:50:16
LastEditTime: 2021-12-05 16:25:00
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block2\task4.py
'''
from xml.dom.minidom import parse as xdmp
import xml.dom.minidom as xdm

DOMTree = xdmp("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block2\\deliveries.xml")
deliveries = DOMTree.documentElement

article = deliveries.getElementsByTagName("article")

for atc in article:
    supplier = atc.getElementsByTagName('supplier')[0]
    name = atc.getElementsByTagName('name')[0]
    print("%s" % supplier.childNodes[0].data + " supplies: %s" % name.childNodes[0].data)
