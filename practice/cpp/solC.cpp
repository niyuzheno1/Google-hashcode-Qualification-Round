#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <intrin.h>
#include <algorithm>
#define __builtin_popcount __popcnt
using namespace std;
typedef struct _pizza{
    int idx;
    int ing;
}pizza;
typedef struct _output_str{
    int num;
    vector<int> v;
}output_str;
vector<output_str> outs;
typedef struct _g2{
    int u,v;
}g2;
int tot;
vector<pizza> piz;
#define MAXB 1<<11
vector<int> G[MAXB];
vector<g2> G2[MAXB];
#define MAXN 100010
vector<int> p[MAXN];
bool vis[MAXN];
int n;
int t2,t3,t4;
void rebuild(){
    for(int i = 0 ; i <= MAXB; ++i){
        G[i].clear();
        G2[i].clear();
    }
    vector<int> goodidx;
    for(int i = 0 ; i < n; ++i){
        if(vis[i] == 0)
            goodidx.push_back(i);
    }
    for(int ki = 0; ki < goodidx.size(); ++ki){
        int i = goodidx[ki];
        for(int kj = 0; kj < goodidx.size(); ++ kj){
            int j = goodidx[kj];
            if(i == j){
                G[piz[i].ing].push_back(i);
                continue;
            }
            int bm = piz[i].ing | piz[j].ing;
            g2 tmp;
            tmp.u = i; tmp.v = j;
            G2[bm].push_back(tmp);
        }
    }
}
void rep(){

    rebuild();
    for(int i = MAXB; i >= 0; --i){
        if(G2[i].size() <= 0) continue;
        while(G2[i].size() > 0){
            auto & x =  G2[i].begin();
            if(vis[(*x).u] ||vis[(*x).v]){
                G2[i].erase(G2[i].begin());
                continue;
            }else{
                break;
            }
        }
        if(G2[i].size() <= 0) continue;
        
        if(t3 == 0) break;
        for(int j = 0; j < MAXB; ++j){
            if(G[j].size() <= 0) continue;
            for(int k = 0; k < G[j].size(); ++k){
                if(vis[G[j][k]] ){
                    G[j].erase(G[j].begin()+k);
                    k = k -1;
                }
            }
        }
        vector<int> goodidx; 
        for(int j = 0; j < MAXB; ++j){
            if(G[j].size() <= 0) continue;
            goodidx.push_back(j);
        }
        sort(goodidx.begin(), goodidx.end(), [&] (const int & lhs, const int & rhs){ return __builtin_popcount(lhs | i) > __builtin_popcount(rhs | i);} );
        int cur = 0;
        for(int j = 0; j < G2[i].size(); ++j){
            g2 & x = G2[i][j];
            if(t3 == 0) break;
            if(vis[x.u] || vis[x.v]){
                G2[i].erase(G2[i].begin()+j);
                j = j -1;
                continue;
            }
            vis[x.u] = 1;
            vis[x.v] = 1;
            if ( cur >= goodidx.size()){
                vis[x.v] =  vis[x.u] = 0;
                break;
            }
            while(cur < goodidx.size() ){
                if(G[goodidx[cur]].size() > 0 ){
                    if(vis[G[goodidx[cur]][0]] )
                        G[goodidx[cur]].erase(G[goodidx[cur]].begin());
                    else
                        break;
                    
                }
                else{
                    cur = cur + 1;
                }
            }
            if ( cur >= goodidx.size()) {
                vis[x.v] =  vis[x.u] = 0;
                break;
            }
            t3 = t3 - 1;
            output_str ou;
            ou.num = 3;
            ou.v.push_back(x.u);
            ou.v.push_back(x.v);
            ou.v.push_back(G[goodidx[cur]][0]);
            outs.push_back(ou);
            vis[x.u] = 1;
            vis[x.v] = 1;
            vis[G[goodidx[cur]][0]] = 1;
        }
    }
}
void rep2(){

    rebuild();
    for(int i = MAXB; i >= 0; --i){
        if(G2[i].size() <= 0) continue;
        while(G2[i].size() > 0){
            auto & x =  G2[i].begin();
            if(vis[(*x).u] ||vis[(*x).v]){
                G2[i].erase(G2[i].begin());
                continue;
            }else{
                break;
            }
        }
        
        if(t2 == 0) break;
        if(G2[i].size() <= 0) continue;
        for(int j = 0; j < G2[i].size(); ++j){
            g2 & x = G2[i][j];
            if(vis[x.u] || vis[x.v]){
                G2[i].erase(G2[i].begin()+j);
                j = j -1;
                continue;
            }
            if(t2 == 0) break;
            vis[x.u] = 1;
            vis[x.v] = 1;
            t2 = t2 - 1;
            output_str ou;
            ou.num = 2;
            ou.v.push_back(x.u);
            ou.v.push_back(x.v);
            outs.push_back(ou);
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n >> t2 >> t3 >> t4;
    int ret = -1;
    for(int i = 0 ; i < n; ++i){
        int m; cin >> m; 
        for(int j = 0; j < m; ++j){
            int s; cin >> s;
            ret = max(s,ret);
            p[i].push_back(s);
        }
    }
    if(ret > 10){
        cout << 0 << endl;
        return 0;
    }
    piz.resize(n);
    for(int i = 0; i < n; ++i)
    {
        piz[i].idx = i;
        for(int j = 0; j < p[i].size(); ++j)
            piz[i].ing |= (1<<p[i][j]);
    }
        rebuild();
    for(int i = MAXB; i >= 0; --i){
        if(G2[i].size() <= 0) continue;
        if(t4 == 0) break;
        for(int j = 0; j < MAXB; ++j){
            if(G2[j].size() <= 0) continue;
            for(int k = 0; k < G2[j].size(); ++k){
                if(vis[G2[j][k].u] || vis[G2[j][k].v]){
                    G2[j].erase(G2[j].begin()+k);
                    k = k -1;
                }
            }
        }
        vector<int> goodidx; 
        for(int j = 0; j < MAXB; ++j){
            if(G2[j].size() <= 0) continue;
            goodidx.push_back(j);
        }
        sort(goodidx.begin(), goodidx.end(), [&] (const int & lhs, const int & rhs){ return __builtin_popcount(lhs | i) > __builtin_popcount(rhs | i);} );
        int cur = 0;
        for(int j = 0; j < G2[i].size(); ++j){
            g2 & x = G2[i][j];
            if(t4 == 0) break;
            if(vis[x.u] || vis[x.v]){
                G2[i].erase(G2[i].begin()+j);
                j = j -1;
                continue;
            }
            vis[x.v] =  vis[x.u] = 1;
            if ( cur >= goodidx.size()){ 
                vis[x.v] =  vis[x.u] = 0;
                break;
            }
            
            while(cur < goodidx.size() ){
                if(G2[goodidx[cur]].size() > 0 ){
                    if(vis[G2[goodidx[cur]][0].u] || vis[G2[goodidx[cur]][0].v])
                    {
                        G2[goodidx[cur]].erase(G2[goodidx[cur]].begin());
                    }else{
                        break;
                    }
                }
                else{
                    cur = cur + 1;
                }
            }
            if ( cur >= goodidx.size()){ 
                vis[x.v] =  vis[x.u] = 0;
                break;
            }
            t4 = t4 - 1;
            output_str ou;
            ou.num = 4;
            ou.v.push_back(x.u);
            ou.v.push_back(x.v);
            ou.v.push_back(G2[goodidx[cur]][0].u);
            ou.v.push_back(G2[goodidx[cur]][0].v);
            outs.push_back(ou);
            vis[G2[goodidx[cur]][0].u] = 1;
            vis[G2[goodidx[cur]][0].v] = 1;
        }
    }
    rep();
    rep2();
    cout << outs.size() << endl;
    for(auto & x : outs){
        cout <<  x.num << " ";
        for(auto & y : x.v){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}