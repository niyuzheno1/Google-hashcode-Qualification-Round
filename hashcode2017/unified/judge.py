import sys
import argparse


def judge_main():
    sys.stdin = open("input.txt")
    V,E,R,C,X = list(map(int,input().split()))
    S = list(map(int,input().split()))
    sinfo = [[] for i in range(C)]
    Endpoint_D =[]
    for i in range(E):
        tmp = { "LD" : 0,  "server" : {} , "requests" : {} }
        tmp1 = list(map(int,input().split()))
        tmp["LD"] = tmp1[0]
        for j in range(tmp1[1]):
            tmp2 =  list(map(int,input().split()))
            tmp["server"][tmp2[0]] = tmp2[1]
        Endpoint_D.append(tmp)
    
    for i in range(R):
        tmp1 = list(map(int,input().split()))
        if tmp1[0] not in Endpoint_D[tmp1[1]]["requests"]:
            Endpoint_D[tmp1[1]]["requests"][tmp1[0]] = 0
        Endpoint_D[tmp1[1]]["requests"][tmp1[0]] += tmp1[2]
    sys.stdin = open("output.txt")
    N = int(input())
    for i in range(N):
        tmp1 = list(map(int,input().split()))
        for j in range(1, len(tmp1)):
            x = tmp1[j]
            sinfo[tmp1[0]].append(x)
    for i in range(C):
        u = sum(list(map(lambda x: S[x], sinfo[i])))
        if u > X:
            print(i)
            print("Invalid Output")
            return -1
    sum1 = 0
    sum2 = 0
    for i in range(E):
        LD = Endpoint_D[i]["LD"]
        for req in Endpoint_D[i]["requests"]:
            L = LD
            for sev in Endpoint_D[i]["server"]:
                if req in sinfo[sev]:
                    L = min(L,Endpoint_D[i]["server"][sev])
            sum1 += (LD-L)*Endpoint_D[i]["requests"][req]
            sum2 += Endpoint_D[i]["requests"][req]
    print(sum1/sum2 * 1000)


if __name__ == "__main__":
    judge_main()