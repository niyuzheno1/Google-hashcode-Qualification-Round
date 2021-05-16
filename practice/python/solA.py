import sys
import argparse


def main():
    n,t2,t3,t4 = list(map(int,input().split()))
    a = []
    la = []
    sa = []
    for i in range(n):
        u = input().split()
        la.append(int(u[0]))
        u.pop(0)
        a.append(set(u))
    
    #{"num" : 0 , "ing" : set}
    teams = []
    for i in range(t2):
        teams.append({"num" : 2 , "ing" : set(), "pnum" :[]})
    for i in range(t3):
        teams.append({"num" : 3 , "ing" : set(), "pnum" :[]})
    for i in range(t4):
        teams.append({"num" : 4 , "ing" : set(), "pnum" :[]})
    m = len(teams)
    # for i in range(n):
    #     besti = 0
    #     for j in range(m):
    #         if teams[j]["num"] == len(teams[j]["pnum"] ):
    #             continue
    #         if len(teams[j]["ing"].intersection(a[i])) < len(teams[besti]["ing"].intersection(a[i])):
    #             besti = j
    #     if teams[besti]["num"] == len(teams[besti]["pnum"] ):
    #         continue
    #     teams[besti]["pnum"].append(i)
    #     teams[besti]["ing"] = teams[besti]["ing"].union(a[i])
    u = set([i for i in range(n)])
    for i in range(m): #fixing every team and then add pizza
        for j in range(teams[i]["num"]):
            bestid = -1
            for x in u:
                if bestid == -1:
                    bestid = x
                if len(teams[i]["ing"].intersection(a[x])) < len(teams[i]["ing"].intersection(a[bestid])):
                    bestid = x
            if bestid == -1:
                continue
            teams[i]["pnum"].append(bestid)
            u.remove(bestid)
    totals = 0
    for i in range(m):
        if len(teams[i]["pnum"]) == (teams[i]["num"]):
            totals = totals + 1
    print(totals)
    for i in range(m):
        output = []
        if len(teams[i]["pnum"]) == (teams[i]["num"]):
            output.append(len(teams[i]["pnum"]))
            for j in range(len(teams[i]["pnum"])):
                output.append(teams[i]["pnum"][j])
            print(" ".join(list(map(str,output))))
    
            



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    sys.stdout = open("output.txt", "w")
    main()