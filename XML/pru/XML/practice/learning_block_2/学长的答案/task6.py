'''
Author: your name
Date: 2021-12-05 15:50:16
LastEditTime: 2021-12-05 16:37:09
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block2\task4.py
'''
from xml.dom.minidom import parse as xdmp
import xml.dom.minidom as xdm

DOMTree = xdmp("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block2\\deliveries.xml")
deliveries = DOMTree.documentElement

print("deliveries",end='')

if deliveries.hasAttribute("xmlns"):
    print(" xmlns: %s" % deliveries.getAttribute("xmlns"), end='')
if deliveries.hasAttribute("xmlns"):
    print(" xmlns:xsi: %s" % deliveries.getAttribute("xmlns:xsi"), end='')
if deliveries.hasAttribute("xsi:schemaLocation"):
    print(" xsi:schemaLocation: %s" % deliveries.getAttribute("xsi:schemaLocation"))

article = deliveries.getElementsByTagName("article")

id = []

for atc in article:

    if atc.hasAttribute("id"):
        t_id = atc.getAttribute("id")
        print ("   article id: %s" % t_id)
        if(t_id not in id):
            id.append(t_id)
        else:
            new_id = int(t_id) + 1
            while(str(new_id) in id):
                new_id = new_id + 1
            new_id = str(new_id)
            id.append(new_id)
            print("      id fehler! FIX: old:" + t_id + " -> new: " + new_id)


    name = atc.getElementsByTagName('name')[0]
    print("      name")
    print("         name: %s" % name.childNodes[0].data)
    price = atc.getElementsByTagName('price')[0]
    print("      price")
    if atc.hasAttribute("unitprice"):
        print("         unitprice: %s" % atc.getAttribute("uniprice"))
    print("         price: %s" % price.childNodes[0].data)
    supplier = atc.getElementsByTagName('supplier')[0]
    print("      supplier")
    print("         supplier: %s" % supplier.childNodes[0].data)
