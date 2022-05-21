'''
Author: your name
Date: 2022-02-10 18:50:07
LastEditTime: 2022-02-10 19:31:21
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task6.py
'''
import rdflib

g1 = rdflib.Graph()
g2 = rdflib.Graph()
g1.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf").serialize(format='turtle')
g2.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\books.rdf").serialize(format='turtle')

g1 += g2
qres1 = g1.query(
    """
PREFIX rdf: <http://example.org/lit#>
SELECT DISTINCT ?name ?the_book_name WHERE {
  ?author rdf:authorName ?name.
  ?author rdf:hasWritten ?book.
  ?book rdf:bookName ?the_book_name.
    FILTER regex(?the_book_name, "about", "i")
}
    """
)

for row in qres1:
    print(row[0] + " |" + row[1])
