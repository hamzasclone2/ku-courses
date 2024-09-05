from helper import createEdges, finalPrint
import sys

F = open(sys.argv[1], "r")
s = F.readline()
s = s.strip('\t\n\r')
a = F.readlines()

edges = createEdges(a)

discovered = []
discovered.append(int(s))
L = []
temp = []
temp.append(int(s))
L.append(temp)
i = 0
while L[i]:
    L.append([])
    for u in L[i]:
        if u in edges:
            while edges[u]:
                v = edges[u].pop(0)
                if v not in discovered:
                    discovered.append(v)
                    L[i+1].append(v)
    i+=1

finalPrint(discovered)
