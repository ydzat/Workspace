import xml.sax as xs
import xml.sax.handler as xsh
import numpy as np

class personen():
    nameList = []
    firstNameList = []
    familyNameList = []
    assessmentList = []
    def setFirstName(self, t_name):
        personen.firstNameList.append(t_name)
    def setFamilyName(self, t_name):
        personen.familyNameList.append(t_name)
        personen.nameList.append(personen.firstNameList[-1] + " " + personen.familyNameList[-1])
    def setAssessment(self, t_assessment):
        personen.assessmentList.append(t_assessment)
    def getBestStudent(self):
        idxList = [idx for idx,x in enumerate(personen.assessmentList) if x == min(personen.assessmentList)]
        print("The student with the best score is: ")
        for idx in idxList:
            print("\t" + personen.nameList[idx])
    def getAvg(self):
        t_asse = []
        for i in personen.assessmentList:
            t_asse.append(int(i))
        print("The average score is: %d" % round(np.mean(t_asse)))
        
class MySaxHandler(xsh.ContentHandler):
    p = personen()

    def __init__(self):
        self.CurrentData = ""
        self.firstName = ""
        self.familyName = ""
        self.assessment = ""

    def startElement(self, tag ,attrs):
        self.CurrentData = tag
        
    def endElement(self, tag):
        sC = self.CurrentData
        if sC == "firstName":
            MySaxHandler.p.setFirstName(self.firstName)
        elif sC == "familyName":
            MySaxHandler.p.setFamilyName(self.familyName)
        elif sC == "assessment":
            MySaxHandler.p.setAssessment(self.assessment)
        
        self.CurrentData = ""

    def characters(self, content):
        sC = self.CurrentData

        if sC == "person":
            self.person = content
        
        elif sC == "firstName":
            self.firstName = content
        elif sC == "familyName":
            self.familyName = content
        elif sC == "assessment":
            self.assessment = content
        
    def printRes(self):
        MySaxHandler.p.getBestStudent()
        MySaxHandler.p.getAvg()

parser = xs.make_parser()
parser.setFeature(xsh.feature_namespaces, 0)

Handler = MySaxHandler()
parser.setContentHandler(Handler)

parser.parse("liveTask1.xml")

Handler.printRes()