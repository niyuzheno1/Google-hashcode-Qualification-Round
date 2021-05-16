#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
typedef long long ll;
int B,L,D;
#define MAXN 1010000
int S[MAXN];
int SP[MAXN];
typedef struct _lib{
    int id;
    int m;
    int t;
    vector<int> b;
    int maxscores;
    int selected;
}library;

typedef struct _book_type{
    int oid;
}book_type;

library lib[MAXN];
bool operator < (library & x, library & y){
    return x.maxscores >  y.maxscores;
}
bool operator < (book_type & x, book_type & y){
    return S[x.oid] > S[y.oid];
}
book_type tmp[MAXN];

int simulate(vector<int> & a, int d, int curday, int deadline){
    int j = 0;
    int sday = curday + 1;
    int n = a.size();
    int ret = 0;
    while(j < n && sday < deadline){
        for(int m = 0; m < d; ++m){
            ret += S[a[j]];
            assert(ret >= 0);
            ++j;
            if(j >= n)
                break;
        }
        sday = sday + 1;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    scanf("%d%d%d",&B,&L,&D);
    for(int i = 0; i < B; ++i){
        scanf("%d", &S[i]);
        SP[i] = S[i];
    }
    for(int i = 0; i < L; ++i){
        int n; scanf("%d%d%d", &n, &lib[i].t, &lib[i].m);
        lib[i].id = i;
        for(int j = 0; j < n; ++j){
            int x;
            scanf("%d",&x);
            lib[i].b.push_back(x);
        }
        lib[i].selected = 1;
        sort(lib[i].b.begin(), lib[i].b.end(), [] (const int & lhs, const int & rhs){ return S[lhs] > S[rhs];});
        lib[i].maxscores = simulate(lib[i].b, lib[i].m, lib[i].t-1, D);
    }
    int curtime = -1;
    sort(lib, lib+L);
    #define heuristic (i+1000)
    for(int i = 0; i < L; ++i){
        sort(lib+i, lib+heuristic);
        curtime += lib[i].t;
        int n = lib[i].b.size();
        for(int j = 0; j < n; ++j){
            S[lib[i].b[j]] = 0;
        }
        for(int j = i+1; j < heuristic+1; ++j){
            sort(lib[j].b.begin(), lib[j].b.end(), [] (const int & lhs, const int & rhs){ return S[lhs] > S[rhs];});
            lib[j].maxscores = simulate(lib[j].b, lib[j].m, curtime+lib[j].t, D);
        }
    }
    for(int i = 0; i < B; ++i){
        S[i]=SP[i];
    }
    printf("%d\n", L);
    for(int i = 0; i < L; ++i){
        printf("%d %d\n", lib[i].id, lib[i].b.size());
        int cur = 0;
        for(auto & x: lib[i].b){
             tmp[cur].oid = x;
             ++cur;
        }
        sort(tmp,tmp+cur);
        for(int i = 0; i < cur; ++i){
             printf("%d ",tmp[i].oid);
             S[tmp[i].oid] = 0;
        }
        
        printf("\n");
    }
    return 0;
}