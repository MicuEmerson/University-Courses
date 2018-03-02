'''
Created on Dec 19, 2016

@author: Emy
'''
from repository.Repository import Repository

class Controller:
    
    def __init__(self, myRepo):
        self.myRepo = myRepo
    
    def add(self, entity):
        '''
            We just simply append into repository the entity, we valid it in repo
            INPUT: entity = a object Student
            OUTPUT: True / False
        '''
        return self.myRepo.add(entity)
    
    def bonus(self, p, b):
        '''
          We iterate to whole repo and we search for stundets who have attendaces >= p
          INPUT: p = minum attendaces at course
                 b = bonus points added at the grade
          OUTPUT: -
        '''
        for i in self.myRepo.getAll():
            if i.getAttendances() >= int(p):
                self.myRepo.addBonus(i, int(b))
    
    def displayAllStudents(self, string):
        '''
            We return a list with all the names include a given string
            INPUT: string
            OUPUT: List with all names
        '''
        myList = [] 
        for i in self.myRepo.getAll():
            if string in i.getName():
                myList.append(i.getName())
        
        myList.sort()
        return myList
    
    def displayStudentsOrderedByGrades(self):
        '''
            We sort the students by the grade, i used simply .sort() function
            because I have defined __lt__ in my domain student class
            INPUT : -
            OUPUT : a list with all students ordered by their grade
        '''
        myList = self.myRepo.getAll()
        myList.sort()
        return myList
        
    def __len__(self):
        return len(self.getAll)
        
        
        
        
        
        
        