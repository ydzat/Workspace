# -*- coding: UTF-8 -*-

'''
DOM：按照要求解析XML并输出 1
'''

from xml.dom.minidom import parse
import xml.dom.minidom

# 使用minidom解析器打开xml文档
DOMTree = parse("deliveries.xml")
delivery = DOMTree.documentElement



# 在集合中获取所有货物
articles = delivery.getElementsByTagName("article")

# ID数组用于存储article id用于判断一致性
id = []

# 打印每项货物的详细信息
for article in articles:
    print("Article")
    # if article.hasAttribute("id"):
    #     # 判断id是否满足一致性，满足追加到数组中并按照要求输出
    #     if(article.getAttribute("id") not in id):
    #         id.append(article.getAttribute("id"))
    #         print("   ID:" + article.getAttribute("id"))
    # 问题1：修改id只是在输出时进行修改，并未修改文档中的值
    # 问题2：什么修改方式比较好，这里使用+1的方式，但是这样会修改很多id的值，不是一个好方法
    t_id = article.getAttribute("id")
    if(t_id not in id):
        id.append(t_id)
        print("   ID:" + t_id)
    else:
        new_id = int(t_id) + 1
        while(str(new_id) in id):
            new_id += 1
        new_id = str(new_id)
        id.append(new_id)
        print("   id fehler! FIX: old:" + t_id + " -> new: " + new_id)

    # Price和Price的属性
    price = article.getElementsByTagName('price')[0]
    # 判断price的属性unitprice是否存在
    if price.hasAttribute("unitprice"):
        price_attribute = price.getAttribute("unitprice")
        print("   Price:" + price.childNodes[0].data, end="  ")
        print("Unitprice:" + price_attribute)

    # Name
    name = article.getElementsByTagName('name')[0]
    print("   Name:" + name.childNodes[0].data)

    # Supplier
    supplier = article.getElementsByTagName('supplier')[0]
    print("   Supplier:" + supplier.childNodes[0].data)