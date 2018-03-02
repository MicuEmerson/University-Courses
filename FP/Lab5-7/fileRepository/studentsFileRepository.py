'''
Created on Dec 17, 2016

@author: Emy
'''
from repository.Repository import Repository
from domain.Student import Student

class StudentsFileRepository(Repository):
    

    def __init__(self, fileName):
        Repository.__init__(self)
        self.fileName = fileName
        self._loadFromFile()

    def _storeToFile(self):
        
        f = open(self.fileName, "w")
        
        for i in self.getAll():
            string = str(i.getID()) + ";" + i.getName() + "\n"
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
            obj = Student(int(param[0]), param[1])
            self.store(obj)
            line = f.readline().strip()
            
        f.close()  
        
        
        