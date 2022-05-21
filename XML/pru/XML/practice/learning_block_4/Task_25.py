import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("./rdfFiles/Schulpersonal.rdf")
graph.parse("./rdfFiles/Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)
count = 0
for employee in graph.subjects(rdflib.RDF.type, per.employee):
    for brother in graph.objects(employee, per.isBrother):
        if not (employee == brother):
            count += 1
            print("teacher ", str(employee), "has brother", str(brother))
if count == 0:
    print("There are no brothers among employees")
