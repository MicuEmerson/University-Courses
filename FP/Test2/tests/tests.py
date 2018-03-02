'''
Created on Dec 18, 2016

@author: Emy
'''
import unittest
from repository.Repository import Repository
from controller.controller import Controller
from ui.console import UI
from domain.student import Student


class Test(unittest.TestCase):
 
    
    def testRepo(self):
        repo = Repository()
        assert repo.add(Student('1', 'Mihai Ionut', 10, 10)) == False
        assert repo.add(Student('2', 'Mihai Ionut', 10, 10)) == False
        assert repo.add(Student('3', 'Mihai Ionut', 10, 10)) == False
        
        repo.addBonus(Student('1', 'Mihai', 13, 9), 1)
        repo.addBonus(Student('2', 'Ionut', 5, 8), 1)
        for i in repo.getAll():
            if i.getID() == 1:
                assert i.getGrade() == 10
            if i.getID() == 2:
                assert i.getGrade() == 9
        
        assert len(repo.getAll()) == 10
            
    def testController(self):
        
        repo = Repository()
        controller = Controller(repo)
        
        myList = controller.displayAllStudents('M')
        assert len(myList) == 3
        
        myList = controller.displayStudentsOrderedByGrades()
        assert myList[0].getGrade() == 10
        assert myList[1].getGrade() == 9
        assert myList[0].getName() == 'Ionela'
        
        
        

        
        
        
        
        
        
        
        
        
        
        
        
   

