import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("./rdfFiles/Schulpersonal.rdf")
graph.parse("./rdfFiles/Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)
count = 0
for student in graph.subjects(rdflib.RDF.type, per.student):
    for brother in graph.objects(student, per.isBrother):
        if not (student == brother):
            count += 1
            print("student ", str(student), "has brother", str(brother))

if count == 0:
    print("There are no brothers among students")
