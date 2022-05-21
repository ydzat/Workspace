'''
Author: your name
Date: 2022-01-18 08:25:55
LastEditTime: 2022-01-18 08:44:20
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\liveTask3.py
'''
import rdflib
import owl

g = rdflib.Graph()
g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(g)

per = rdflib.Namespace("http://example.org/personal/per#")


# for teacher, student in g.subject_objects(rdflib.URIRef("http://example.org/personal/per#teaches")):
#   print(teacher, student)


for caretaker in g.subjects(rdflib.RDF.type, per.caretaker):
    for relative in g.subjects(per.isRelative, caretaker):
        for teacher in g.subjects(per.teacher, caretaker):
            print(f"{teacher} teaches {relative} who is related to {caretaker}")


# SPARQL

qres = g.query("""
    PREFIX ...
    SELECT ?teacher ?relative ?caretaker
    WHERE {...}

""")
for teacher, relative, caretaker in qres:
    print(f"{teacher} teaches {relative} who is related to {caretaker}")