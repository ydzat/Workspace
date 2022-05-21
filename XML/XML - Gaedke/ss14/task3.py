'''
Author: your name
Date: 2022-02-13 20:19:33
LastEditTime: 2022-02-13 20:31:42
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\XML - Gaedke\ss14\task3a.py
'''


# 3a
"""
Prefix shop:<http://example.org/shop#>
Select distinct ?customer ?meal
From <Customers.rdf>
From <Meals.rdf>
Where{
    ?name shop:prefersMeal ?mealName
    ?name shop:customerName ?customer
    ?m shop:mealName ?meal
}

"""

# 3b
"""
Prefix shop:<http://example.org/shop#>
Select distinct ?meal
From <Customers.rdf>
From <Meals.rdf>
Where{
    ?mealName shop:nealName ?meal
    ?customer shop:prefersMeal ?mealName
    ?customer shop:customerName ?customerName
    Filer (regex(?customerName, "Customer2","i") || regex(?customerName, "Customer3","i"))
}
"""
