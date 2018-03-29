from random import randint, random

def individual(length, vmin, vmax):
    return [ randint(vmin, vmax) for x in range(length)]


def population(count, length, vmin, vmax):
    return [individual(length, vmin, vmax) for x in range(count)]


def genTest(fileName, popSize, tasksNumber, computersNumber):

    list = population(popSize, tasksNumber, 0, computersNumber-1);

    f = open(fileName, "w")
    f.write("%d,%d,%d\n" %(popSize, tasksNumber, computersNumber))

    for i in range(0, len(list)):
        for j in range(0, len(list[i])):
            f.write(str(list[i][j]) + ',')
        f.write('\n')

    for i in range(tasksNumber):
        for j in range(computersNumber):
            f.write(str(i) + ',' + str(j) + ',' + str(random()))
            f.write('\n')



#genTest("test1.txt", 5, 10, 3);
#genTest("test2.txt", 10, 5, 2);
#genTest("test3.txt", 100, 100, 10);
#genTest("test4.txt", 1000, 1000, 100);
#genTest("test5.txt", 100, 1000, 25)
genTest("statistics.txt", 40, 30, 5)