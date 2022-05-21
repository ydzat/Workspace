import rdflib

g = rdflib.Graph()
g1 = rdflib.Graph()
g2 = rdflib.Graph()
g3 = rdflib.Graph()
g.parse("./rdfFiles/authors.rdf")
g3.parse("./rdfFiles/translators.rdf")
g += g3
qres = g.query(
    """
        PREFIX lit: <http://example.org/lit#>
        SELECT DISTINCT ?Translator
        WHERE {
            ?translator lit:authorName ?Translator.
            ?translator lit:hasTranslated ?the_book_name.
        }
    """
)
for row in qres:
    print(row)
