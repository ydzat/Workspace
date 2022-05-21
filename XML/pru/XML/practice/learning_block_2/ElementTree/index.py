import xml.etree.ElementTree as ET

# 遍历节点函数
def read():
    # 创建XMLXML文档节点树
    tree = ET.parse("deliveries.xml")
    # root是根节点
    root = tree.getroot()
    # 获取所有的article节点。此处要注意findall中要写XPath表达式
    article_node_list = root.findall("article")
    print(article_node_list)
    # 遍历所有的article节点
    for article_node in article_node_list:
        print("------记录------")
        id = article_node.attrib["id"]
        print("id : {}".format(id))
        #遍历article节点所有子节点
        for node in article_node:
            # 判断是否是price节点
            if node.tag == "price":
                # 取出unitprice属性
                unitprice = node.attrib["unitprice"]
                print("unitprice : {}".format(unitprice))
            print("{} : {}".format(node.tag, node.text))

# 插入节点
def insert():
    # 创建XML文档节点树
    tree = ET.parse("deliveries.xml")
    # root是根节点
    root = tree.getroot()
    # 创建一个新的article节点对象
    new_article_node = ET.Element("article")
    new_article_node.attrib["id"] = "123456"
    # 创建一个新的name节点对象
    new_name_node = ET.SubElement(new_article_node, "name")
    new_name_node.text = "pears"
    # 创建一个新的price节点对象
    new_price_node = ET.SubElement(new_article_node, "price")
    new_price_node.text = "20"
    new_price_node.attrib["unitprice"] = "true"
    # 创建一个新的supplier节点对象
    new_supplier_node = ET.SubElement(new_article_node, "supplier")
    new_supplier_node.text = "Pear Inc."
    # 将article节点添加到根节点deliveries中
    root.append(new_article_node)
    # 保存到XML文件中
    tree.write("deliveries_2.xml", "utf-8")
    
# 删除节点
def remove():
    # 创建XML文档节点树
    tree = ET.parse("deliveries.xml")
    # root是根节点
    root = tree.getroot()
    # XPath表达式
    expression = ".//price[@unitprice='true']/.."
    # # 找到复合表达式的第一个
    # article_node = root.find(expression)
    # # 删除节点
    # root.remove(article_node)
    # # 保存到XML文件中国
    # tree.write("./deliveries_3.xml", "utf-8")
    article_nodes = root.findall(expression)
    for article_node in article_nodes:
        root.remove(article_node)
    tree.write("./deliveries_4.xml", "utf-8")

# 主函数
def main():
    read()
    # insert()
    remove()

if __name__ == '__main__':
    main()