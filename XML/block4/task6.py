'''
Author: your name
Date: 2022-02-10 18:50:07
LastEditTime: 2022-02-10 18:52:32
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task6.py
'''
import rdflib

g = rdflib.Graph()
g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf")
qres = g.query(
    """
SELECT DISTINCT ?object WHERE {
  ?author <http://example.org/lit#authorName> ?object
}

    """
)
print("author_name")

for row in qres:
    print(row[0])

