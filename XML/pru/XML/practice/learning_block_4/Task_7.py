import rdflib

g = rdflib.Graph()
g.parse("authors.rdf")
g1= rdflib.Graph()
g1.parse("./rdfFiles/books.rdf")
g+=g1
qres = g.query(
    """
        SELECT ?author ?book 
        WHERE {
            ?author <http://example.org/lit#hasWritten> ?book 
        }
    """
)

for row in qres:
    print(row)

