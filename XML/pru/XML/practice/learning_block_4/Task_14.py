import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()
g3 = rdflib.Graph()
g.parse("authors.rdf")

g1.parse("books.rdf")
g2.parse("locations.rdf")
g3.parse("translators.rdf")
g += g1+g2+g3
qres = g.query(
    """
        PREFIX lit: <http://example.org/lit#>
        SELECT ?name ?the_book_name ?translator_name ?author_city ?translator_city
        WHERE {
           ?author lit:authorName ?name.
           ?author lit:hasWritten ?book.
           ?author lit:livesIn ?author_city.
           ?book lit:bookName ?the_book_name.
           ?translator lit:hasTranslated ?book.
           ?translator lit:livesIn ?translator_city.
           ?translator lit:authorName ?translator_name.
        }
    """
)
for row in qres:
    print(row)
