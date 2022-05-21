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
        SELECT  ?Author ?written_book_name ?translated_book_name 
        WHERE {
          ?author lit:authorName ?Author
          {
            ?author lit:hasWritten ?book .
            ?book lit:bookName ?written_book_name .
          }
          UNION
          {
            ?author lit:hasTranslated ?book .
            ?book lit:bookName ?translated_book_name .
          }
        }
    """
)
for row in qres:
    print(row)
