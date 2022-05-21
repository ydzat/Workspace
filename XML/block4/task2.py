'''
Author: your name
Date: 2022-01-18 07:45:57
LastEditTime: 2022-02-12 15:22:22
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task2.py
'''

import rdflib

g1 = rdflib.Graph()
g2 = rdflib.Graph()
g = rdflib.Graph()
g4 = rdflib.Graph()

aut = g2.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\books.rdf")
lit = g1.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf")
trans = g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\translators.rdf")
loc = g4.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\locations.rdf")

authorPaar = {}
authorAndBook = {}
bookPaar = {}

transPaar = {}
transAndBook = {}

authorAndLocation = {}

for s,p,o in g1:
    if "authorName" in str(p) and str(p) not in authorPaar:
        authorPaar[str(s)] = str(o)
    if "hasWritten" in str(p):
        if str(s) not in authorAndBook:
            authorAndBook[str(s)] = []
        authorAndBook[str(s)].append(str(o))
     

for s,p,o in g2:
    if "bookName" in str(p):
        bookPaar[str(s)] = str(o)

tempAB = {}

for i in authorAndBook.keys():
    #authorAndBook[authorPaar[i]] = tempAB.pop(i)
    tempAB[authorPaar[i]] = authorAndBook[i]
authorAndBook = tempAB

#print(authorAndBook)

for i in authorAndBook.keys():
    tempBook = []
    for j in authorAndBook[i]:
        tempBook.append(bookPaar[j])
        authorAndBook[i] = tempBook
        
for s,p,o in g:
    if "authorName" in str(p) and str(p) not in transPaar:
        transPaar[str(s)] = str(o)
    if "hasTranslated" in str(p):
        if str(s) not in transAndBook:
            transAndBook[str(s)] = []
        transAndBook[str(s)].append(str(o))

tempTB = {}
for i in transAndBook.keys():
    tempTB[transPaar[i]] = transAndBook[i]
transAndBook = tempTB

for i in transAndBook.keys():
    tempBook = []
    for j in transAndBook[i]:
        tempBook.append(bookPaar[j])
        transAndBook[i] = tempBook

def findTranslator(transAndBook, bookName):
    nameList = []
    for i in transAndBook.keys():
        if bookName in transAndBook[i]:
            nameList.append(i)
    return nameList

for i in authorAndBook.keys():
    print(i + "wrote:")
    for j in authorAndBook[i]:
        print("\t" + j)
        nameList = findTranslator(transAndBook, j)
        for k in range(len(nameList)):
            print("\t\t translated by: " + nameList[k])


# task 4 skip, falsch doc
#print(authorPaar)
# for s,p,o in g4:
#     print(authorPaar[str(s)])
    #authorAndLocation[authorPaar[str(s)]] = str(o)


# for i in authorAndBook.keys():
#     print(i + " wrote:")
#     for j in authorAndBook[i]:
#         print("  " + j)
#         for k in transAndBook.keys():
#             if j in transAndBook[k]:
#                 print("    translated by: " + k )
#     print()