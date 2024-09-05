from __future__ import print_function
import sys

def createEdges(a):

    edges = {}
    for line in a:
        line = line.strip('\t\n\r')
        temp = line.split(', ')
        u = int(temp[0])
        v = int(temp[1])
        if u in edges:
            temp = edges[u]
            temp.append(v)
            edges[u] = temp
        else:
            temp = []
            temp.append(v)
            edges[u] = temp

    return edges

def finalPrint(list):
    print("\n")
    for a in list:
        print(a, end = " ")
    print("\n")
