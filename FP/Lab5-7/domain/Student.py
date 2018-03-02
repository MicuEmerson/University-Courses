'''
Created on Nov 24, 2016

@author: Emy
'''

class Student:
    
    def __init__(self, studentID, name):
        
        self.__studentID = studentID
        self.__name = name

    def getID(self):
        return self.__studentID


    def getName(self):
        return self.__name


    def setName(self, value):
        self.__name = value

    
    def __eq__(self, entity):
        '''
        Tells when 2 objects are equal
        input: entity
        output: True or False
        '''
        if isinstance(entity, Student) == False:
            return False;
        return self.__studentID == entity.getID() and self.__name == entity.getName()
    
    def __str__(self):
        '''
        How the activity will be printed
        input: -
        output: -
        '''
        return "Student ID: " + str(self.__studentID) + ", Name: " + str(self.__name)
    
    
    def __lt__(self, entity):
        """
        < operator required for sorting the list
        """
        return self.getName() < entity.getName()
    
    studentID = property(getID, None, None, None)
    name = property(getName, setName, None, None)
    
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    