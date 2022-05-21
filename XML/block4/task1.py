'''
Author: your name
Date: 2022-01-18 07:29:52
LastEditTime: 2022-02-10 16:36:53
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task1.py
'''


import rdflib

g1 = rdflib.Graph()

#g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Litera.rdf")
g=g1.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf").serialize(format='xml')
#g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\books.rdf")
print(g)

# for subj, pred, obj in g:
#     if(subj, pred, obj) not in g:
#         raise Exception("It better be!")

# print("graph has {} statements.".format(len(g)))

# print(g.serialize(format="turtle"))