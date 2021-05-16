import sys
import argparse


def main():
    sys.stdin = open("input.txt")
    n,t2,t3,t4 = list(map(int,input().split()))
    a = []
    for i in range(n):
        a.append(input().split())
    sys.stdin = open("output.txt")
    m = int(input())
    scores = 0
    for i in range(0,m):
        b = list(map(int,input().split()))
        s = set()
        for j in range(1,b[0]+1):
            for k in range(1,int(a[b[j]][0])+1):
                s.add(a[b[j]][k])
        scores += len(s)**2

    
    print(scores)
    

if __name__ == "__main__":
    main()