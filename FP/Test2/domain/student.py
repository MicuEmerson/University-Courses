'''
Created on Dec 19, 2016

@author: Emy
'''
from ctypes.test.test_pickling import name

class Student:
    
    def __init__(self, id, name, attendances, grade):
        self.id = id
        self.name = name
        self.attendances = attendances
        self.grade = grade
    
    def getID(self):
        return self.id
    
    def getName(self):
        return self.name
    
    def getAttendances(self):
        return self.attendances
    
    def getGrade(self):
        return self.grade
    
    def setID(self, ID):
        self.id = ID
        
    def setName(self):
        self.name = name
        
    def setAttendaces(self, attendance):
        self.attendances = attendance
    
    def setGrade(self, grade):
        self.grade = grade
        
    def __str__(self):
        return "ID: " + str(self.id) + ", Name: " + str(self.name) + ", Attendaces: " + str(self.attendances) + ", Grade:" + str(self.grade) 
        
    def isValid(self):
        
        status = True
        
        if self.grade > 10 or self.grade < 0:
            status = False
            
        myList = self.name.split(' ')
        
        if len(myList) != 2:
            status = False
        if len(myList[0]) < 3 or len(myList[1]) < 3:
            status = False
        
        return status
    
    def __lt__(self, entity):
        '''
            TODO
        '''
        return self.grade > entity.getGrade()
         
        
        
        
        
        
        
        
        
    
    
    
    
    
    
    
    
    
    
    
        
        
        