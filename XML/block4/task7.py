'''
Author: your name
Date: 2022-02-10 18:50:07
LastEditTime: 2022-02-10 19:07:14
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task6.py
'''
import rdflib

g = rdflib.Graph()
g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf").serialize(format='turtle')
qres = g.query(
    """

SELECT DISTINCT ?author ?object WHERE {
  ?author <http://example.org/lit#hasWritten> ?object.
}
    """
)
print("")

for row in qres:
    print(row[0] + " | " + row[1])

