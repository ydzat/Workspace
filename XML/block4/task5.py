import rdflib

g = rdflib.Graph()
g.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\authors.rdf")
qres = g.query(
    """
SELECT DISTINCT ?author WHERE {
  ?author <http://example.org/lit#hasWritten> ?object
}

    """
)
print("author")

for row in qres:
    print(row[0])

