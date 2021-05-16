#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cassert>
#include <queue>
#include <map>
using namespace std;
int B,L,D;
typedef struct _lib{
    int id;
    int m;
    int t;
    vector<int> b;
    double maxscores;
}library;
#define MAXN 1010000

library lib[MAXN];
int S[MAXN];
#define MAXN 1010000
#define SIM_TIMES 10
typedef pair<double, int> pdi;
typedef pair<pdi, int> pdii;
#define expect_val first.first
#define counts first.second
#define idx second
#define mp make_pair
priority_queue<pdii> pq[MAXN];
map<int,pdi> updates[MAXN];
vector<int> libidx;
int good[MAXN];
int maxdep;
map<int,int> MS;
void saveS(){
    MS.clear();
}
void restoreS(){
    for(auto & x : MS){
        S[x.first] = x.second;
    }
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
            if(S[a[j]] != 0) MS[a[j]] = S[a[j]];
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
int simulate2(vector<int> & libidx, int x, int cday){
    int ret = 0;
    int curday = cday;
    int u = libidx.size();
    for(int i = x; i < u; ++i){
        ret += simulate(lib[libidx[i]].b, lib[libidx[i]].m, curday+lib[libidx[i]].t, D);
        curday += lib[libidx[i]].t;
    }
    return ret;
}
pdi operator += (pdi & x, const pdi & y){
    x.first = x.first+y.first;
    x.second = x.second + y.second;
    return x;
}

double dfs(int dep, int curtime){
    if(dep >= maxdep){
        
         return 0;
    }
    if(curtime > D){
        return 0;
    }
    vector<int> tmp;
    for(int i = 0; i < L; ++i){
        if(!good[i])
            tmp.push_back(i);
    }
    bool majority_good = false;
    int ctimeaddone = curtime+1;
    for(int sim = 0; sim < SIM_TIMES; ++ sim){
        random_shuffle(tmp.begin(),tmp.end());
        saveS();
        if(updates[ctimeaddone][tmp[0]].second == -1) continue;
        double res = double(simulate2(tmp,0, curtime));
        if(abs(res) > 0.1){
            majority_good = true;
        }
        updates[ctimeaddone][tmp[0]] += mp(res, 1);
        restoreS();
    }
    if(!majority_good){
        
        return 0;
    }
    for(auto & x : updates[ctimeaddone]){
        pq[ctimeaddone].push(mp(mp(x.second.first/double(x.second.second),1),x.first));
        updates[ctimeaddone][x.first].first = 0.0;
        updates[ctimeaddone][x.first].second = 0;
    }
    double best = 0.0;
    while(!pq[ctimeaddone].empty())
    {
        auto & x = pq[ctimeaddone].top();pq[ctimeaddone].pop();
        if(updates[ctimeaddone][x.idx].second != 0){
            double newexpected = x.expect_val + updates[ctimeaddone][x.idx].first;
            newexpected /= double(x.counts+updates[ctimeaddone][x.idx].second);
            pq[ctimeaddone].push(mp(mp(newexpected,1),x.idx));
            updates[ctimeaddone][x.idx].first = 0.0;
            updates[ctimeaddone][x.idx].second = 0;
        }else{
            MS.clear();
            double cscores = simulate(lib[x.idx].b, lib[x.idx].m, curtime+lib[x.idx].t, D);
            map<int,int> tmp = MS;
            good[x.idx] = 1;
            cscores = dfs(dep+1,lib[x.idx].t+curtime)+cscores;
            best = max(best,cscores);
            good[x.idx] = 0;
            for(auto & x : tmp){
                S[x.first] = x.second;
            } 
            
            updates[ctimeaddone][x.idx].first = x.expect_val+cscores;
            updates[ctimeaddone][x.idx].second = x.counts+1;
        }
    }
    return best;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   scanf("%d%d%d",&B,&L,&D);
    for(int i = 0; i < B; ++i)
        scanf("%d", &S[i]);
    
    for(int i = 0; i < L; ++i){
        int n; scanf("%d%d%d", &n, &lib[i].t, &lib[i].m);
        lib[i].id = i;
        for(int j = 0; j < n; ++j){
            int x;
            scanf("%d",&x);
            lib[i].b.push_back(x);
        }
    }
    maxdep = L;
    dfs(0,-1);
    return 0;
}