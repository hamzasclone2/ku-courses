import sys

F = open(sys.argv[1], "r")
a = F.readlines()
edges = []
for line in a:
    line = line.strip('\r\n ')
    line = line.split(' ')
    edges.append(line)

for i in range(len(edges)):
    edges[i] = [int(x) for x in edges[i]]

weights = {}
first = 0
for i in edges:
    second = 0
    for j in i:
        if j != 0:
            if j in weights:
                temp = weights[j]
                temp.append([first, second])
                weights[j] = temp
            else:
                temp = []
                temp.append([first, second])
                weights[j] = temp
        second += 1
    first += 1

numSet = 1
sets = [0] * len(edges)
for i in weights:
    for j in weights[i]:
        printBool = True
        first = j[0]
        second = j[1]
        if sets[first] == 0 and sets[second] == 0:
            sets[first] = numSet
            sets[second] = numSet
            numSet += 1
        elif sets[first] == 0 and sets[second] != 0:
            sets[first] = sets[second]
        elif sets[first] != 0 and sets[second] == 0:
            sets[second] = sets[first]
        elif sets[first] == sets[second]:
            printBool = False
        elif sets[first] != 0 and sets[second] != 0:
            val = sets[first]
            val2 = sets[second]
            for i in range(len(sets)):
                if sets[i] == val or sets[i] == val2:
                    sets[i] = numSet
            numSet+=1
        if printBool:
            #print(first, second)
            print(first, end = " ")
            print(second,end = "\r\n")
