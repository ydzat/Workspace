'''
Author: your name
Date: 2022-02-12 16:41:25
LastEditTime: 2022-02-12 17:06:30
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task23.py
'''
import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)

print("Brother among Student, and not a teacher")
for s in graph.subjects(rdflib.RDF.type,per.student):
    for b in graph.objects(s,per.isBrother):
        if (s != b) and b not in [ b1 for b1 in graph.subjects(b, per.teacher)]:
            print(s, "is brother of", b)