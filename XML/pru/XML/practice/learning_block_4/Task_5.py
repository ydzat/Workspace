import rdflib

g = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")
qres = g.query(
    """
SELECT DISTINCT ?author WHERE {
  ?author <http://example.org/lit#hasWritten> ?object
}

    """
)
print("author")

for row in qres:
    print(row)

