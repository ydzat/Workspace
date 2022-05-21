"""
Write a Python program using the RDFlib package, which reads the information about the authors and displays it
in RDF format. The module can be imported as usual using import rdflib, the RDF files are also available with their
respective filenames. A possible output could look like this (shortened):

<rdf:RDF
    xmlns:lit="https://example.org/lit#"
    xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#" >
    <lit:authorName>John Lorge</lit:authorName>
  <rdf:Description rdf:about="https://example.org/lit#author0">
    <lit:hasWritten rdf:resource="https://example.org/lit#book12"/>
    <lit:hasWritten rdf:resource="https://example.org/lit#book3"/>
    <lit:hasWritten rdf:resource="https://example.org/lit#book0"/>
   (...)

直接输出rdf文件中的内容
1. 创建Graph对象
2. 使用parse对rdf文档进行转换
3. 对转换后的对象进行序列化

"""

from rdflib import Graph

g1 = Graph()
g = g1.parse('./rdfFiles/authors.rdf').serialize(format='xml')
print(g)
