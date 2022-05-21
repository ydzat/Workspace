'''
Author: your name
Date: 2022-02-13 21:08:43
LastEditTime: 2022-02-13 21:16:30
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\XML - Gaedke\PrÜfung XML SS 2013\Aufgabe 4\task4.py
'''



# 4a
"""
PREFIX rdf:<http://www.w3.org/1999/02/22-rdf-syntax-ns#>
PREFIX sup:<http://example.org/sup#>

Select distinct ?producer ?produkte
From <Producers.rdf>
From <Products.rdf>
Where{
    ?productNr sup:productName ?produkte
    ?producerNr sup:hasProduced ?productNr
    ?producerNr sup:producerName ?producer
}

"""

# 4b
"""
PREFIX rdf:<http://www.w3.org/1999/02/22-rdf-syntax-ns#>
PREFIX sup:<http://example.org/sup#>

Select distinct ?produkte
From <Producers.rdf>
From <Products.rdf>
Where{
    ?productNr sup:productName ?produkte
    ?producerNr sup:hasProduced ?productNr
    ?producerNr sup:producerName ?producer
    Filter (regex (?producer, "producer2","i") || regex(?producer, "producer3","i"))
}
"""