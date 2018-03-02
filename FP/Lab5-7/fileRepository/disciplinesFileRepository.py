'''
Created on Dec 17, 2016

@author: Emy
'''
from repository.Repository import Repository
from domain.Discipline import Discipline

class DisciplinesFileRepository(Repository):
    

    def __init__(self, fileName):
        Repository.__init__(self)
        self.fileName = fileName
        self._loadFromFile()
      
    def _storeToFile(self):
        
        try:
            f = open(self.fileName, "w")
        except IOError:
            return
        
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
            obj = Discipline(int(param[0]), param[1])
            self.store(obj)
            line = f.readline().strip()
            
        f.close()  
        
        
        