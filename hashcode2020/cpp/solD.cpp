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
void saveS(){
    for(int i = 0; i < B; ++i)  SP[i] = S[i];
}
void restoreS(){
    for(int i = 0; i < B; ++i)  S[i] = SP[i];
}
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
    assert(x.maxscores >= 0);
    assert(y.maxscores >= 0);
    return x.maxscores >  y.maxscores;
}

int simulate(vector<int> & a, int d, int curday, int deadline){
    sort(a.begin(), a.end(), [] (const int & lhs, const int & rhs){ return S[lhs] > S[rhs];});
    int j = 0;
    int sday = curday + 1;
    int n = a.size();
    int ret = 0;
    while(j < n && sday < deadline){
        for(int m = 0; m < d; ++m){
            ret += S[a[j]];
            S[a[j]] = 0;
            assert(ret >= 0);
            ++j;
            if(j >= n)
                break;
            
        }
        sday = sday + 1;
    }
    return ret;
}
vector<int> libidx;
int simulate2(vector<int> & libidx, int x, int cday){
    int ret = 0;
    int curday = cday;
    for(int i = x; i < L; ++i){
        ret += simulate(lib[libidx[i]].b, lib[libidx[i]].m, curday+lib[libidx[i]].t, D);
        curday += lib[libidx[i]].t;
    }
    return ret;
}
#define psort() sort(libidx.begin(), libidx.end(), [](const int & lhs, const int & rhs){ return lib[lhs].maxscores > lib[rhs].maxscores;})
int main()
{
    srand(time(NULL));
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
        saveS();
        lib[i].maxscores = simulate(lib[i].b, lib[i].m, lib[i].t-1, D);
        restoreS();
        libidx.push_back(i);
    }
    psort();
    saveS();
    lib[libidx[0]].maxscores = simulate2(0, -1);
    cout << lib[libidx[0]].maxscores << endl;
    restoreS();
    random_shuffle(libidx.begin(),libidx.begin()+1000);

    for(int i = 0; i < 50; ++i){
        random_shuffle(libidx.begin(),libidx.begin()+1000);
        saveS();
        lib[libidx[0]].maxscores = simulate2(0, -1);
        cout << lib[libidx[0]].maxscores << endl;
        restoreS();
    }
    psort();
    for(int i = 0; i < 50; ++i){
        random_shuffle(libidx.begin(),libidx.begin()+1000);
        saveS();
        lib[libidx[0]].maxscores = simulate2(0, -1);
        cout << lib[libidx[0]].maxscores << endl;
        restoreS();
    }
    return 0;
}