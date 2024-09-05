import sys

def createEdges(a): #resused most of this function from hw2 for reading in file

    edges = {}
    # added allNodes which makes sure nodes that aren't actually in the graph
    # aren't accidentally included later on
    allNodes = []
    for line in a:
        line = line.strip('\t\n\r')
        temp = line.split(',')
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

        if u not in allNodes:
            allNodes.append(u)
        if v not in allNodes:
            allNodes.append(v)

    return (edges, allNodes)

# creates a G where each node knows what points to it
def create(edges):
    G = {}

    for key in edges: #for each node with outgoing arrows
        for item in edges[key]: # for each node with an incoming arrow
            if item in G:
                temp = G[item]
                temp.append(key)
                G[item] = temp
            else:
                temp = []
                temp.append(key)
                G[item] = temp
    return G

def recurse(G, output, allNodes, edges):
    if allNodes: # if node exists
        for v in allNodes: # for each node
            if v not in G and v not in output: # if node has no incoming
                if v in edges: # if node has outgoing arrows
                    edges.pop(v) # update edges
                    G = create(edges) # remake G from the updated edges
                output.append(v)
                allNodes.remove(v) # don't look at that number anymore
                recurse(G, output, allNodes, edges)
    else:
        for a in output: # print the output
            print(a, end = " ")

def top_order():
    F = open(sys.argv[1], "r")
    a = F.readlines()
    (edges, allNodes) = createEdges(a)
    allNodes.sort() # put the nodes in order so you always take smallest num

    G = create(edges)

    recurse(G, [], allNodes, edges)

sys.setrecursionlimit(5000) # allows program to recurse a lot
top_order() #begin the program
