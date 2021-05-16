import matplotlib.pyplot as plt
import networkx as nx
from itertools import combinations
from random import random, choice


def ER(n, p):
    E = []
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            if random() > p:
                continue
            E.append([i,j])
    return E

def generate(E,n, m):
    Edges = { x: [] for x in range(n)}
    paths = []
    for i in range(len(E)):
        Edges[E[i][0]].append(E[i][1])
    for _ in range(m):
        x = int((n+1)*random())
        x = x % n
        a = [x]
        first = 0
        while True:
            x = choice(Edges[x])
            if first != 0 and random() < 0.2:
                break
            a.append(x)
            first = first + 1
        paths.append(a)
    return paths
    #print(paths)

D,I,S,V,F = choice(range(1,100)), 0, 0, 4, choice(range(1,1000))
n = 10
p = 0.4
m = V
E = ER(n, p)
paths = generate(E,n, m)
label = 1
tmp = {}
I = n
S = len(E)
print(D,I,S,V,F)
for i in range(len(E)):
    l= choice(range(1, 100))
    print(E[i][0], E[i][1], label, l)
    tmp[(E[i][0], E[i][1])] = label 
    label = label + 1

le = len(paths)
for i in range(le):
    pathsd = []
    for j in range(len(paths[i])-1):
        pathsd.append(tmp[(paths[i][j],paths[i][j+1])])
    ap = " ".join(list(map(str,pathsd)))
    print(len(pathsd), ap)