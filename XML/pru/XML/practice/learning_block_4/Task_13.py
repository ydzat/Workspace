import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()
g3 = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")

g1.parse("./rdfFiles/books.rdf")
g3.parse("./rdfFiles/translators.rdf")
g += g1+g3
qres = g.query(
    """
        PREFIX lit: <http://example.org/lit#>
        SELECT DISTINCT ?name ?the_book_name ?translator 
        WHERE {
          ?authorW lit:hasWritten ?book ;
                  lit:authorName ?name .
          ?authorT lit:hasTranslated ?book ;
                  lit:authorName ?translator .
          ?book lit:bookName ?the_book_name .
        }
    """
)
for row in qres:
    print(row)
