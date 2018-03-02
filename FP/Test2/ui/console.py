'''
Created on Dec 19, 2016

@author: Emy
'''

from domain.student import Student

class UI:
    
    def __init__(self, controller):
        self.controller = controller
        
    def readAStudent(self):
        while True: 
            try:
                id = input("ID: ")
                name = input("Name: ")
                attendaces = input("Attendaces: ")
                grade = input("Grade: ")
                stud = Student(id, name, int(attendaces), int(grade))
                assert stud.isValid()
                break
            except:
                print("Invalid Input, try again!")
                
        return stud
        
    def printMenu(self):
        s ='\t Menu\n'
        s += '1) Add a student\n'
        s += '2) Give bonuses\n'
        s += '3) Display all students whose name include a given string\n'
        s += '4) Display all students ordered decreasing by grades\n'
        s += '0) Exit\n'
        return s
        
        
    def run(self):
        
        while True:
            print(self.printMenu())
            cmd = int(input("Command: "))
            
            if cmd == 1:
                stud = self.readAStudent()
                if not self.controller.add(stud):
                    print("Stundet with this ID:" + str(stud.getID()) + " is already in repo!")
                
            elif cmd == 2:
                p = input("P: ")
                b = input("B: ")
                self.controller.bonus(p, b)
                
            elif cmd == 3:
                string = input("Read the string: ")
                for i in self.controller.displayAllStudents(string):
                    print(i)
                    
            elif cmd == 4:
                for i in self.controller.displayStudentsOrderedByGrades():
                    print(i)
            else:
                break
    

            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        