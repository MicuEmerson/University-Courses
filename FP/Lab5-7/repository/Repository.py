'''
Created on Nov 26, 2016

@author: Emy
'''
from myDataStructure import MyDataStructure

class Repository:
    
    def __init__(self):
        #self._objects = []
        self._objects = MyDataStructure()

    def store(self, obj):
        '''
         Functionality: Try to add to repository a new object, if fail(it can fail when object is already in the repository) return False, else True
         INPUT: an object
         OUPUT: successful added = True, Fail = False
        '''
        if self.find(obj.getID()) != False:
            print("Element having id = " + str(obj.getID()) + " already stored!")
            return False
        self._objects.append(obj)
        return True
    

    def update(self, object):
        """
        Update the instance given as parameter. The provided instance replaces the one having the same ID
        object - The object that will be updated
        Raises RepositoryException in case the object is not contained within the repository
        """
        el = self.find(object.getID())
        if el == False:
            print("Element not found!")
            return False
        index = self._objects.getIndex(el)
        self._objects[index] = object
        return True

    def find(self, objectId):
        '''
          Search an object in repository by his ID
          INPUT:
              objectID - the ID of the searched buildings
          OUTPUT:
              the object of the ID if it was found
              None if not found
        '''
        for i in self._objects:
            if objectId == i.getID():
                return i
        return False
    
    def delete(self, objectId):
        """
        Remove the object with given objectId from repository
        objectId - The objectId that will be removed
        Returns the object that was removed
        Raises RepositoryException if object with given objectId is not contained in the repository
        """
        entity = self.find(objectId)
        
        if entity == False:
            print("Element not in repository!")
            return False
        
        index = self._objects.getIndex(entity)
        del self._objects[index]
        return entity
    
    
    def findByName(self, name):
        '''
          Functionality: Will print all the students/discipline with the name "name" witch is also case insensitive and partial string match
          Input: name - the name of discipline/student
          Ouput: True if we found something, else False
        '''
        gasit = 0
        
        for i in self._objects:
            if name.lower() == i.getName().lower() or name.lower() in i.getName().lower():
                print(str(i))
                gasit = 1
        
        if gasit == 0: return False
        else: return True
        

    def findByName2(self, name):
        '''
          Functionality: search in repository a discipline with name 'name' and return the id of that discipline
          Input: name - the name of the discipline
          Ouput: the ID of discipline witch have the name 'name'
        '''
        for i in self._objects:
            if name.lower() == i.getName().lower():
                return i.getID()
        return False
    

    def getAll(self):
        return self._objects;

    def __len__(self):
        return len(self._objects)

    def __str__(self):
        r = "Repository:\n"
        for e in self._objects:
            r += str(e)
            r += "\n"
        return r
    

class RepositoryGrades:
    
    def __init__(self):
        self._objects = MyDataStructure()
        

    def store(self, object):
        self._objects.append(object)
        

    def update(self, object):
        """
        Update the instance given as parameter. The provided instance replaces the one having the same ID
        object - The object that will be updated
        Raises RepositoryException in case the object is not contained within the repository
        """
        el = self.find(object.getID_discipline(), object.getID_student())
        if el == False:
            print("Element not found!")
            return False
        index = self._objects.getIndex(el)
        self._objects[index] = object
        return True
    
    def delete(self, object):
        '''
           #TODO
        '''
        index = self._objects.getIndex(object)
        del self._objects[index]
        return True
            
        
               

    def find(self, objectId1, objectId2):
        '''
          Search an object in repository by his ID
          INPUT:
              objectId1 - the ID of the discipline
              objectId2 - the ID of the student
          OUTPUT:
              the object of the ID if it was found
              None if not found
        '''
        for i in self._objects:
            if objectId1 == i.getID_discipline() and objectId2 == i.getID_student():
                return i
        return False
    
    def findByDisciplineID(self, ID):
        '''
        Functionality: Search in list of objects, the objects with id same like ID, and put them into a list that will be returned
        INPUT:
            ID - The discipline id that will be searched into repository 
        OUTPUT:
            Mylist - List of ID's of students that have enrolled that the ID of an specify discipline 
        '''
        myList = []
        for i in self._objects:
            if ID == i.getID_discipline():
                myList.append(i.getID_student())

        return myList
    
   
    def deleteByStud(self, ID):
        """
        Remove the objects with the studentID == ID
        ID - The student ID that will be removed
        Print "Element not in repository!" if object with given objectId is not contained in the repository
        """
        status = True
        while status:
            status = False
            for i in self._objects:
                if i.getID_student() == ID:
                    index = self._objects.getIndex(i)
                    del self._objects[index]
                    status = True
    
                
    def deleteByDiscipline(self, ID):
        """
        Remove the objects with the studentID == ID
        ID - The student ID that will be removed
        Print "Element not in repository!" if object with given objectId is not contained in the repository
        """
        
        status = True
        while status:
            status = False
            for i in self._objects:
                if i.getID_discipline() == ID:
                    index = self._objects.getIndex(i)
                    del self._objects[index]
                    status = True
                

    def getAllStudentGrades(self, ID):
        """
        Get all objects with the studentID == ID
        ID - The student ID 
        return a list of objects which contains the 'ID'
        """
        
        myList = []
        for i in self._objects:
            if i.getID_student() == ID:
                myList.append(i)
        
        return myList
    
   
    def getAll(self):
        return self._objects;

    def __len__(self):
        return len(self._objects)

    def __str__(self):
        r = "Repository:\n"
        for i in self._objects:
            r += str(i) + '\n'
            
        return r
    
    
    
    
    
    
    
    
    
    
    
    
     
    
        