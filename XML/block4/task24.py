'''
Author: your name
Date: 2022-02-12 17:01:52
LastEditTime: 2022-02-12 17:05:27
LastEditors: your name
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task24.py
'''
import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)

print("Brother among Teachers, and not a strudent")
for s in graph.subjects(rdflib.RDF.type,per.teacher):
    for b in graph.objects(s,per.isBrother):
        if (s != b) and b not in [ b1 for b1 in graph.subjects(b, per.student)]:
            print(s, "is brother of", b)