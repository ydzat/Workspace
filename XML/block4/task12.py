'''
Author: your name
Date: 2022-02-10 19:55:07
LastEditTime: 2022-02-10 19:59:10
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task12.py
'''
import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()
g3 = rdflib.Graph()
g1.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf")
g2.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\books.rdf")
g3.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\translators.rdf")

g1 = g1 + g2 + g3

qres = g1.query(
    """
        PREFIX rdf:<http://example.org/lit#>
        SELECT DISTINCT ?Translator WHERE{
            ?author rdf:hasTranslated ?book.
            ?author rdf:authorName ?Translator.
        }
    
    """
)

for row in qres:
    print(row[0])