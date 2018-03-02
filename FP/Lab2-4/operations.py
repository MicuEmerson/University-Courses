from validations import *
import copy

###################################################################################################
############################################ ADD ##################################################
###################################################################################################

def addCommand(buildings, params, myList):
    '''
        This function add to an apartament with type_expense an amout, if there is not an apartament or an expense with this type, we will create a new one,
        myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place it to myList
        INPUT: buildings = nested dictionary, params[0] = apartament, params[1] = expense, params[2] = amount, myList = list of buildings
        OUPUT: True is we gave good parameters, else False
    '''
    if len(params) == 3 and checkDigits(params[0]) and checkExpense(params[1]) and checkDigits(params[2]):
        
        if int(params[0]) in buildings:
            myList.append(copy.deepcopy(buildings))
            if params[1] in buildings[int(params[0])]:
                buildings[int(params[0])][params[1]] += int(params[2])
            else:
                buildings[int(params[0])][params[1]] = int(params[2])
                
        else:
            myList.append(copy.deepcopy(buildings))
            buildings[int(params[0])]={} # we need to create it(apartament) first                   
            buildings[int(params[0])][params[1]] = int(params[2])
            
        return True;
    
    else:
        print("Invalid Input")
        return False;

###################################################################################################
############################################ REMOVE ###############################################
###################################################################################################
    
def remove(buildings, ap, myList):
    '''
         This function just remove an aparament (ap) from the dictionary(buildings)
         myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place it to myList
         INPUT: buildings = nested dictionary, ap = apartament, myList = list of dictionaries
         OUTPUT: True if we found and remove it, else False
    '''
    
    if ap in buildings:
        myList.append(copy.deepcopy(buildings))
        del buildings[ap];
        return True;
    
    return False;


def removeExpense(buildings, ex, myList):
    '''
         This function  remove an ex(expanse) from all apartaments
         myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place it to myList
         INPUT: buildings = nested dictionary which contain apartaments with expanses, ex = expanse, myList = list of buildings
         OUTPUT: -
    '''
    gasit = 0
    myList.append(copy.deepcopy(buildings))
    
    for i in buildings.keys():
        if ex in buildings[i]:
            gasit = 1
            del buildings[i][ex]
            
    if gasit == 0:
        myList.pop()


def removeRange(buildings, left, right, myList):
    '''
         This function  remove apartament in a given range
         myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place it to myList
         INPUT: buildings = nested dictionary, left and right are the range between we will remove all apartaments, myList = list of buildings
         OUTPUT: -
    '''
    gasit = 0 # with this variable we see if we made some changes to your building, if we don't made, we will pop the current building that we added before checking some changes
    myList.append(copy.deepcopy(buildings))
    
    for i in range(left, right + 1):
        if i in buildings:
            gasit = 1
            del buildings[i]

    if gasit == 0:
        myList.pop()
            
                    
            
def removeCommand(buildings, params, myList):
    '''
        This function remove the apartament from the dictionary(buildings)
        myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place it to myList
        INPUT: nested dictionary(buildings), params = a list with [params[0] = apartament, params[1] = expense, params[2] = amount], myList = list of buildings
        OUTPUT: True if we removed something, else False if we have invalid input
    '''
    if len(params) == 1:
        
         if checkDigits(params[0]):
             return remove(buildings, int(params[0]), myList)
                    
         elif checkExpense(params[0]):
             removeExpense(buildings, params[0], myList)
             return True
                    
         else:
             print("Invalid Input")
             return False
              
    else:
        if checkDigits(params[0]) and checkDigits(params[1]):
            removeRange(buildings, int(params[0]), int(params[1]), myList)
            return True;
                            
        else:
            print("Invalid Input")
            return False;
         
    

def replaceCommand(buildings, params, myList):
    '''
       This function will change the value from apartament X and expanse Y with amount Z
       myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place it to myList
       INPUT: nested dictionary(buildings), params = a list with [params[0] = apartament, params[1] = expense, params[2] = amount], myList = list of buildings
       OUTPUT: True if we replaced something, else False if we have invalid input
    '''
    if checkDigits(params[0]) and checkExpense(params[1]) and checkDigits(params[2]) and len(params) == 3:
        myList.append(copy.deepcopy(buildings))
        buildings[int(params[0])][params[1]] = int(params[2])
        return True;

    else:
        print("Invalid Input")
        return False;

