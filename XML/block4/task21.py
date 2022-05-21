import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)

print("isChild")
for s, o in graph.subject_objects(per.isChild):
    if not (s == o):
        print(s, "is isChild of", o)