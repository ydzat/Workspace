import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("./rdfFiles/Schulpersonal.rdf")
graph.parse("./rdfFiles/Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)
count = 0
for teacher in graph.subjects(rdflib.RDF.type, per.teacher):
    for brother in graph.objects(teacher, per.isBrother):
        if not (teacher == brother):
            count += 1
            print("teacher ", str(teacher), "has brother", str(brother))

if count == 0:
    print("There are no brothers among teachers")