###################################################################################################
############################################ LIST  ################################################
###################################################################################################
    
def listPrint(buildings):
    '''
       This function will simply print the list with apartaments and their expenses with amount
       INPUT: nested dictionary(buildings), params = a list with some [params[0] = apartament, params[1] = expense, params[2] = amount]
       OUTPUT: True if we replaced something, else False if we have invalid input
    '''
    for i in buildings.keys(): 
        print("Apartament " + str(i) + ':')
        for j in buildings[i]:
            print('\t', j, buildings[i][j])
        
        print('')
        
def apartamentPrint(buildings, ap):
    '''
       This function will simply print the an apartament with all expenses and amount for each ex
       INPUT: nested dictionary(buildings), params = a list with some [params[0] = apartament, params[1] = expense, params[2] = amount]
       OUTPUT: True if apartament exist and was printed, else False if we don't have that apartament or invalid input
    '''
    if checkDigits(ap):
        if int(ap) in buildings:
            print("Apartament " + str(ap) + ':')
            for i in buildings[int(ap)]:
                print('\t', i, buildings[ int(ap) ] [i])
            return True
        
 
    print("Invalid input")
    return False

def totalExpensesSum(buildings, ap):
    '''
       This function will calculate the sum of all expenses of a given apartament
       INPUT: nested dictionary(buildings), ap = apartament number
       OUTPUT: will return the sum of all expenses of that apartament
    '''
    res = 0
    for i in buildings[ap]:
        res += int(buildings[ap][i])

    return res;
    
        
def operatorPrint(buildings, params):
    '''
       This function will simply print apartaments with total expanses sum < | = | > then a given number
       INPUT: nested dictionary(buildings), params = a list with some [params[0] = < | = | >, params[1] = apartament number
       OUTPUT: True if we have valid input, else False for invalid input
    '''
    
    if (params[0] == '>' or params[0] == '<' or params[0] == '=') and checkDigits(params[1]):
        
        x = int(params[1])       # we transform in int that string which have the aparament number and put it in variable x
        
        if params[0] == '>':
            for i in buildings.keys():
                if totalExpensesSum(buildings, i) > x:
                    print("Apartament " + str(i))
           
        elif params[0] == '<':
            for i in buildings.keys():
                if totalExpensesSum(buildings, i) < x:
                    print("Apartament " + str(i))

        else:
            for i in buildings.keys():
                if totalExpensesSum(buildings, i) == x:
                    print("Apartament " + str(i))
        
        return True
        
    
    print("Invalid input")
    return False
            


def listCommand(buildings, params):
    '''
       This function make more things, if the length of params is 0, we print the list of buildings with all expanses,
       else if the lenght of params is 1 we print just one apartament given on params, elif we have 2 params, then we have an
       operation > < = we print the building which have the total sum of expanses > < = then a value given by us
       INPUT: nested dictionary(buildings), params = a list with some [params[0] = < | = | >, params[1] = apartament number
       OUTPUT: True if we have valid input, else False for invalid input
    '''
    if len(params) == 0:
        listPrint(buildings)
        return True
        
    elif len(params) == 1:
        return apartamentPrint(buildings, params[0])

    elif len(params) == 2:
        return operatorPrint(buildings, params)
        
    else:
        print("Invalid input")
        return False;

###################################################################################################
############################################ SUM ##################################################
###################################################################################################

def sumCommand(buildings, params):
    '''
         This function will calculate the value of all apartament on a specify expense
         INPUT:  buildings = nested dictionars, params is a list with one parameter, params[0] = expense type
         OUTPUT: We print the the amout of the expense, TODOOOOO
    '''
    res = 0
    if(len(params) == 1 and checkExpense(params[0])):
        for i in buildings.keys():
            if params[0] in buildings[i]:
                res += int(buildings[i][params[0]])

        return res
    else:
        print("Invalid input")
        return False

###################################################################################################
############################################ SORT #################################################
###################################################################################################
 
def sortType(buildings):
    '''
         This function will calculate all the expanses type of the building and sort them ascendent 
         INPUT:  buildings = nested dictionary
         OUTPUT: We print the ascendent sorted list of expanses type of building 
    '''
    myList = [[0,'water'], [0,'heating'], [0,'electricity'], [0,'gas'], [0,'other']]
    
    for expense in ['water', 'heating', 'electricity', 'gas', 'other']:
        for i in buildings.keys():
            if expense in buildings[i]:
                for j in myList:
                    if j[1] == expense:
                        j[0] += int(buildings[i][expense])  
   
    myList.sort()
    for i in myList:
        print(i[1] + ": " + str(i[0]))


