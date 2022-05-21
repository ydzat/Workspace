import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
per = rdflib.Namespace("http://example.org/personal/per#")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)

print("Brother among employees")
for s in graph.subjects(rdflib.RDF.type,per.employee):
    for b in graph.objects(s,per.isBrother):
        #if (s != b) and b not in [ b1 for b1 in graph.subjects(b, per.student)]:
        print(str.replace(str(s),str(per),""), "is brother of", str.replace(str(b),str(per),""))