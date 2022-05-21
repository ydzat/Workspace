'''
Author: your name
Date: 2022-02-10 20:14:03
LastEditTime: 2022-02-10 20:24:19
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task16.py
'''
import rdflib
g = rdflib.Graph()
g.parse("https://dbpedia.org/sparql")

qres = g.query(
    """
        PREFIX dbp:<http://dbpedia.org/resource>
        SELECT DISTINCT ?who WHERE{
            ?who [] dbp:Dresden.
            
        }
    """
)

for row in qres:
    print(row)