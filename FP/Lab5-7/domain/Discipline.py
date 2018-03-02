'''
Created on Nov 25, 2016

@author: Emy
'''

class Discipline:
    
    def __init__(self, disciplineID, name):
        '''
        Constructor
        '''
        self.__disciplineID = disciplineID
        self.__name = name

    def getID(self):
        return self.__disciplineID


    def getName(self):
        return self.__name


    def setID(self, value):
        self.__disciplineID = value
        
    def __eq__(self, entity):
        '''
        Tells when 2 objects are equal
        input: entity
        output: True or False
        '''
        if isinstance(entity, Discipline) == False:
            return False;
        return self.__disciplineID == entity.getID() and self.__name == entity.getName()
    
    def __str__(self):
        '''
        How the activity will be printed
        input: -
        output: -
        '''
        return "Discipline ID: " + str(self.__disciplineID) + ", Name: " + str(self.__name)
    
     
        

    
    
    
    
    
    