'''
Created on Nov 24, 2016

@author: Emy
'''

class Grades:

    def __init__(self, disciplineID, studentID, gradeValue):

        self.__disciplineID = disciplineID
        self.__studentID = studentID
        self.__gradeValue = gradeValue

    def getID_discipline(self):
        return self.__disciplineID
    
    def getID_student(self):
        return self.__studentID
    
    def getGrade(self):
        return self.__gradeValue
    
    def setGrade(self, value):
        self.__gradeValue = value
        
    def __eq__(self, entity):
        '''
        Tells when 2 objects are equal
        input: entity
        output: True or False
        '''
        if isinstance(entity, Grades) == False:
            return False;
        return self.__disciplineID == entity.getID_discipline() and self.__studentID == entity.getID_student()  and self.__gradeValue == entity.getGrade()    
    
    def __str__(self):
        '''
        How the activity will be printed
        input: -
        output: -
        '''
        return "Discipline ID: " + str(self.__disciplineID) + ", Student ID: " + str(self.__studentID) + ", Grade Value: " + str(self.__gradeValue)



