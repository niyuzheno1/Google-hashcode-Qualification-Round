#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int B,L,D;
#define MAXN 1000010
int S[MAXN];
typedef struct _lib{
    int id;
    int m;
    int t;
    set<int> b;
    int maxscores;
}library;

typedef struct _book_type{
    int oid;
}book_type;

library lib[MAXN];
bool operator < (library & x, library & y){
    return x.t < y.t;
}
bool operator < (book_type & x, book_type & y){
    return S[x.oid] > S[y.oid];
}
book_type tmp[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    scanf("%d%d%d",&B,&L,&D);
    for(int i = 0; i < B; ++i){
        scanf("%d", &S[i]);
    }
    for(int i = 0; i < L; ++i){
        int n; scanf("%d%d%d", &n, &lib[i].t, &lib[i].m);
        lib[i].id = i;
        for(int j = 0; j < n; ++j){
            int x;
            scanf("%d",&x);
            lib[i].b.insert(x);
        }
        for(auto & x : lib[i].b){
            lib[i].maxscores += S[x];
        }
    }
    sort(lib, lib+L);
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