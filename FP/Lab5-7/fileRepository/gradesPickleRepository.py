'''
Created on Dec 17, 2016

@author: Emy
'''
from repository.Repository import RepositoryGrades
import pickle

class GradesPickleRepository(RepositoryGrades):
    
    
    def __init__(self, fileName):
        RepositoryGrades.__init__(self)
        self.fileName = fileName
        self.loadFromFile()
      
    
    def storeToFile(self):
        f = open(self.fileName, "wb")
        pickle.dump(self.getAll(), f)
        f.close()
        
    def loadFromFile(self):
        f = open(self.fileName, "rb")  
        for i in pickle.load(f):
                self.store(i)
        f.close()
    

    
    