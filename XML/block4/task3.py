'''
Author: your name
Date: 2022-01-18 07:58:51
LastEditTime: 2022-02-10 18:12:13
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task3.py
'''

import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()
trans = g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\translators.rdf")
aut = g2.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\books.rdf")
lit = g1.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf")

authorPaar = {}
authorAndBook = {}

for s,p,o in g:
    if "authorName" in str(p) and str(p) not in authorPaar:
        authorPaar[str(s)] = str(o)
    if "hasTranslated" in str(p):
        if str(s) not in authorAndBook:
            authorAndBook[str(s)] = []
        authorAndBook[str(s)].append(str(o))
