import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("Schulpersonal.rdf")
graph.parse("Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)
print("Brothers")
for s, o in graph.subject_objects(per.isRelative):
    print(o, "is relative of", s)
