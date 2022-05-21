import copy

class unrGraph:
    map = []
    mapT = [] 
    value = 0
    valutT = 0
    Reihenfolge = []    
    count = 0
    def __init__(self):
        print("Initialisieren...")
        
    def setValue(self,value):
        self.value = value
        self.valutT = value
        print("Es gibt ",self.value," mal Knoten")


    def setKante(self):
        print("Bitte geben Sie die Endknoten ein!(Jetzt gibt es ",self.value," mal Knten):")
        for i in range(self.value):
            print("Bitten geben Sie die Knote ein, die mit dem Node ",i+1," verbunden ist(1-",self.value,")")
            print(" 'x' bedeutet eingeben-fertig")
            self.map.append([i+1])
            while(1):
                kante = input()
                if kante =='x':
                    break;
                if kante != i+1:
                    self.map[i].append(int(kante))
        self.mapT = self.map
                

    def printGraph(self):
        print(self.map)
    
    def getGraph(self):
        return self.map

    def expa(self,v):

        map1 = self.mapT
        grad = []
        delIndex = []
        map2 = []
        for i in range(v):
            map2.append(map1[i][0])
        # print("Nr. ",self.count," mal Rekursiv")
        # print("map1 = ",map1)
        if v != 0:
            for i in range(v):
                grad.append([map1[i][0]])
            for i in range(v):
                grad[i].append(len(map1[i]) - 1)
            for i in range(v):
                if grad[i][1] == 0:
                    delIndex.append(i)
                    continue
                if grad[i][1] <= 2:
                    delIndex.append(i)
                    grad[i][1] = 0
                    for j in range(len(map1[i])-1):
                        index_y = map2.index(map1[i][j+1])
                        index_x = map1[index_y].index(map2[i])
                        if map2[i] == map1[index_y][index_x]:
                            del map1[index_y][index_x]
                            grad[index_y][1] = grad[index_y][1] - 1
                            continue
        s = []
        s = copy.deepcopy(delIndex)
        delIndex.sort(reverse = True)
        for i in range(len(s)):
            self.Reihenfolge.append(map2[s[i]])

        for i in delIndex:
            del map1[i]
        self.mapT = map1

        print("G' ist ",map1)
        
        expad = len(delIndex)
        koeexpa = 0
        for i in range(len(grad)):
            if int(grad[i][1]) <=2:
                koeexpa = koeexpa + 1
        self.count = self.count + 1
        if koeexpa > 0:
            self.valutT = self.valutT - expad
            grad.clear()
            delIndex.clear()
            self.expa(self.valutT)
        else:    
            self.count = 0
            print("Reihenfolge ist: ",self.Reihenfolge)
            
            if map1 == []:
                #print("G' ist ",map1)
                print("G ist 3-färbbar")
            else:
                print("G' ist ",map1)
                print("Weiß nicht")
#---------------------------------------------------------------
    def expa_3f(self,v):
    
        map1 = self.mapT
        grad = []
        delIndex = []
        map2 = []
        delk = []
        for i in range(v):
            map2.append(map1[i][0])
        # print("Nr. ",self.count," mal Rekursiv")
        # print("map1 = ",map1)
        if v != 0:
            for i in range(v):
                grad.append([map1[i][0]])
            for i in range(v):
                grad[i].append(len(map1[i]) - 1)
            # for i in range(v):
            #     if grad[i][1] == 0:
            #         delIndex.append(i)
            #         continue
            #     if grad[i][1] <= 2:
            #         delIndex.append(i)
            #         grad[i][1] = 0
            #         for j in range(len(map1[i])-1):
            #             index_y = map2.index(map1[i][j+1])
            #             index_x = map1[index_y].index(map2[i])
            #             if map2[i] == map1[index_y][index_x]:
            #                 del map1[index_y][index_x]
            #                 grad[index_y][1] = grad[index_y][1] - 1
            #                 continue
            for i in range(v):
                if grad[i][1] <= 2:
                    delk.append(grad[i][0])
            #print("grad = ",grad)
            #print("delk = ",delk)
            for i in range(v):
                if map1[i][0] in delk:
                    continue
                for j in range(len(delk)):
                    if delk[j] in map1[i]:
                        index_y = map1[i].index(delk[j])
                        del map1[i][index_y]

        # s = []
        # s = copy.deepcopy(delIndex)
        # delIndex.sort(reverse = True)
        # for i in range(len(s)):
        #     self.Reihenfolge.append(map2[s[i]])
        
        # for i in delIndex:
        #     del map1[i]
        #print("G' ist ",map1)
        #print("delk = ",delk)
        for i in range(len(delk)):
            # index_x = map2.index(delk[i])
            # print("index_x = ",index_x)
            # del map1[index_x]
            for j in range(len(map1)):
                if map1[j][0] == delk[i]:
                    del map1[j]
                    break
        
        
        #self.mapT = map1
        expad = len(delIndex)
        koeexpa = 0
        for i in range(len(grad)):
            if int(grad[i][1]) <=2:
                koeexpa = koeexpa + 1
        self.count = self.count + 1
        if koeexpa > 0:
            self.valutT = self.valutT - expad
            grad.clear()
            delIndex.clear()
            #self.expa(self.valutT)
        #else:    
        #self.count = 0
        #print("Reihenfolge ist: ",self.Reihenfolge)
            
        if map1 == []:
            #print("G' ist ",map1)
            print("G ist 3-färbbar")
            map1.clear()
            self.valutT = self.value
        else:
            print("G' ist ",map1)
            print("Weiß nicht")
    

        