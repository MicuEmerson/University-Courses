'''
Created on Dec 17, 2016

@author: Emy
'''

from domain.Student import Student
from domain.Discipline import Discipline
from domain.Grades import Grades
from repository.Repository import Repository
from repository.Repository import RepositoryGrades
from controller.DisciplineController import DisciplineController
from controller.GradesController import GradesController
from controller.StudentController import StudentController
from controller.undoController import UndoController
from ui.console import UI
from fileRepository.studentsFileRepository import StudentsFileRepository
from fileRepository.studentsPickleRepository import StudentsPickleRepository
from fileRepository.disciplinesFileRepository import DisciplinesFileRepository
from fileRepository.disciplinesPickleRepository import DisciplinesPickleRepository
from fileRepository.gradesFileRepository import GradesFileRepository
from fileRepository.gradesPickleRepository import GradesPickleRepository
from random import Random

def extractName(string):
    result = ''
    flag = 0
    for i in string:
        if i == '"':
            flag = 1
        if flag == 1:
            result += i
    
    return result[1:-1]


f = open("settings.properties", "r")

whatRepo = f.readline().strip()
whatRepo = whatRepo.split('=')
whatRepo = whatRepo[1].strip()


if whatRepo == 'inmemory':
    studentsRepository = Repository()
    disciplineRepository = Repository()
    gradesRepository = RepositoryGrades()
    
elif whatRepo == 'textfiles':
    fileName = extractName(f.readline().strip())
    studentsRepository = StudentsFileRepository(fileName)
    
    fileName = extractName(f.readline().strip())
    disciplineRepository = DisciplinesFileRepository(fileName)
    
    fileName = extractName(f.readline().strip())
    gradesRepository = GradesFileRepository(fileName)
    
elif whatRepo == 'binaryfiles':
    fileName = extractName(f.readline().strip())
    studentsRepository = StudentsPickleRepository(fileName)
    
    fileName = extractName(f.readline().strip())
    disciplineRepository = DisciplinesPickleRepository(fileName)
   
    
    fileName = extractName(f.readline().strip())
    gradesRepository = GradesPickleRepository(fileName)


f.close()


undoController = UndoController()
undoController.newOperation()
students = StudentController(studentsRepository, undoController, gradesRepository)
disciplines = DisciplineController(disciplineRepository, undoController, gradesRepository)
grades = GradesController(studentsRepository, disciplineRepository, gradesRepository, undoController)

ui = UI(students, disciplines, grades, undoController)
        

def generateStudents():
    undoController.newOperation(), students.store(Student(123, 'Andrei Stefan'))
    undoController.newOperation(), students.store(Student(124, 'Cosmin Iordache'))
    undoController.newOperation(), students.store(Student(125, 'Simon Claudiu'))
    undoController.newOperation(), students.store(Student(126, 'Arthur Mihai'))
    undoController.newOperation(), students.store(Student(127, 'George Ionut'))
    undoController.newOperation(), students.store(Student(128, 'Beatrice Chelaru'))
    undoController.newOperation(), students.store(Student(129, 'Iosif Emil'))
    undoController.newOperation(), students.store(Student(130, 'Cret Vasile'))
    undoController.newOperation(), students.store(Student(131, 'Popovici Tudor'))
    undoController.newOperation(), students.store(Student(132, 'Ciprian Teodorescu'))


def generateDisciplines():
    undoController.newOperation(), disciplines.store(Discipline(1,'Math'))
    undoController.newOperation(), disciplines.store(Discipline(2,'Assembly Language'))
    undoController.newOperation(), disciplines.store(Discipline(3,'Programming Fundamentals'))
    undoController.newOperation(), disciplines.store(Discipline(4,'Computation Logic'))
    undoController.newOperation(), disciplines.store(Discipline(5,'Sport'))

def generateGrades():
    
    for i in students.getAll():
        n = 4
        while n:
            n -= 1
            for j in disciplines.getAll():
                grade = Random().randint(1, 10)
                undoController.newOperation()
                grades.store(Grades(j.getID(), i.getID(), grade))


if whatRepo == 'inmemory':
    generateStudents()
    generateDisciplines()
    generateGrades()
        

ui.run()
if whatRepo == 'textfiles' or whatRepo == 'binaryfiles':
    studentsRepository.storeToFile()
    disciplineRepository.storeToFile()
    gradesRepository.storeToFile()
    
    
    






