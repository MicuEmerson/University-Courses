'''
Created on Dec 19, 2016

@author: Emy
'''

from domain.student import Student

class Repository:
    '''
         #TODO
    '''
    def __init__(self):
        self.objects = []
        self.fileName = "myData.txt"
        self.readFromFile()
        
    
    def readFromFile(self):
        '''
         #TODO
        '''
        try:
            f = open(self.fileName, "r")
        except IOError:
            return
        
        line = f.readline().strip()
        while line != "":
            
            param = line.split(",")
            entity = Student(param[0], param[1], int(param[2]), int(param[3]))
            self.add(entity)
            line = f.readline().strip()
            
        f.close() 
        
        
    def add(self, entity):
        '''
         We check if the entity have the unique ID and after we add it to list
         INPUT: entity = object of class Student
         OUPUT: True or False
        '''
        status = True
        
        for i in self.objects:
            if i.getID() == entity.getID():
                status = False
        
        if status == True:
            self.objects.append(entity)
            
        return status
        
    
    def addBonus(self, entity, b):
        '''
         We iterate to self.objects and when we find our entity we just add
         some bonus points(b) at his grade, if grade will be always <= 10
         INPUT: entity = object of student class
                b = bonus points
         OUPUT: -
        '''
        for i in self.objects:
            if i == entity:
                if entity.getGrade() + b > 10:
                    entity.setGrade(10)
                else:
                    entity.setGrade((entity.getGrade() + b))
        
        
    def getAll(self):
        return self.objects
    
    def __len__(self):
        return len(self.objects)
    
    
    
    
    
    
    
    
    
    
    
    
    
    