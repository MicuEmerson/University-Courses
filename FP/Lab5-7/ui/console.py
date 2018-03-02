'''
Created on Nov 25, 2016

@author: Emy
'''
from domain.Student import Student
from domain.Discipline import Discipline
from domain.Grades import Grades
from controller.Statistics import Statistics


class UI:
    
    def __init__(self, studentController, disciplineController, gradesController, undoController):
        self.__students = studentController
        self.__disciplines = disciplineController
        self.__grades = gradesController
        self.__undoController = undoController
    
    def __getNumber(self):
        '''
        Functionality: 
        INPUT: -
        OUTPUT: an integer number
        '''
        while True:
            try:
                x = int(input("Number: "))
                break
            except ValueError:
                print("Please enter a number!")
        return x
        
    def __readStudent(self):
        '''
        Functionality: Try to read a Student object parameters, if fail print invalid input 
        INPUT: - 
        OUTPUT: an object Student
        '''
        print("Please insert the student ID:")
        ID = self.__getNumber()
        name = input("Student name: ")
    
        return Student(ID, name)
         
            
    def __readDiscipline(self):
        '''
        Functionality: Try to read a Discipline object parameters, if fail print invalid input 
        INPUT: -
        OUTPUT: an object Discipline
        '''
        print("Please insert the discipline ID:")
        ID = self.__getNumber()
        name = input("Discipline Name: ")
        
        return Discipline(ID, name)
        
            
    def __readGrade(self):
        '''
        Functionality: Try to read a Grade object parameters, if fail print invalid input 
        INPUT: -
        OUTPUT: an object Grades
        '''
        print("Please insert the discipline ID:")
        ID_discipline = self.__getNumber()
        print("Please insert the student ID:")
        ID_student = self.__getNumber()
        print("Please insert the grade value:")
        grade_value = self.__getNumber()
      
        return Grades(ID_discipline, ID_student, grade_value)
        
        
    
    def __printMenu(self):
        
        string = "\tMenu"
        string += "\n1.  Print Menu"
        string += "\n2.  Add a new student"
        string += "\n3.  Add a new discipline"
        string += "\n4.  Add a grade"
        string += "\n5.  Remove a student"
        string += "\n6.  Remove a discipline"
        string += "\n7.  Update a student"
        string += "\n8.  Update a discipline"
        string += "\n9.  List students"
        string += "\n10. List disciplines"
        string += "\n11. List Students + Grades at each Discipline"
        string += "\n12. Search discipline by ID"
        string += "\n13. Search student by ID"
        string += "\n14. Search discipline by name"
        string += "\n15. Search student by name"
        string += "\n16  All students enrolled at a given discipline, sorted alphabetically or by descending order of average grade"
        string += "\n17. All students failing at one or more disciplines"
        string += "\n18. Students with the best school situation, sorted in descending order of their aggregated average"
        string += "\n19. All disciplines at which there is at least one grade, sorted in descending order of the average grade received by all students enrolled at that discipline"
        string += "\n20. Undo"
        string += "\n21. Redo"
        string += "\n0.  Exit."
        print(string)

    def run(self):
     
        self.__printMenu()
        
        while True:
           
            try:
               
                cmd = int(input("Command: "))
                while cmd < 0 or cmd > 21:
                    cmd = int(input("Please enter a number between 0-21!"))
                    
                if cmd == 1:
                    
                    self.__printMenu()
                     
                elif cmd == 2:
                    
                    self.__undoController.newOperation()
                    if not self.__students.store(self.__readStudent()):
                        self.__undoController._index -= 1
                        
                elif cmd == 3:
                    
                    self.__undoController.newOperation()
                    if not self.__disciplines.store(self.__readDiscipline()):
                        self.__undoController._index -= 1
                
                elif cmd == 4:
                    
                    self.__undoController.newOperation()
                    self.__grades.store(self.__readGrade())
              
                
                elif cmd == 5:
                    
                    ID = self.__getNumber()
                    self.__undoController.newOperation()
                    if not self.__students.delete(ID):
                        self.__undoController._index -= 1
                        
                elif cmd == 6:

                    ID = self.__getNumber()
                    self.__undoController.newOperation()
                    if not self.__disciplines.delete(ID):
                        self.__undoController._index -= 1
                    
                elif cmd == 7:
                    
                    self.__undoController.newOperation()
                    if not self.__students.update(self.__readStudent()):
                        self.__undoController._index -= 1
                                      
                elif cmd == 8:
                    
                    self.__undoController.newOperation()
                    if not self.__disciplines.update(self.__readDiscipline()):
                        self.__undoController._index -= 1
                    
                    
                elif cmd == 9:
                    
                    print(str(self.__students))
                    
                elif cmd == 10:
                    
                    print(str(self.__disciplines))
                    
                elif cmd == 11:
                    s = ""
                    for i in self.__students.getAll():
                        s += str(i) + ":\n"
                        for j in self.__disciplines.getAll():
                            s += "\t" + j.getName() + ": "
                            for k in self.__grades.getAll():
                                if i.getID() == k.getID_student() and j.getID() == k.getID_discipline():
                                    s += str(k.getGrade()) + ", "
                            s +="\n"
                        s +="\n"
                    print (s)
                    
                elif cmd == 12:
                    
                    ID = self.__getNumber()
                    print(self.__disciplines.find(ID))
                    
                elif cmd == 13:
                    
                    ID = self.__getNumber()
                    print(self.__students.find(ID))
                
                elif cmd == 14:
                    
                    nameDiscipline = input("Discipline Name: ") 
                    self.__disciplines.findByName(nameDiscipline)
                    
                elif cmd == 15:
                    
                    nameStud = input("Student Name: ")  
                    self.__students.findByName(nameStud)
                    
                elif cmd == 16 or cmd == 17 or cmd == 18 or cmd == 19:
                    
                    statistics = Statistics(self.__grades)
                    print(statistics.statisticsMenu(cmd))
                
                elif cmd == 20:
                    if not self.__undoController.undo():
                        print("Cannot perform undo command")
                
                elif cmd == 21:
                    if not self.__undoController.redo():
                        print("Cannot perform redo command")
                else:
                    break
            except ValueError:
                print("Please enter a number between 0-21!")
