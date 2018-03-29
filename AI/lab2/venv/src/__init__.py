from random import randint, random
from operator import add
from math import cos, pi
import matplotlib.pyplot as plt
import numpy as numpy

class Individ:

    def __init__(self, computersSize, taskArray, d):
        self.computersSize = computersSize
        self.tasksArray = taskArray  #task[i] = la taskul i am asignat ceva calculator
        self.individSize = len(taskArray)
        self.d = d                   #dictionar unde gasim timpul
        self.f = self.fitness()


    def fitness(self):
        """
        Determine the fitness of an individual. Lower is better.(min problem)
        individual: the individual to evaluate
        We sum the time in which computer i finish tasks[i]
        """

        f = 0.0;
        for i in range(self.individSize):
            f = f + self.d[(i, self.tasksArray[i])]

        return f

    def mutate(self, pM):

        if pM > random():
            p = randint(0, len(self.tasksArray) - 1)
            self.tasksArray[p] = randint(0, self.computersSize-1);

        self.f = self.fitness()



    @staticmethod
    def crossover(parent1, parent2):
        child1 = []
        child2 = []

        n = randint(0, parent1.individSize);

        for i in range(parent1.individSize):
            if i <= n:
                child1.append(parent1.tasksArray[i])
                child2.append(parent2.tasksArray[i])
            else:
                child2.append(parent2.tasksArray[i])
                child1.append(parent1.tasksArray[i])

        return child1, child2;


    def __str__(self) -> str:
        return str(self.tasksArray)




class Population:

    def __init__(self, values):
        self.values = values
        self.populationSize = len(values)

    def selection(self):
        self.values = sorted(self.values, key=lambda Individ: Individ.f)
        self.values = self.values[:self.populationSize]

    def reunion(self, otherPopulation):
        self.values = self.values + otherPopulation.values


    def __str__(self) -> str:
        s = ""
        for x in self.values:
            s = s + str(x) + '\n'
        return s


class Problem():

    def __init__(self ,fileName):
        self.populationSize = 0
        self.tasksNumber = 0     #individualSize
        self.computersSize = 0   #number of computers that will be used to solve tasks
        self.values = []         #the actual population
        self.d = {}              #dictionar(x,y) = z, where x=task, y=pc, z=time
        self.loadData(fileName)

    def loadData(self, fileName):

        try:
            f = open(fileName, "r")
            l = f.readline().split(',')
            self.populationSize = int(l[0])
            self.tasksNumber = int(l[1])
            self.computersSize = int(l[2])


            for i in range(self.populationSize):
                self.values.append([int(x) for x in f.readline().split(',')[:-1]]);


            for i in range(self.tasksNumber * self.computersSize):
                l = f.readline().split(',')
                task = int(l[0])
                computer = int(l[1])
                time = float(l[2])
                #print(task," ",computer, " ",time)
                self.d[(task, computer)] = time

            '''
            for i in self.values:
                print(i)
                
            for i in self.d:
               print(i , '=' , self.d[(i[0],i[1])])

            '''
        except Exception as e:
            print(str(e))
            sys.exit(1)



class Algorithm():

    def __init__(self, fileName, paramFileName, noIteratii = 10):
        self.problem = Problem(fileName)
        self.probability_mutate = 0.4
        self.noIteratii = 100
        #self.readParameters(paramFileName)

        individs = []
        for i in self.problem.values:
            individs.append(Individ(self.problem.computersSize, i, self.problem.d))

        self.population = Population(individs)


    def readParameters(self, paramFileName):
        try:
            f = open(paramFileName, "r")
            for line in f:
                (key, value) = line.split("=")
                if key == "probability_mutate":
                    self.probability_mutate = float(value)
                elif key == "no_iteratii":
                    self.noIteratii = int(value)
                else:
                    raise Exception("Corrupt parameters file (key)")
        except Exception as e:
            print(str(e))
            sys.exit(1)

    def iterations(self):
        size = self.population.populationSize
        nextValues= []

        while size != 0:
            idx1 = randint(0, self.population.populationSize - 1)
            idx2 = randint(0, self.population.populationSize - 1)

            if idx1 != idx2:
                i1 = self.population.values[idx1]
                i2 = self.population.values[idx2]

                ii1, ii2 = Individ.crossover(i1,i2)

                ind1 = Individ(self.problem.computersSize, ii1, self.problem.d);
                ind2 = Individ(self.problem.computersSize, ii2, self.problem.d);
                ind1.mutate(self.probability_mutate)
                ind2.mutate(self.probability_mutate)

                nextValues.append(ind1)
                nextValues.append(ind2)
                size = size - 1


        return Population(nextValues)



    def run(self):
        aux = []
        while(self.noIteratii != 0):
            newPopulation = self.iterations();
            #print(str(newPopulation))
            self.population.reunion(newPopulation)
            self.population.selection()
            self.noIteratii = self.noIteratii - 1
            aux.append(self.population.values[0].f)

        return aux

    @staticmethod
    def statistics(aux):

        standardev = numpy.std(aux)
        average = numpy.average(aux)
        best = min(aux)
        print("Standard:" + str(standardev))
        print("Average:" + str(average))
        print("Best:" + str(best))



class Application:
    def __init__(self, fileName):
        self.fileName = fileName

    def main(self):
        self.algorithm = Algorithm(self.fileName, "")
        result = self.algorithm.run()
        Algorithm.statistics(result)
        plt.plot(result)
        plt.show()



a = Application("test5.txt")

a.main()





