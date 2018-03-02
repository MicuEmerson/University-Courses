from operations import *

buildings = {
             1:{'water': 1, 'heating': 100},
             2:{'gas': 300, 'other': 10},
             3:{'heating': 100, 'other': 20},
             4:{'electricity':75, 'heating': 200},
             5:{'water':50, 'electricity':20, 'other':100},
             6:{'water':100, 'gas':25},
             7:{'heating':95, 'electricity':300, 'other':50},
             8:{'other':1000},
             9:{'electricity':75, 'heating': 200, 'other': 50},
             10:{'water':10, 'heating':100, 'electricity':150, 'other':300}
             }


def testAddCommand():
    assert addCommand(buildings, ['10', 'water', '100'], []) == True
    assert addCommand(buildings, ['10', 'water', '100', 'abc'], []) == False
    assert addCommand(buildings, ['100000', 'other', '9999999'], []) == True 
 
def testRemoveApartamentCommand():
    assert remove(buildings, 10, []) == True
    assert remove(buildings, 100, []) == False
    assert remove(buildings, 1, []) == True

    
def testRemoveExpenseCommand():
    assert removeExpense(buildings, 'water', [])
    assert removeExpense(buildings, 'gas', [])
    assert removeExpense(buildings, 'electricity', [])
    

def testReplaceCommand():
    assert addCommand(buildings, ['10', 'water', '100'], []) == True
    assert addCommand(buildings, ['10', 'water', '100', 'abc'], []) == False
    assert addCommand(buildings, ['1234', 'other', '467'], []) == True
    

def testSumCommand():
    assert sumCommand(buildings, ['gas']) == 325
    assert sumCommand(buildings, ['water']) == 161
    assert sumCommand(buildings, ['other']) == 1530


def testTotalSumApartamentCommand():
    assert totalSumApartament(buildings, 10) == 560
    assert totalSumApartament(buildings, 3) == 120
    assert totalSumApartament(buildings, 5) == 170
    
    
def testMaxCommand():
    assert maxCommand(buildings, ['10','100']) == False
    assert maxCommand(buildings, ['10']) == True
    assert maxCommand(buildings, ['112']) == False
    assert maxCommand(buildings, ['5']) == True

def testFilterCommand():
    dim = len(buildings)
    filterCommand(buildings, ['1000'], [])
    assert dim == 9
    assert filterCommand(buildings, ['aaa', '12'], []) == False
    assert filterCommand(buildings, ['500'], []) == True

          
  
def testAll():
    #testAddCommand()
    #testRemoveApartamentCommand()
    #testRemoveExpenseCommand()
    #testReplaceCommand()
    #testSumCommand()
    #testTotalSumApartamentCommand()
    #testMaxCommand()
    #testFilterCommand()
    #testUndoCommand()


testAll()
