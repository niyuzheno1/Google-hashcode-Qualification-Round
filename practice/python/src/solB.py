import sys
import argparse


def main():
    sys.stdout = open("output.txt", "w")
    n,t2,t3,t4 = list(map(int,input().split()))
    t = [t2,t3,t4]
    pt = [2, 3, 4]
    a = []
    la = []
    sa = []
    for i in range(n):
        u = input().split()
        la.append(int(u[0]))
        u.pop(0)
        a.append(set(u))
    
    total = 0
    cur = 0
    ans = []
    for k in range(0,3):
        for i in range(t[k]):
            ba = []
            for j in range(0,pt[k]):
                ba.append(cur)  
                cur = cur + 1
                if cur >= n:
                    break
            if cur > n:
                break
            if len(ba) < 2:
                break
            ans.append(ba)
            if cur == n:
                break
    print(len(ans))
    for i in range(len(ans)):
        print(len(ans[i]), end =" ")
        print(" ".join(list(map(str,ans[i]))))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()