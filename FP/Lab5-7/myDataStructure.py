'''
Created on Dec 29, 2016

@author: Emy
'''

class MyDataStructure:
  
    def __init__(self):
        self.myList = []
        
        
    def append(self, element):
        self.myList.append(element)
        
        
    def getAll(self):
        return self.myList
    
        
    def __getNextGap(self, gap):
        gap = gap*10/13
        if gap < 1:
            gap = 1
        return int(gap)
    
    
    def sort(self, condition):
        
        '''
           I use comb sort, the time complexity of this algorithm is: O(n^2 / 2^p) avegarage case
                                                                      O(n * log n) best case
                                                                      O(n^2)       worst case
           It is an in place sorting algorithm so O(1) for extra memory
           CombSort is a derivated BubbleSort, in BubbleSort the problem is that 
           the small elements from the end of the list slows down the algorithm, that is why 
           here, in CombSort we use that 'gap' to eliminated that small elements from the end
           of the list. The big elements from the beginning of the list are not a problem.
           
           Worst case is still O(n^2) like in BubblseSort
           
           Best case is O(n * log n) and in BubblseSort is O(n), because here, in CombSort
           we have that gap >= 1  which don't work so well if the list is almost sorted like in
           BubbleSort best case scenario.
           
           Average case is O(n^2 / 2^p) where p is the number of incremenets.  
        '''
        
        n = len(self.myList)
        gap = n
        swapped = True
        
        while gap != 1 or swapped != False:
            
            gap = self.__getNextGap(gap)
            swapped = False
            
            for i in range(0,n-gap):
                if self.myList[i] > self.myList[i+gap]:
                    self.myList[i], self.myList[i+gap] = self.myList[i+gap], self.myList[i]
                    swapped = True
        
        if condition:
            self.myList = list(reversed(self.myList))         
        
        
    def filter(self):
        
        myList2 = []
        for i in self.myList:
            if i not in myList2:
                myList2.append(i)
        
        return myList2
    
    
    def __setitem__(self, index, elem):
        self.myList[index] = elem
    
    def __delitem__(self, index):
        del self.myList[index]
        
    def __len__(self):
        return len(self.myList)
            
    def __next__(self):
    
        if self._iterPoz >= len(self.myList):
            raise StopIteration()
        
        rez = self.myList[self._iterPoz]
        self._iterPoz = self._iterPoz + 1
        return rez
    
    def __iter__(self):
        self._iterPoz = 0
        return self
    
    def getIndex(self, element):
        index = 0
        for i in  self.myList:
            if i == element:
                return index
            index += 1
  
  
def testMyDataStructure():
    myData = MyDataStructure()  
    myData.append(5)
    myData.append(3)
    myData.append(0)
    myData.append(7)
    myData.append(5)
    myData.append(1)
    assert len(myData) == 6
    assert len(myData.filter()) == 5
    
    
    
testMyDataStructure() 
'''
test = MyDataStructure()
#5 3 0 7 1 9 
test.add(5)
test.add(3)
test.add(0)
test.add(7)
test.add(5)
test.add(1)
test.add(5)
test.add(9)
print(test.getAll())
test.sort(0)
print(test.getAll())
test.sort(1)
print(test.getAll())


#del test[1]

test[1] = 100

print(test.getAll())
'''
    
    
    
    
    
    
    
    
    