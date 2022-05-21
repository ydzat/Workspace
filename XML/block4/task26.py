'''
Author: your name
Date: 2022-02-12 17:14:53
LastEditTime: 2022-02-12 18:03:54
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\XML\block4\task26.py
'''
import rdflib
import owlrl

graph = rdflib.Graph()
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpersonal.rdf")
graph.parse("C:\\Users\\ydzat\\OneDrive\\Workspace\\XML\\block4\\Schulpers.owl")
owlrl.DeductiveClosure(owlrl.OWLRL_Semantics).expand(graph)

per = rdflib.Namespace("http://example.org/personal/per#")

print("caretaker is a Teacher and/or a student and/or an Empoloyee and/or a Person")
# 找到所有的caretaker
for s in graph.subjects(rdflib.RDF.type,per.caretaker):
    mark = [0,0,0,0]
    workList = ["student","teacher","employee","person"]
    print("============")    
    # 打印当前caretaker的名字
    print(str.replace(str(s),str(per),""))
    # 对于当前的caretaker，根据名字找到其工作/身份
    for w in graph.objects(s, rdflib.RDF.type):
        work = str.replace(str(w),str(per),"")
        if work == "student":
            mark[0] = 1
        if work == "teacher":
            mark[1] = 1
        if work == "employee":
            mark[2] = 1
        if work == "person":
            mark[3] = 1
    # 根据找到的身份，打印相关信息
    for i in range(4):
        if mark[i] == 0:
            print("caretaker is no " + workList[i])
        if mark[i] == 1 and i == 2:
            print("caretaker is an " + workList[i])  
        if mark[i] == 1 and i != 2:
            print("caretaker is a " + workList[i]) 
