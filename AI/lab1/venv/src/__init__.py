from time import time
from math import sqrt


class Configuration:
    '''
    holds a configurations of sliding puzzle
    '''

    def __init__(self, positions):
        self.__size = len(positions)
        self.__values = positions[:]
        self.__columnSize = int(sqrt(self.__size))

    def getSize(self):
        return self.__size

    def getValues(self):
        return self.__values[:]

    def getColumnSize(self):
        return self.__columnSize

    def findPoz(self):
        for i in range(len(self.__values)):
            if self.__values[i] == 0:
                return i
        return -1

    def nextConfig(self):
        '''
        slide an element to the empty 'poz', [top bottom left right] directions
        in: poz = the position of the empty slot
        out: list of next current configurations obtained from sliding elements to poz slot
        '''
        nextC = []
        poz = self.findPoz()

        if poz % self.__columnSize:
            aux = self.__values[:]
            aux[poz], aux[poz - 1] = aux[poz - 1], aux[poz]
            nextC.append(Configuration(aux))
            # left sliding

        if poz % self.__columnSize < self.__columnSize - 1:
            aux = self.__values[:]
            aux[poz], aux[poz + 1] = aux[poz + 1], aux[poz]
            nextC.append(Configuration(aux))
            # right sliding

        if poz + self.__columnSize < self.__size:
            aux = self.__values[:]
            aux[poz], aux[poz + self.__columnSize] = aux[poz + self.__columnSize], aux[poz]
            nextC.append(Configuration(aux))
            # bottom sliding

        if poz - self.__columnSize >= 0:
            aux = self.__values[:]
            aux[poz], aux[poz - self.__columnSize] = aux[poz - self.__columnSize], aux[poz]
            nextC.append(Configuration(aux))
            # top sliding

        return nextC

    def __eq__(self, other):
        if not isinstance(other, Configuration):
            return False
        if self.__size != other.getSize():
            return False
        for i in range(self.__size):
            if self.__values[i] != other.getValues()[i]:
                return False
        return True

    def __str__(self):

        s = ''
        for i in range(len(self.__values)):
            s = s + str(self.__values[i]) + " "
            if (i+1) % self.__columnSize == 0:
                s = s + "\n"

        return s


class State:
    '''
    holds a PATH of configurations
    '''

    def __init__(self):
        self.__values = []

    def setValues(self, values):
        self.__values = values[:]

    def getValues(self):
        return self.__values[:]

    def __str__(self):
        s = ''
        for x in self.__values:
            s += str(x) + "\n"
        return s

    def __add__(self, something):
        aux = State()
        if isinstance(something, State):
            aux.setValues(self.__values + something.getValues())
        elif isinstance(something, Configuration):
            aux.setValues(self.__values + [something])
        else:
            aux.setValues(self.__values)
        return aux


class Problem:

    def __init__(self):
        self.__initialConfig = []
        self.__finalConfig = []
        self.readFromFile();

        self.__initialState = State()
        self.__initialState.setValues([self.__initialConfig])

    def expand(self, state):
        myList = []
        currentConf = state.getValues()[-1]

        for x in currentConf.nextConfig():
            myList.append(state + x)

        return myList

    def getFinal(self):
        return self.__finalConfig

    def getRoot(self):
        return self.__initialState

    def heuristics(self, configuration):
        count = 0

        for i in range(len(self.__finalConfig.getValues())):
            if configuration.getValues()[-1].getValues()[i] == self.__finalConfig.getValues()[i]:
                count = count + 1
        return -1*count

    def readFromFile(self):

        fin = open('text.txt', 'r')
        list = []
        for line in fin.readlines():
            list.append([int(x) for x in line.split(',')])

        self.__initialConfig = Configuration(list[0])
        self.__finalConfig = Configuration(list[1])



class Controller:

    def __init__(self, problem):
        self.__problem = problem


    def BFS(self, root):

        q = [root] # initial state added in Q
        viz = {}

        while len(q) > 0:
            currentState = q.pop(0)

            viz[str(currentState.getValues()[-1])] = True

            if currentState.getValues()[-1] == self.__problem.getFinal():
                return currentState


            for x in self.__problem.expand(currentState):
                 if str(x.getValues()[-1]) not in viz:
                    q = q + [x]


    def GBFS(self, root):
        q = [root]  # initial state added in Q
        viz = {}

        while len(q) > 0:
            currentState = q.pop(0)

            viz[str(currentState.getValues()[-1])] = True

            if currentState.getValues()[-1] == self.__problem.getFinal():
                return currentState

            aux = []
            for x in self.__problem.expand(currentState):
                if str(x.getValues()[-1]) not in viz:
                    aux = aux + [x]


            aux = [[x, self.__problem.heuristics(x)] for x in aux]
            aux.sort(key=lambda x: x[1])
            aux = [x[0] for x in aux]


            q =   aux[:] + q


class UI:

    def __init__(self):
        self.__p = Problem()
        self.__contr = Controller(self.__p)

    def printMainMenu(self):
        s = ''
        s += "0 - exit \n"
        s += "1 - find a path with BFS \n"
        s += "2 - find a path with GBFS\n"
        print(s)

    def findPathBFS(self):
        startClock = time()
        print(str(self.__contr.BFS(self.__p.getRoot())))
        print('execution time = ', time() - startClock, " seconds")

    def findPathGBFS(self):
        startClock = time()
        print(str(self.__contr.GBFS(self.__p.getRoot())))
        print('execution time = ', time() - startClock, " seconds")

    def run(self):
        runM = True
        self.printMainMenu()
        while runM:
            try:
                command = int(input(">>"))
                if command == 0:
                    runM = False
                elif command == 1:
                    self.findPathBFS()
                elif command == 2:
                    self.findPathGBFS()
            except:
                print('invalid command')

def main():
    #tests();
    ui = UI();
    ui.run();

main()
'''
main()
list = [1,2,3,4,5,0,6,7,8]
print(list)
initialConf = Configuration(list)
print(initialConf)
'''

#initialConf = Configuration([1,2,3,4,5,'O',6,7,8])
#finalConf = Configuration([4,'O',1,2,7,3,5,6,8])


#initialConf = Configuration([4, 7, 3, 1, 5, 8, 6, 2, 'O'])
#finalConf = Configuration(['O', 1, 2, 3, 4, 5, 6, 7, 8])

'''
#1 2 3
#4 5 'O'
#6 7 8

#4 'O' 1
#2 7 3
#5 6 8
'''


#initialConf = Configuration(['O',2,1,3])
#finalConf = Configuration([1,2,3,'O'])

'''
problem = Problem(initialConf, finalConf)
controller = Controller(problem)

a = time()
print(controller.GBFS(problem.getRoot()))
print(time() - a)
'''

'''
1  2  3  4
5  10  6  8
13  0  7 12
14 9  15 16

1,2,3,4,5,6,7,8,9,10,0,12,13,14,15,16
1,2,3,4,5,10,6,8,13,0,7,12,14,9,15,16
'''

