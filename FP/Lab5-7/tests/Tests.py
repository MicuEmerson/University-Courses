'''
Created on Nov 28, 2016

@author: Emy
'''
import unittest
from repository.Repository import Repository
from repository.Repository import RepositoryGrades
from domain.Student import Student
from domain.Grades import Grades

class Test(unittest.TestCase):


    def setUp(self):
        unittest.TestCase.setUp(self)


    def tearDown(self):
        unittest.TestCase.tearDown(self)


    def __testRepository(self):
        
        students = Repository()
        students.store(Student(123, 'Andrei Stefan'))
        students.store(Student(124, 'Cosmin Iordache'))
        students.store(Student(125, 'Simon Claudiu'))
        
        # len of repository
        assert len(students) == 3
        
        # findByName2 function tests
        assert students.findByName2('Andrei Stefan') == 123
        assert students.findByName2('Cosmin Iordache') == 124
        assert students.findByName2('Simon Claudiu') == 125
        
        #find tests
        assert students.find(133) == False
        assert students.find(134) == False
        assert students.find(135) == False
        
        #store tests
        assert students.store(Student(123,'Cosmin')) == False
        assert students.store(Student(125, 'Geanina')) == False
        assert students.store(Student(124, 'Mihai')) == False
        
        #update test
        assert students.update(Student(133,'Cosmin')) == False
        assert students.update(Student(155, 'Geanina')) == False
        assert students.update(Student(175, 'Ionut')) == False
        
        
        students.store(Student(126, 'Arthur Mihai'))
        students.store(Student(127, 'George Ionut'))
        
        # test store and delete
        assert len(students) == 5
        students.delete(123)
        assert len(students) == 4
        assert students.delete(1664) == False
        
        
        
    
    def __testGradesRepository(self):
        
        grades = RepositoryGrades()
        
        #test Store
        grades.store(Grades(1, 123, 10))
        assert len(grades) == 1
        grades.store(Grades(3, 124, 9))
        assert len(grades) == 2
        grades.store(Grades(3, 125, 10))
        assert len(grades) == 3
        grades.store(Grades(4, 123, 10))
        assert len(grades) == 4
        
        #test getAll
        myList = grades.getAll()
        assert len(myList) == 4
        
        #test findByDisciplineID
        myList = grades.findByDisciplineID(3)
        assert len(myList) == 2
        
        #test find 
        assert grades.find(4,124) == False
        assert grades.find(4,125) == False
        assert grades.find(4,126) == False
        assert grades.find(4,127) == False
        
      
        
    def testAll(self):
        self.__testRepository()
        self.__testGradesRepository()
    
        
        
        
        
testing = Test()
testing.testAll()