def totalSumApartament(buildings, ap):
    '''
         This function calculate the total sum of expenses of one apartament
         INPUT:  buildings = nested dictionary, ap = apartament number
         OUTPUT: we return the value of all expenses amout
    '''
    res = 0
    for i in buildings[ap]:
        res += int(buildings[ap][i])
    return res


def sortApartament(buildings):
    '''
         This function will sort the apartament by amount of expanses in ascendent order
         INPUT:  buildings = nested dictionary
         OUTPUT: We print the sorted list
    '''
    myList=[];
    for i in buildings.keys():
        myList.append( [totalSumApartament(buildings, i), i] )

    myList.sort()
    for i in myList:
        print("Apartament " + str(i[1]) + ": " + str(i[0]))
     
    

def sortCommand(buildings, params):
    '''
         This function is the main function of sortCommand
         INPUT:  buildings = nested dictionary, and params which contain on parameter that can be apartament or type
         OUTPUT: If the input if correct the function will return True, else False
    '''
    if len(params) == 1:

        if params[0] == 'apartament':
            sortApartament(buildings)
        elif params[0] == 'type':
            sortType(buildings)
        return True;

    print("Invalid input")
    return False

    
###################################################################################################
############################################ MAX ##################################################
###################################################################################################

def maxCommand(buildings, params):
    '''
         This function will print the maximum amount of expanse that an apartament have
         INPUT:  buildings = nested dictionary, params which contain just one paramere, params[0] = apartament number
         OUTPUT: We print the name of the maximun expense expanse and the amount of it and return True, else we return False for invalid input
    '''
    maxy = 0
    name = '' 
    if len(params) == 1:
        if checkDigits(params[0]):
            if(int(params[0]) in buildings):
                for i in buildings[int(params[0])]:
                    if maxy < buildings[int(params[0])][i]:
                        maxy = buildings[int(params[0])][i]
                        name = i
                    
                print(name + ': ' + str(maxy))
                return True
            
    print("Invalid input")
    return False
    

###################################################################################################
############################################ FILTER ###############################################
###################################################################################################


def filterCommand(buildings, params, myList):
    '''
         This function will pass the apartaments from building through a filter which can be type of expense or value of all expenses, and
         for example if type = 'gas', all other expenses will be deleted, if we have a value, we will keep only the apartaments with total
         sum of expense lower then that value, myList is used here for undoCommand, we save at each step when we modify the buildings a deepcopy and place
         it to myList
         INPUT:  buildings = nested dictionary, params which contain just one paramere, params[0] = type of expense or a value, myList = list of buildings
         OUTPUT: We return True if parameters was right, else False
    '''

    if(len(params) == 1):
        
        if checkExpense(params[0]):
            schimba = 0
            myList.append(copy.deepcopy(buildings))
            
            for expense in ['water', 'heating', 'electricity', 'gas', 'other']:
                if expense != params[0]:
                    for i in buildings.keys():
                        if expense in buildings[i]:
                            schimba = 1
                            del buildings[i][expense]
                            
            if schimba == 0:
                myList.pop()
            return True;
        
        elif checkDigits(params[0]):
            
            listOfApartaments = []
            myList.append(copy.deepcopy(buildings))
            
            for i in buildings.keys():
                sumApartament = totalSumApartament(buildings, i)
                if sumApartament >= int(params[0]):
                    listOfApartaments.append(i)

            if len(listOfApartaments) == 0:
                myList.pop()
                
            for i in listOfApartaments:
                del buildings[i]

            return True
    
    print("Invalid input")
    return False



###################################################################################################
############################################ UNDO #################################################
###################################################################################################


def undoCommand(buildings, myList):
    '''
         This function will set the buildings to last element from myList and delete the last element from myList, in this way we are able to make undo operation
         INPUT:  buildings = nested dictionary, myList = list of buildings
         OUTPUT: We return buildings which is the nested dictionary updated with the last element from myList,
         if myList is empty we print "Invalid Input" and return buildings without any changes
    '''
    
    if len(myList) > 0:
        buildings = copy.deepcopy(myList[-1])
        myList.pop()
        return buildings

    print("Unavailable command")
    return buildings



    
