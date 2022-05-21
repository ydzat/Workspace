import rdflib

g = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")
g1 = rdflib.Graph()
g1.parse("./rdfFiles/books.rdf")
g += g1
qres = g.query(
    """
        PREFIX lit:<http://example.org/lit#>
        SELECT ?name ?the_book_name
        WHERE {
          ?author lit:hasWritten ?book .
          ?author lit:authorName ?name .
          ?book lit:bookName ?the_book_name .
          FILTER regex(?the_book_name, "about", "i")
        }
    """
)
for row in qres:
    print(row)
