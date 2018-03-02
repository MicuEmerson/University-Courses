from operations import *
import copy

def helpCommand():
    print("Valid commands:")
    print("\t add <apartment> <type> <amount>") 
    print("\t remove <apartment>") 
    print("\t remove <start apartment> <end apartment>") 
    print("\t remove <type>")
    print("\t replace <apartment> <type> <amount>")
    print("\t list")
    print("\t list <apartment>")
    print("\t list [ < | = | > ] <amount>")
    print("\t sum <type>")
    print("\t max <apartment>") 
    print("\t sort apartment")
    print("\t sort type")
    print("\t filter <type>")
    print("\t filter <value>")
    print("\t undo")
    print("\t help")
    print("\t exit")
    

def readCommand():
       cmd = input("command: ")

       if cmd.find(" ") == -1:
              command = cmd
              params = ""
       else:
              command = cmd[0:cmd.find(" ")]

              params = cmd[cmd.find(" ")+1:]
              params = params.split(" ")
              for i in range(0, len(params)):
                     params[i] = params[i].strip()
                     
                     
       return (command, params)
              
       
def main():
    
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
    myList = []
    while True:
       
           cmd = readCommand()
           command = cmd[0]
           params = cmd[1]
           
           if command == 'add':
                  addCommand(buildings, params, myList)
           elif command == 'remove':
                  removeCommand(buildings, params, myList)
           elif command == 'replace':
                  replaceCommand(buildings, params, myList)
           elif command == 'list':
                  listCommand(buildings, params)
           elif command == 'sum':
                  print(sumCommand(buildings, params))
           elif command == 'max':
                  maxCommand(buildings, params)
           elif command == 'sort':
                  sortCommand(buildings, params)
           elif command == 'filter':
                  filterCommand(buildings, params, myList)
           elif command == 'undo':
                 buildings =  undoCommand(buildings, myList)
           elif command == 'help':
                  helpCommand()
           elif command == 'exit':
                  break;
           else:
                  print("Invalid input")
                    
                  
main()
















			
