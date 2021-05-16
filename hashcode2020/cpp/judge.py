import sys
import argparse


def judge_main():
    sys.stdin = open("input.txt")
    B,L,D = list(map(int,input().split())) # book,libraries, days
    S = list(map(int,input().split())) #scores
    lib = []
    for i in range(L):
        n,t,m = list(map(int,input().split()))
        a = list(map(int,input().split()))
        lib.append([n,t,m, *a])
    sys.stdin = open("output.txt")
    A = int(input())
    curday = -1
    bookset = set()
    for i in range(A):
        Y, K = list(map(int,input().split()))
        k = list(map(int,input().split()))
        curday += lib[Y][1]
        j = 0
        sday = curday + 1
        while j < K and sday < D:
            for m in range(lib[Y][2]):
                bookset.add(k[j])
                j = j + 1
                if j >= K:
                    break
            sday = sday + 1
    total = 0
    for x in bookset:
        total += S[x]
    print(total)
    return total


if __name__ == "__main__":
    judge_main()