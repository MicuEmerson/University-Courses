'''
Created on Nov 27, 2016

@author: Emy
'''



class Statistics(object):
    '''
    classdocs
    '''

    def __init__(self, gradesController):
        '''
        gradesController = a controller with Grades objects
        '''
        self.__gradesController = gradesController
        
    def __cmd16(self):
        '''
         Functionality: All students enrolled at a given discipline, sorted alphabetically or by descending order of average grade
         INPUT: -
         OUTPUT: a string with 
        '''
        
        s = ""
        for i in self.__gradesController.cmd16():
            s += str(i) +'\n'
        
        return s
    
            
    def __cmd17(self):
        '''
        Functionality: All students failing at one or more disciplines
        INPUT: -
        OUTPUT: a string with persons that have a grade at one discipline lower then 5
        '''
        
        s = ""
        for i in self.__gradesController.cmd17():
            s += str(i) + '\n'
           
        return s
    
            
    def __cmd18(self):
        '''
         Functionality: Students with the best school situation, sorted in descending order of their aggregated average
         INPUT: -
         OUTPUT: a string with students sorted in descendent order of their aggregated average
        '''
    
        s = ''     
        for i in self.__gradesController.cmd18():
            s += str(i) + '\n'
           
        return s
    
    
    def __cmd19(self):
        '''
         Functionality: All disciplines at which there is at least one grade, sorted in descending order of the average grade received by all students enrolled at that discipline
         INPUT: -
         OUTPUT: a string with 
        '''
        
        s = ''     
        for i in self.__gradesController.cmd19():
            s += str(i) + '\n'
        
        return s
    
    
    def statisticsMenu(self, cmd):
        '''
            A menu that will call a cmd(number) function
            INPUT: cmd = number commmand
            OUTPUT: return a function which belong to cmd
        '''
        if cmd == 16: return self.__cmd16()
        if cmd == 17: return self.__cmd17()
        if cmd == 18: return self.__cmd18()
        if cmd == 19: return self.__cmd19()
    
    
            