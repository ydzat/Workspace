import os

class process:
    def __init__(self, name, arrivedTime, laufTime):
        self.name = name
        self.arrivedTime = arrivedTime
        self.laufTime = laufTime
        self.llf = laufTime
        self.lauf = -1
    def getName(self):
        return self.name
    def getArr(self):
        return int(self.arrivedTime)
    def getlaufTime(self):
        return int(self.laufTime)
    def leftlaufTime(self,lf):
        self.llf = self.laufTime - lf
    def getllf(self):
        return int(self.llf)
    def run1sec(self):
        self.llf = int(self.llf) - 1


class RR:
    def __init__(self, timeSlice , processlist):
        self.timeSlice = timeSlice
        self.processlist = processlist  
        self.wartenlist = []        #FIFO
        self.lauflist = []          #first elem, 仅存储当前运行的进程
        self.laufSeq = []           #存储整个运行运输
        self.totalLaufTime = 0
        self.lauf = -1
    def getProcess(self):
        return self.process
    def tLT(self):
        self.totalLaufTime = 0
        for i in processlist:
            self.totalLaufTime = self.totalLaufTime + i.getlaufTime()
    def getTLT(self):
        self.tLT()
        return self.totalLaufTime
    def getLaufSeq(self):
        return self.laufSeq
    def laufen(self):
        self.tLT()
        i = 0
        j = 0
        timePunkt = 0
        #for i in range (0,self.totalLaufTime+1, self.timeSlice):      #i is 1 time punkt !!!!! hier ist die Problem!!!!
        while (i < self.totalLaufTime+1):
            #抢占在此时发生，判断是否有新进程进入等待队列
            
            #obj = lambda x : x in self.processlist if (x.getArr() == i) == self.wartenlist.append(x) else 0
            
            # for x in self.processlist :
            #     if (x.getArr() == i):
            #         self.wartenlist.append(x)
            if(self.wartenlist != []):
                print("--------------------", self.wartenlist[0].getName())
            print("i = ",i)
            print("self.lauf = ",self.lauf)


            #在此处为一个时间片内，不发生抢占

            
            
            #时间片开始，判断是否有进程运行

            if self.lauf == -1 :        # -1 为没有运行的进程
                
                # 如果等待队列为空，判断此时是否有新进
                ###############################################
                if self.wartenlist == [] : 
                    for x in self.processlist :
                        if (x.getArr() == i):
                            self.wartenlist.append(x)
                            #若有新进，则
                            temp = self.wartenlist.pop(0)
                            self.lauflist.append(temp)      #此时已经放入lauflist
                            self.lauf = 1
                            
                            for j in range(i, i+int(self.timeSlice)):
                                
                                for x in self.processlist :
                                    if (x.getArr() == i):
                                        self.wartenlist.append(x)
                                print("89行，lauflist状态：",self.lauflist[0].getName())
                                #判断剩余时间是否为0
                                if self.lauflist[0].getllf() == 0:
                                    
                                    self.lauf = -1
                                    self.lauflist.clear()
                                    #break
                                else:
                                    self.laufSeq.append(self.lauflist[0])
                                    self.lauflist[0].run1sec()      #运行1次，进程的剩余时间-1
                            
                                i = j

                            ################################10086
                        else:
                            break
                ###############################################
                #否则，则将等待队列头部的元素放入lauflist
                else:
                    temp = self.wartenlist.pop(0)
                    self.lauflist.append(temp)      #此时已经放入lauflist
                    self.lauf = 1
                    
                    for j in range(i, i+int(self.timeSlice)):
                        
                        for x in self.processlist :
                            if (x.getArr() == i):
                                self.wartenlist.append(x)
                        print("89行，lauflist状态：",self.lauflist[0].getName())
                        #判断剩余时间是否为0
                        if self.lauflist[0].getllf() == 0:
                            
                            self.lauf = -1
                            self.lauflist.clear()
                            #break
                        else:
                            self.laufSeq.append(self.lauflist[0])
                            self.lauflist[0].run1sec()      #运行1次，进程的剩余时间-1
                       
                        i = j
                            
            else:       #若当前有正在运行的进程
                #判断当前进程剩余时间，若为0，则需考虑wartenlist
                if self.lauflist[0].getllf() == 0:
                    self.lauflist.clear()
                    #判断wartenlist中是否还有剩余进程
                    ###############################################
                    if self.wartenlist == [] : 
                        for x in self.processlist :
                            if (x.getArr() == i):
                                self.wartenlist.append(x)
                                #若有新进，则
                                temp = self.wartenlist.pop(0)
                                self.lauflist.append(temp)      #此时已经放入lauflist
                                self.lauf = 1
                                
                                for j in range(i, i+int(self.timeSlice)):
                                    
                                    for x in self.processlist :
                                        if (x.getArr() == i):
                                            self.wartenlist.append(x)
                                    print("89行，lauflist状态：",self.lauflist[0].getName())
                                    #判断剩余时间是否为0
                                    if self.lauflist[0].getllf() == 0:
                                        
                                        self.lauf = -1
                                        self.lauflist.clear()
                                        #break
                                    else:
                                        self.laufSeq.append(self.lauflist[0])
                                        self.lauflist[0].run1sec()      #运行1次，进程的剩余时间-1
                                
                                    i = j

                            ################################10086
                        else:
                            break
                    ###############################################
                    else:   #否则，则将等待队列头部的元素放入lauflist
                        temp = self.wartenlist.pop(0)
                        self.lauflist.append(temp)      #此时已经放入lauflist
                        self.lauf = 1
                        for j in range(i, i+int(self.timeSlice)):
                            for x in self.processlist :
                                if (x.getArr() == i):
                                    self.wartenlist.append(x)
                            #判断剩余时间是否为0
                            if self.lauflist[0].getllf() == 0:
                                
                                self.lauf = -1
                                self.lauflist.clear()
                                break
                            else:
                                self.laufSeq.append(self.lauflist[0])
                                self.lauflist[0].run1sec()      #运行1次，进程的剩余时间-1
                            i = j
                            print("j2 = ",j)
                else:   #当前进程仍有剩余时间
                    for j in range(i, i+int(self.timeSlice)):
                        for x in self.processlist :
                            if (x.getArr() == i):
                                self.wartenlist.append(x)
                        #判断剩余时间是否为0
                        if self.lauflist[0].getllf() == 0:
                            
                            self.lauf = -1
                            self.lauflist.clear()
                            break
                        else:
                            self.laufSeq.append(self.lauflist[0])
                            self.lauflist[0].run1sec()      #运行1次，进程的剩余时间-1
                        i = j
                        print("j3 = ",j)
            #print("--------------------i ",i)
            #print("j ",j)
            #i = j
            for obj in self.laufSeq:
                print("顺序：",obj.getName())



##########################################################################################
#                       main
##########################################################################################
#processlist = [process(1,0 ,68), process(2,0 ,53), process(3,0,24),process(4,0,8) ]

#rr01 = RR(1,processlist)

#print(rr01.getProcess()[0].getName())



timeSlice = input("time slice = ")
numOfProcess = input("how many process: ")
numOfProcess = int(numOfProcess)

processlist = []
name = []
arrTime = []
runtime = []

print("name arrived-time running-time:")

for i in range (0,numOfProcess):
    nameT, arrTimeT, runtimeT = input().split()
    name.append(nameT)
    arrTime.append(arrTimeT)
    runtime.append(runtimeT)

for i in range (0,numOfProcess):
    processlist.append(process(name[i],arrTime[i],runtime[i]))

rr01 = RR(timeSlice,processlist)

rr01.laufen()

for i in rr01.getLaufSeq():
    print("i --- ",i.getName())