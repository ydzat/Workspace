# -*- coding: UTF-8 -*-
from xml.dom.minidom import parse
import xml.dom.minidom

domtree = xml.dom.minidom.parse("deliveries.xml") # 生成dom树
deliveries = domtree.documentElement # 所有树的根

# 获取所有article到articleList中
articleList = deliveries.getElementsByTagName("article")

# 获取所以供应商
supplierList = []
for article in articleList:
    supplier = article.getElementsByTagName("supplier")[0]
    supplierList.append(supplier.childNodes[0].data)
supplierList = list(set(supplierList)) # 删除列表中的重复元素

# 创建一个二维列表，在子列表中存储所需的供应商和产品名称以及产品类别信息的数量
L = []

# 遍历supplierList获取所需要的元素
for suppliers in supplierList:
    # 创建一下格式额子列表
    # [供应商, 产品类别数, 产品名称, 产品名称, ...]
    # 获取产品类别数并将其存储在此处, 以便分类
    L1 = []
    L1.append(suppliers)
    i = 0 # 初始化产品类别数
    L1.append(i)
    for article in articleList:
        name = article.getElementsByTagName("name")[0]
        supplier = article.getElementsByTagName("supplier")[0]
        if supplier.childNodes[0].data == suppliers:
            i = i + 1 # 获取产品类别数
            L1.append(name.childNodes[0].data)
    L1[1] = i # 将供应商提供的产品类别数量存储在子列表的第二个元素中
    L.append(L1) # 将子列表作为元素添加到二维列表
L = sorted(L, key=(lambda x:[-x[1], x[0]]), reverse=True) # 按照子列表中产品类别数量升序，按照供应商的首字母降序，对整个二维列表排序

# 根据需要逐一打印元素
for i in range(len(L)):
    print(L[i][0], " supplies: ", end="")
    for j in range(2, L[i][1]+2):
        print(L[i][j], "", end="")
    print(" ")

