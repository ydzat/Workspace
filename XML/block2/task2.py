'''
Author: your name
Date: 2021-12-05 14:07:40
LastEditTime: 2022-02-12 02:47:56
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block2\task1.py
'''
from glob import glob
import xml.sax
import copy

class Deliveries( xml.sax.ContentHandler ):
    def __init__(self):
        self.current = ""       #当前访问标签
        self.articleNode = {}   #存储一整个article的数据，形如{"id":"7789", "name":"pineapple", "price":"8.60", "supplier":"Richard Inc."}
        self.list = []          #存储所有的article。形如[ {articleNode1的内容}, {articleNode2的内容}...  ]
    def startElement(self, tag, attrs):
        self.current = tag
        if self.current == "article":   #以一个article为基础单位。
            self.articleNode["id"] = attrs["id"]    #记录基础单位的属性
            
    def characters(self, content):
        # 在访问基础单位内部的子元素时，记录所需的子元素数据。
        if self.current == "name":
            self.articleNode["name"] = content
        if self.current == "price":
            self.articleNode["price"] = content
        if self.current == "supplier":
            self.articleNode["supplier"] = content
    def endElement(self,tag):
        # 在访问到关闭标签时，意味着整个articleNode已经记录完成，将其深拷贝至temp，然后将temp存入list中。
        if tag == "article":
            temp = copy.deepcopy(self.articleNode)
            self.list.append(temp)
        self.current = ""   # 归零

if(__name__ == "__main__"):

    # 照抄即可↓↓↓↓
    parser = xml.sax.make_parser()
    parser.setFeature(xml.sax.handler.feature_namespaces, 0)

    Handler = Deliveries()
    parser.setContentHandler( Handler )

    parser.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block2\\deliveries.xml")
    # 照抄即可↑↑↑↑ 注：上面这个parse()中的地址，直接写deliveries.xml就好。
    
    # 接下来对获取的数据进行处理，我们已经获取了所需的id/name/price/supplier，并存放在list中，
    # 这些数据在期望的html文件中所在的位置是<table>部分，那么就将其装入。并存为String格式，放在trString中。
    trString = ""
    for i in Handler.list:
        for j in range(4):
            if j == 0:
                trString = trString + "\t\t<tr><td>" + i["id"] + "</td>"
            if j == 1:
                trString = trString + "<td>" + i["name"] + "</td>"
            if j == 2:
                trString = trString + "<td>" + i["price"] + "</td>"
            if j == 3:
                trString = trString + "<td>" + i["supplier"] + "</td></tr>\n"
    
    #然后把其他部分写上去，中间用加号连接就ok啦
    html = """
<html><head><title>Deliveries</title></head>
    <body>
        <h1>Deliveries</h1><hr>

        <table border="1">
            <tr><th>Number</th><th>Article</th><th>Price</th><th>Supplier</th></tr>
            """ + trString + """
        </table>
    </body>
</html>
    """
    print(html)


################# 这后面的不用看 #########################
# 未能实现版本，想用class包装每一个html标签。这后面的不用看

# class html(object):
#     htmlLab = []
#     htmlS = ""
#     def __init__(self):
#         self.htmlLab.append("<html>")
#         self.htmlLab.append("")
#         self.htmlLab.append("</html>\n")
#     def getHtmlLab(self):
#         return self.htmlLab
#     def getHtmlS(self):
#         return "".join(self.htmlLab)

# class title(object):
#     titleLab = []
#     titleS = ""
#     def __init__(self):
#         self.titleLab.append("<title>")
#         self.titleLab.append("")
#         self.titleLab.append("</title>")
#     def getTitleLab(self):
#         return self.titleLab
#     def getTitleS(self):
#         return "".join(self.titleLab)

# class head(object):
#     headLab = []
#     headS = ""
#     def __init__(self):
#         self.headLab.append("<head>")
#         self.headLab.append("")
#         self.headLab.append("</head>")
#     def getHeadLab(self):
#         return self.headLab
#     def getHeadS(self):
#         return "".join(self.headLab)

# class body(object):
#     bodyLab = []
#     bodyS = ""
#     def __init__(self):
#         self.bodyLab.append("<body>")
#         self.bodyLab.append("")
#         self.bodyLab.append("</body>")
#     def getBodyLab(self):
#         return self.bodyLab
#     def getBodyS(self):
#         return "".join(self.bodyLab)

# class h1(object):
#     h1Lab = []
#     h1S = ""
#     def __init__(self):
#         self.h1Lab.append("<h1>")
#         self.h1Lab.append("")
#         self.h1Lab.append("</h1>")
#     def getH1Lab(self):
#         return self.h1Lab
#     def getH1S(self):
#         return "".join(self.h1Lab)

# class hr(object):
#     hrLab = "<hr>\n"
#     def getH1Lab(self):
#         return self.hrLab

# class table(object):
#     tableLab = []
#     tableS = ""
#     def __init__(self):
#         self.tableLab.append("<table border=\"1\">")
#         self.tableLab.append("")
#         self.tableLab.append("</table>\n")
#     def getH1Lab(self):
#         return self.h1Lab
#     def getTableS(self):
#         return "".join(self.tableLab)

# class tr(object):
#     trLab = []
#     trS = ""
#     def __init__(self):
#         self.trLab.append("<tr>")
#         self.trLab.append("")
#         self.trLab.append("</tr>\n")
#     def getTrLab(self):
#         return self.trLab
#     def getTrS(self):
#         return "".join(self.trLab)

# class td(object):
#     tdLab = []
#     tdS = ""
#     def __init__(self):
#         self.tdLab.append("<td>")
#         self.tdLab.append("")
#         self.tdLab.append("</td>\n")
#     def getTdLab(self):
#         return self.tdLab
#     def getTdS(self):
#         return "".join(self.tdLab)

# th = "<tr><th>Number</th><th>Article</th><th>Price</th><th>Supplier</th></tr>"

# html1 = html()
# head1 = head()
# title1 = title()
# body1 = body()
# h11 = h1()
# hr1 = hr()
# table1 = table()

# title1.titleLab[1] = "Deliveries"
# head1.headLab[1] = title1.getTitleS()
# h11.h1Lab[1] = "Deliveries"

# length = len(Handler.list)

# # trList = [tr() for i in range(length)]

# trList = []
# for i in range(length):
#     trList.append(tr())

# #tdList = [td() for i in range(4)]
# tdList = []
# for i in range(4):
#     tdList.append(td())

# print(tdList[0])

# for i in range(length):
#     for j in range(4):
#         if j == 0:
#             tdList[j].tdLab[1] = Handler.list[i]["id"]
#         if j == 1:
#             tdList[j].tdLab[1] = Handler.list[i]["name"]
#         if j == 2:
#             tdList[j].tdLab[1] = Handler.list[i]["price"]
#         if j == 3:
#             tdList[j].tdLab[1] = Handler.list[i]["supplier"]
#         tdList[j].getTdS()
#         if j == 3:
#             print(tdList[j].getTdS())
            
#             trList[i].trLab[1] = "".join(tdList)

# trString = ""
# for i in range(length):
#     trString += trList[i].getTrS

# table1.tableLab[1] = th + trString

# body1.bodyLab[1] = h11.getH1S() + hr1.getH1Lab + table1.getTableS()

# html1.htmlLab[1] = head1.getHeadS() + body1.getBodyS()

# print(html1.getHtmlS())