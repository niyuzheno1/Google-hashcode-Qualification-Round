import sys
import argparse


def judge_main():
    sys.stdin = open("input.txt")
    n = int(input())
    a = []
    for i in range(n):
        a.append(input().split())
    sys.stdin = open("output.txt")
    m = int(input())
    scores = 0
    allset = []
    for i in range(m):
        t = list(map(int,input().split()))
        if len(t) == 1:
            if a[t[0]][0] != 'H':
                print(-1)
                return -1
            s = set()
            for j in range(2, 2+int(a[t[0]][1])):
                s.add(a[t[0]][j])
            allset.append(s)
        if len(t) == 2:
            if a[t[0]][0] != 'V' or a[t[1]][0] != 'V' :
                print(-1)
                return -1
            s = set()
            for j in range(2, 2+int(a[t[0]][1])):
                s.add(a[t[0]][j])
            for j in range(2, 2+int(a[t[1]][1])):
                s.add(a[t[1]][j])
            allset.append(s)
        if len(t) >= 3:
            print(-1)
            return -1
    for i in range(m-1):
        i1 = allset[i].intersection(allset[i+1])
        if len(i1) == 0:
            print(i)
            print(-1)
            return -1
        s1 = allset[i].difference(allset[i+1])
        s2 = allset[i+1].difference(allset[i])
        scores += min(len(i1),len(s1),len(s2))
    print(scores)
    return scores

if __name__ == "__main__":
    judge_main()