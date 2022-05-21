"""
Write a Python program using the RDFlib package, that displays which author wrote which book. A possible output could
look like this (shortened):


John Lorge wrote:
    About a poor man
    My ghost
    The Bridge
Clarence Will wrote:
    hands up
    cooking with Hella
   (...)

"""

from rdflib import Graph

g1 = Graph()
g2 = Graph()
g1.parse('./rdfFiles/authors.rdf')
g2.parse('./rdfFiles/books.rdf')
author = {}
count = 0

# 创建字典：以author.rdf中的的谓语为键，名字的属性值作为键值对的值
for s, p, o in g1:
    if not str(s) in author:
        if "authorName" in str(p):
            author[str(s)] = str(o)

# 循环输出：根据作者进行分输出
for index in author:
    # 外循环：输出作者
    print(author[index], "wrote:")
    # 第一层内循环：分类计数
    for s, p, o in g1:
        if str(s) == index:
            count = count + 1
            # 第二层内循环：与books.rdf建立联系循环输出每个作者的作品
            for s1, p1, o1 in g2:
                if str(s1) == str(o):
                    print("    '", str(o1), "'")
    # 每个“作者”统计完毕判断计数
    if count - 1 == 0:
        print("    No Books")
    else:
        print(count - 1, "books")
    # 重置计数
    count = 0
