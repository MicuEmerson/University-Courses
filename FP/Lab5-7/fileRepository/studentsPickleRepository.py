'''
Created on Dec 17, 2016

@author: Emy
'''
from repository.Repository import Repository
import pickle

class StudentsPickleRepository(Repository):
    
    
    def __init__(self, fileName):
        Repository.__init__(self)
        self.fileName = fileName
        self.loadFromFile()
        
    def getAll(self):
        return Repository.getAll(self)
    
    def storeToFile(self):
        f = open(self.fileName, "wb")
        pickle.dump(self.getAll(), f)
        f.close()
        
    def loadFromFile(self):
        f = open(self.fileName, "rb")  
        for i in pickle.load(f):
                self.store(i)
        f.close()
    