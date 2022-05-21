import rdflib

g = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")
qres = g.query(
    """
        SELECT DISTINCT ?author_name 
        WHERE {
            ?subject <http://example.org/lit#authorName> ?author_name
        }

    """
)


for row in qres:
    print(row)
