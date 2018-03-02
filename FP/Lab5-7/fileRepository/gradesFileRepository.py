'''
Created on Dec 17, 2016

@author: Emy
'''
from repository.Repository import RepositoryGrades
from domain.Grades import Grades

class GradesFileRepository(RepositoryGrades):
    
    
    def __init__(self, fileName):
        RepositoryGrades.__init__(self)
        self.fileName = fileName
        self._loadFromFile()
    
    def _storeToFile(self):
        
        try:
            f = open(self.fileName, "w")
        except IOError:
            return
        
        for i in self.getAll():
            string = str(i.getID_discipline) + ";" + str(i.getID_student()) + ";" +  str(i.getGrade()) + "\n"
            f.write(string)
            
        f.close()

    def _loadFromFile(self):

        try:
            f = open(self.fileName, "r")
        except IOError:
            return
        
        line = f.readline().strip()
        while line != "":
            param = line.split(";")
            obj = Grades(param[0], param[1], int(param[2]))
            self.store(obj)
            line = f.readline().strip()
            
        f.close()  
        
        
        