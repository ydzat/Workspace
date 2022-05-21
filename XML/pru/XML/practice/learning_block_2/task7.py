import xml.sax
import xml.sax.handler

firstNameList=[]
familyNameList=[]
assessmentList=[]

class StudentsHandler(xml.sax.ContentHandler):
  def __init__(self):
    self.CurrentData = ""
    self.firstName = ""
    self.familyName = ""
    self.assessment = ""

  def startElement(self, tag, attributes):
    self.CurrentData = tag

  def characters(self, content):
    if self.CurrentData == "firstName":
      self.firstName = content
    elif self.CurrentData == "familyName":
      self.familyName = content
    elif self.CurrentData == "assessment":
      self.assessment = content

  def endElement(self, tag):
    if self.CurrentData == "firstName":
      firstNameList.append(self.firstName)
    elif self.CurrentData == "familyName":
      familyNameList.append(self.familyName)
    elif self.CurrentData == "assessment":
      assessmentList.append(self.assessment)
    self.CurrentData=""  # Why do we need this one?

if( __name__ == "__main__"):
  parser = xml.sax.make_parser()
  parser.setFeature(xml.sax.handler.feature_namespaces, 0)

  Handler = StudentsHandler()
  parser.setContentHandler(Handler)

  parser.parse("task7data.xml")

  # get the max score
  ids = []
  totalScore = 0
  count = 0
  maxcore = min(assessmentList)
  # get the index of max core
  ids = [i for i,x in enumerate(assessmentList) if x == maxcore]
  for score in assessmentList:
    totalScore += int(score)
    count += 1
  
  bestnames = []
  for id in ids:
    fullname = firstNameList[id]+" "+familyNameList[id]
    bestnames.append(fullname)
  for name in bestnames:
    print("The student with the best score is: ", name)

  meanscore = totalScore/count
  print("The average score is: ", round(meanscore, 1))
