'''
Created on Nov 26, 2016

@author: Emy
'''

from domain.Student import Student
from controller.undoController import FunctionCall, Operation
from myDataStructure import MyDataStructure

class GradesController:

    def __init__(self, studentRepository, disciplinesRepository, gradesRepository, undoController):
        '''
        Students = a repository with Student objects
        Disciplines = a repository with Discipline objects
        Grades = a repository with Grades objects
        '''
        self.__students = studentRepository
        self.__disciplines = disciplinesRepository
        self.__grades = gradesRepository
        self._undoController = undoController
        
    def store(self, entity):
        
        self.__grades.store(entity)
        redo = FunctionCall(self.store, entity) 
        undo = FunctionCall(self.delete, entity)
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation)
         
        
    def delete(self, entity):
        return self.__grades.delete(entity)
            
        
    def update(self, entity):
        return self.__grades.update(entity)
    
    def find(self, ID1, ID2):
        return self.__grades.find(ID1, ID2)
        
    def findByDisciplineID(self, ID):
        return self.__grades.findByDisciplineID()
    
    def deleteByStudent(self, ID):
        return self.__grades.deleteByStud()
    
    def deleteByDiscipline(self, ID):
        return self.__grades.deleteByDiscipline()
    
    def getAllStudentGrades(self, ID):
        return self.__grades.getAllStudentGrades()
    
    def getAll(self):
        return self.__grades.getAll()
    
    def __len__(self):
        return len(self.__grades)
    
    def __str__(self):
        return str(self.__grades)
    
    def compare1(self, a, b):
        return a > b 
    
    def compare2(self, a, b):
        return a < b
    
    def cmd16(self):
        '''
         Functionality: All students enrolled at a given discipline, sorted alphabetically or by descending order of average grade
         INPUT: -
         OUTPUT: a string with 
        '''
        nameDiscipline = input("Discipline Name: ")
        ID  = self.__disciplines.findByName2(nameDiscipline)
        myList  = self.__grades.findByDisciplineID(ID)
        myList2 = MyDataStructure()
        
        '''  Data transfer object ''' 
        for i in myList:
            myList2.append(Student(i, self.__students.find(i).getName()))
        
        ''' Unique list'''
        myList2 = myList2.filter()
        myList2.sort()
       
        return myList2
      
    
   
    def averageStudentDiscipline(self, ID_stud, ID_discipline):
        '''
        Functionality: Return the average of one student at one discipline
        INPUT: - ....
        OUTPUT: a floating number
        '''
        how_many = 0.0
        sum = 0.0
        
        for i in self.__grades.getAll():
            if i.getID_discipline() == ID_discipline and i.getID_student() == ID_stud:
                how_many += 1.0
                sum += i.getGrade()
                
                
        if(how_many == 0.0):
            return 0.0
        else:
            return float(sum / how_many)
                
    def cmd17(self):
        '''
        Functionality: All students failing at one or more disciplines
        INPUT: -
        OUTPUT: a list with persons that have a grade at one discipline lower then 5
        '''
        myList = MyDataStructure()
       
       
        '''  Data transfer object ''' 
        for i in self.__students.getAll():
            for j in self.__disciplines.getAll():
                if self.averageStudentDiscipline(i.getID(), j.getID()) < 5.0 and self.averageStudentDiscipline(i.getID(), j.getID()) != 0.0 :
                    myList.append( failedStudent(i, j, self.averageStudentDiscipline(i.getID(), j.getID()) ))
        
        myList = myList.filter()
                
        return myList
    
   
    def cmd18(self):
        '''
         Functionality: Students with the best school situation, sorted in descending order of their aggregated average
         INPUT: -
         OUTPUT: a list with students sorted in descendent order of their aggregated average
        '''
        
        myList = MyDataStructure()
        
        '''  Data transfer object '''
        for i in self.__students.getAll():
            res = 0.0
            cate = 0.0
            for j in self.__disciplines.getAll():
                sumDisci = self.averageStudentDiscipline(i.getID(), j.getID())
                if(sumDisci != 0.0):
                    res += sumDisci
                    cate += 1.0
            if cate != 0.0:
                myList.append(studentSituation(i, float(res/cate)))
            else:
                myList.append(studentSituation(i, 0.0))
                
                        
        myList.sort(1) 
        return myList
    
    
    def cmd19(self):
        '''
         Functionality: All disciplines at which there is at least one grade, sorted in descending order of the average grade received by all students enrolled at that discipline
         INPUT: -
         OUTPUT: a string with 
        '''
        myList = MyDataStructure()
        
        '''  Data transfer object '''
        for i in self.__disciplines.getAll():
            cate = 0.0
            res = 0.0
            for j in self.__grades.getAll():
                if i.getID() == j.getID_discipline():
                        res += j.getGrade()
                        cate += 1.0
                        
            if cate != 0.0:
                myList.append(disciplineAverage(i, float(res/cate)))
                  
        myList.sort(1)
        return myList 



'''Classes made for DTO'''
class failedStudent:
    def __init__(self, student, discipline, averageGrade):
        '''
        Students = an object Student
        Disciplines = an object Discipline
        averageGrade = the average of a given discipline of that student
        '''
        self.__student = student
        self.__discipline = discipline
        self.__averageGrade = averageGrade
        
            
    def __lt__(self, failedStud):
        """
        < operator required for sorting the list
        """
        return self.__student.getName() < failedStud.getName()
    
    def __str__(self):
        return str(self.__student) + " failed at " +  str(self.__discipline.getName()) + " with average grade: " + str(self.__averageGrade);
        
        
class studentSituation:
    def __init__(self, student, situation):
        '''
        Students = an object Student
        situation = average of averages of all disciplines
        '''
        self.__student = student
        self.__situation = situation
        
    def getSituation(self):
        return self.__situation
        
    def __lt__(self, studSituation):
        """
        < operator required for sorting the list
        """
        return self.__situation < studSituation.getSituation();
    
    def __str__(self):
        return str(self.__student) + " with aggregated average: " + str(self.__situation)
        
        
class disciplineAverage:
    def __init__(self, discipline, average):
        '''
        disicipline = an object Discipline
        average = average of averages of students at that discipline
        '''
        self.__discipline = discipline
        self.__average = average
        
    def getAverage(self):
        return self.__average
        
    def __lt__(self, disci):
        """
        < operator required for sorting the list
        """
        return self.__average < disci.getAverage();
    
    def __str__(self):
        return str(self.__discipline) + " have average grade: " + str(self.__average)
        
        
        
        
        
        
        
        
        
        
        
        
    
    
     
 