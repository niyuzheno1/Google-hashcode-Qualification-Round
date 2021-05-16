import sys
import argparse

tx = [31, 48, 51, 63, 63, 70, 73, 76, 78, 81]
def judge_main():
    print(sum(tx))
    sys.stdin = open("input.txt")
    B,L,D = list(map(int,input().split())) # book,libraries, days
    S = list(map(int,input().split())) #scores
    print( sorted(S))
    lib = []
    times = []
    for i in range(L):
        n,t,m = list(map(int,input().split()))
        a = list(map(int,input().split()))
        lib.append([n,t,m, *a])
        ux = sum(sorted(list(map(lambda x: S[x],lib[len(lib)-1]))))
        if ux > 2703359//7:
            print("+", [n,t,m, ux, ux//t])
            times.append(t)
    print(sorted(times))
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