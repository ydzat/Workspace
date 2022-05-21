import rdflib

g = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")
g1 = rdflib.Graph()
g1.parse("./rdfFiles/books.rdf")
g += g1
qres = g.query(
    """
        PREFIX rdf: <http://example.org/lit#>
        SELECT DISTINCT ?name ?the_book_name
        WHERE {
          ?author rdf:authorName ?name .
          ?author rdf:hasWritten ?book .
          ?book rdf:bookName ?the_book_name 

        }
    """
)
for row in qres:
    print(row)
