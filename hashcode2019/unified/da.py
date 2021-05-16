import sys
import argparse


def judge_main():
    sys.stdin = open("input.txt")
    sys.stdout = open("pro.txt", "w")
    n = int(input())
    a = []
    for i in range(n):
        u = input().split()
        v = []
        m = int(u[1])
        for j in range(2, 2+m):
            v.append(int(u[j]))
        a.append(v)
    p = []
    for i in range(n):
        p.append([min(a[i]), max(a[i])])
    p = sorted(p)
    for i in range(n):
        print(p[i][0],p[i][1])
    

    

if __name__ == "__main__":
    judge_main()