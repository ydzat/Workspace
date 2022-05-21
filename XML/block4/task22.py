'''
Author: your name
Date: 2022-02-12 16:38:31
LastEditTime: 2022-02-12 16:39:58
LastEditors: your name
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task22.py
'''
import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)

print("Relative")
for s, o in graph.subject_objects(per.isRelative):
    if not (s == o):
        print(s, "is Relative of", o)