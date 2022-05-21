'''
Author: your name
Date: 2022-02-12 15:24:28
LastEditTime: 2022-02-12 15:43:20
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task2.1.py
'''
import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()

g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\translators.rdf")
g1.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf")
g2.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\books.rdf")

g = g + g1 + g2

authorPaar = {}     # 作者名字URI ： 作者实际名字
authorAndBook = {}  # 作者名字 ： [书]
bookPaar = {}       # 书名字URI ： 书实际名字
transPaar = {}      # 翻译名字URI ： 翻译实际名字
transAndBook = {}   # 翻译名字 ： [书]

for s,p,o in g:
    if "authorName" in str(p) and str(p) not in authorPaar:
        authorPaar[str(s)] = str(o)
    if "hasWritten" in str(p):
        if str(s) not in authorAndBook:
            authorAndBook[str(s)] = []
        authorAndBook[str(s)].append(str(o))
    if "bookName" in str(p):
        bookPaar[str(s)] = str(o)
    if "authorName" in str(p) and str(p) not in transPaar:
        transPaar[str(s)] = str(o)
    if "hasTranslated" in str(p):
        if str(s) not in transAndBook:
            transAndBook[str(s)] = []
        transAndBook[str(s)].append(str(o))
tempAB = {}     # 将authorAndBook的key从URI格式替换为作者实际名字
for i in authorAndBook.keys():
    tempAB[authorPaar[i]] = authorAndBook[i]
authorAndBook = tempAB
# 将authorAndBook中的value内书名字URI替换为书实际名字
for i in authorAndBook.keys():
    tempBook = []
    for j in authorAndBook[i]:
        tempBook.append(bookPaar[j])
        authorAndBook[i] = tempBook
        
# 将transAndBook的key从URI格式名字替换为翻译实际名字
tempTB = {}
for i in transAndBook.keys():
    tempTB[transPaar[i]] = transAndBook[i]
transAndBook = tempTB

# 将transAndBook的value内书名字URI替换为实际书名字
for i in transAndBook.keys():
    tempBook = []
    for j in transAndBook[i]:
        tempBook.append(bookPaar[j])
        transAndBook[i] = tempBook
# 函数，根据书名找到其翻译者，返回翻译者列表
def findTranslator(transAndBook, bookName):
    nameList = []
    for i in transAndBook.keys():
        if bookName in transAndBook[i]:
            nameList.append(i)
    return nameList
# 输出
for i in authorAndBook.keys():
    print(i + "wrote:")
    for j in authorAndBook[i]:
        print("\t" + j)
        nameList = findTranslator(transAndBook, j)
        for k in range(len(nameList)):
            print("\t\t translated by: " + nameList[k])


     
