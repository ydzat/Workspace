"""
Write a Python program using the RDFlib package, which displays where authors and translators live.
A possible output could look like this (shortened)

John Lorge (Dresden) wrote:
    About a poor man
        translated by: Renate Koller (Berlin)
    My ghost
        translated by: Bert Klimer (Frankfurt)
   (...)

"""
from rdflib import Graph

g1 = Graph()
g2 = Graph()
g3 = Graph()
g4 = Graph()
g1.parse('./rdfFiles/authors.rdf')
g2.parse('./rdfFiles/books.rdf')
g3.parse('./rdfFiles/translators.rdf')
g4.parse("./rdfFiles/locations.rdf")
author = {}  # 统计所有作者
authors = {}
translators = {}  # 统计所以翻译者
translator = {}
location = {}  # 统计所以人居住地
count = 0


# 合并两个字典
def merge_two_dicts(x, y):
    z = x.copy()
    z.update(y)
    return z


# 创建字典1：以author.rdf中的的谓语为键，名字的属性值作为键值对的值
for s, p, o in g1:
    if not str(s) in author:
        if "authorName" in str(p):
            author[str(s)] = str(o)

# 创建字典2：以translator.rdf中的的谓语为键，名字的属性值作为键值对的值
for s, p, o in g3:
    if not str(p) in translators:
        if "authorName" in str(p):
            translators[str(s)] = str(o)

# 创建字典3：locations.rdf中的的谓语为键，名字的属性值作为键值对的值
for s, p, o in g4:
    if not str(s) in location:
        if "livesIn" in str(p):
            location[str(s)] = str(o)

# 创建字典4：以translators字典的值作为键，将在books.rdf中匹配到的所有的同一作者翻译的作品书籍添加到list中作为键值对的值
for index in translators:
    tlist = []
    for s, p, o in g3:
        if str(s) == index:
            for s1, p1, o1 in g2:
                if str(s1) == str(o):
                    tlist.append(str(o))
                translator[translators[index]] = tlist
# 合并两个字典
authors = merge_two_dicts(author, translators)

for index in author:
    # 外层循环输出作者和作者所在地区
    print(author[index], "(", location[index], ")", "wrote:")
    # 内循环1：通过authors.rdf，使用循环逐一匹配所有作者，并为他们的著书计数
    for s, p, o in g1:
        if str(s) == index:
            count = count + 1
            # 内循环2：通过books.rdf，使用循环匹配所有的书籍，输出书籍的真实名字
            for s1, p1, o1 in g2:
                if str(s1) == str(o):
                    print("    '", str(o1), "'")
                    # 内循环3：通过translator字典，使用循环匹配该书籍的所有翻译者，输出翻译者的名字
                    for abc in translator:
                        i = 0
                        for i in range(len(translator[abc])):
                            if translator[abc][i] == str(s1):
                                print("        translated by ", abc, end="")
                                for xyz in authors:
                                    if abc == authors[xyz]:
                                        print(" (", location[xyz], ")")
    # 判断计数
    if count - 1 == 0:
        print("    No Books")
    # 计数重置
    count = 0
