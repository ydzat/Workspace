import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("./rdfFiles/Schulpersonal.rdf")
graph.parse("./rdfFiles/Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)
print("Brothers")
for s, o in graph.subject_objects(per.isFather):
    if not (s == o):
        print(o, "is father of", s)
