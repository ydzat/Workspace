import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")

g1.parse("./rdfFiles/books.rdf")
g2.parse("./rdfFiles/locations.rdf")
g += g1 + g2
qres = g.query(
    """
        SELECT DISTINCT ?name ?book_name
        WHERE {
          ?author <http://example.org/lit#authorName> ?name .
          ?author <http://example.org/lit#hasWritten> ?book .
          ?book <http://example.org/lit#bookName> ?book_name .
          ?author <http://example.org/lit#livesIn> ?location .
          FILTER ((contains(?book_name,"About"))|| ?location="Magdeburg")
        }
    """
)
for row in qres:
    print(row)
