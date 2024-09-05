barValues = [] #values for all user created data
barNames = [] #names for all user created data
numBars = 0 #number of bars made so far, used for looping purposes

#main program 
def program():
  print("Sideways Bar Graph Creator Thing")
  print("--------------------------------")
  
  menu()
  
#menu that continuously shows up so you can work on your graph
def menu():
  choice = 0
  while choice != 5:
    print("\nWhat would you like to do?")
    print("1) Create new data")
    print("2) Change data")
    print("3) Delete a bar")
    print("4) Generate graph")
    print("5) Exit")
    choice =  int(input(">"))
    if choice == 1:
      createData()
    elif choice == 2:
      changeData()
    elif choice == 3:
      deleteBar()
    elif choice == 4:
      print("\n")
      generateGraph()
    elif choice == 5:
      break
    else: 
      print("That's not an option, try again!\n")
    
#asks for data and stores it in the lists to be drawn later      
def createData():
  global numBars
  name = input("\nName of data (can be changed later):")
  value = float(input("Value of data (can be changed later):"))
  barNames.append(name)
  barValues.append(value)
  numBars = numBars + 1

#changes name or value of a bar one at a time  
def changeData():
  global barValues
  global barNames
  global numBars
  print("\nWhich one would you like to change? (Hit 0 to exit)")
  #prints out current data
  for x in range(0, numBars):
    print(x+1 , ") Name: " , barNames[x] , ", Value: " , barValues[x])
  choice = int(input(">"))
  index = choice
  if choice >= 1 and choice <= numBars:
    print("\n1) Change Name")
    print("2) Change Value")
    print("3) Go Back")
    choice = int(input(">"))
    if choice == 1:
      newName = input("Change name to: ")
      barNames[index - 1] = newName
    elif choice == 2:
      newValue = float(input("Change value to: "))
      #change value here
      barValues[index - 1] = newValue

#deletes whatever bar the user wants to
def deleteBar():
  global barValues
  global barNames
  global numBars
  choice = 0
  while choice < 1 or choice > numBars:
    print("\nWhich one would you like to delete? (Hit 0 to exit)")
    #prints out current data
    for x in range(0, numBars):
      print(x+1 , ") Name: " , barNames[x] , ", Value: " , barValues[x])
    choice = int(input(">"))
    if choice >= 1 and choice <= numBars:
      print("\nDeleted!\n")
      barValues.pop(choice-1)
      barNames.pop(choice-1)
      numBars -= 1
      break
    elif choice == 0:
      break
    else:
      print("That's not an option, try again!") 
  
#loop that draws each bar 
def generateGraph():
  #draws the bar itself
  for x in range(0, numBars):
    drawBar(int(barValues[x]), x)
  
  #labels the axis
  high = int(max(barValues))
  third = int(high / 3)
  twoThird = int(high * (2/3))
  #print("|", end="")
  for x in range(0, high-1):
    if x == third -1:
      print(third, end ="")
    elif x == twoThird -1:
      print(twoThird, end ="")
    else:
      print(" ", end="")
  print(high)

#draws bar based on what size length is given, width is always the same
def drawBar(size, num):
  #top line
  for x in range(0, size):
    print("=", end="")
    
  print("")
  
  #right side
  for x in range(0, 3):
    for y in range(0, size):
      print(" ", end="")
    
    #also prints out name and exact value of data here
    if x == 1:
      print("| ", barNames[num], " (", barValues[num], ")",sep="")
    else:
      print("|")
    
  #bottom line
  for x in range(0, size):
    print("=", end="")

  print("")

#heres where the program is actually being run from
program()
