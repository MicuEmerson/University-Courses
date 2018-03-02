'''
Created on Dec 11, 2016

@author: Emy
'''
from controller.undoController import FunctionCall, Operation

class StudentController:
    
    def __init__(self, repository, undoController, gradesRepository):
        self.__repository = repository
        self._undoController = undoController
        self.__gradesRepository = gradesRepository
        
  
    def store(self, entity):
    
        status = self.__repository.store(entity)
        if status != False:
            
            redo = FunctionCall(self.store, entity) 
            undo = FunctionCall(self.delete, entity.getID())
            operation = Operation(redo, undo)
            self._undoController.recordOperation(operation)
         
        return status
        
     
    def update(self, entity):
        
        entityForUndo = self.__repository.find(entity.getID()) # we save the current one before we add the new one
        status = self.__repository.update(entity)
        
        if status != False:
            
            redo = FunctionCall(self.update, entity) 
            undo = FunctionCall(self.update, entityForUndo)
            self._undoController.newOperation()
            operation = Operation(redo, undo)
            self._undoController.recordOperation(operation)
        
        return status
    
    
    def delete(self, ID):
        
        entity =  self.__repository.delete(ID)
        
        if entity != False:
            myList = self.__gradesRepository.getAllStudentGrades(ID)
            self.__gradesRepository.deleteByStud(ID)    
            
            redo = FunctionCall(self.delete, ID) 
            undo = FunctionCall(self.store, entity)
            operation = Operation(redo, undo)
            self._undoController.recordOperation(operation)
            
            for i in myList:
                redo = FunctionCall(self.__gradesRepository.delete, i) 
                undo = FunctionCall(self.__gradesRepository.store, i)
                operation = Operation(redo, undo)
                self._undoController.recordOperation(operation)
                
            return True
        
        return False
    
    def find(self, ID):
        return self.__repository.find(ID)
    
    def findByName(self, name):
        return self.__repository.findByName(name)
    
    def findByName2(self, name):
        return self.__repository.findByName2(name)
    
    def getAll(self):
        return self.__repository.getAll()
    
    def __str__(self):
        return str(self.__repository)
    


    
    