'''
Author: your name
Date: 2022-01-18 08:07:51
LastEditTime: 2022-01-18 08:12:52
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task18.py
'''
# DBPedia is a publicly available RDF graph containing information generated 
# from Wikipedia information. A public SPARQL endpoint can be found 
# at https://dbpedia.org/sparql, which may be used for next few tasks.

# If you wish to run DBPedia queries from a local Python script, 
# you need to adjust the endpoint address accordingly.

select distinct ?name where {dbr:Dresden }