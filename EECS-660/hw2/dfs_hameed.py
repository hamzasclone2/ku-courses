from helper import createEdges, finalPrint
import sys

F = open(sys.argv[1], "r") 
s = F.readline()
s = s.strip('\t\n\r')
a = F.readlines()

edges = createEdges(a)
S = []
S.append(int(s))
Explored = []
while S:
    u = S.pop(0)
    if u not in Explored:
        Explored.append(u)
        if u in edges:
            edgeList = edges[u]
            count = 0
            for v in edgeList:
                S.insert(count, v)
                count += 1

finalPrint(Explored)
