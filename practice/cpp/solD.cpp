#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <intrin.h>
#include <algorithm>
#include <set>
#define __builtin_popcount __popcnt
using namespace std;
typedef struct _pizza{
    int idx;
    vector<int> ing;
}pizza;
typedef struct _output_str{
    int num;
    vector<int> v;
}output_str;
vector<output_str> outs;
typedef struct _g2{
    int u,v;
}g2;
typedef struct _4pa{
    int chara;
    vector<int> v;
}pa4;
vector<pa4> P4;
int tot;
#define MAXB 1<<11
vector<int> G[MAXB];
vector<g2> G2[MAXB];
#define MAXN 100010
vector<int> p[MAXN];
bool vis[MAXN];
vector<pizza> piz;
int n;
int t2,t3,t4;

void addans4(int u, int v, int w, int x){
    output_str tmp;
    --t4;
    u = piz[u].idx; v = piz[v].idx; w = piz[w].idx; x = piz[x].idx;
    tmp.num=4; tmp.v.push_back(u); tmp.v.push_back(v); tmp.v.push_back(w); tmp.v.push_back(x);
    outs.push_back(tmp);
}
void addans3(int u, int v, int w){
    output_str tmp;
    --t3;
    u = piz[u].idx; v = piz[v].idx; w = piz[w].idx; 
    tmp.num=3; tmp.v.push_back(u); tmp.v.push_back(v); tmp.v.push_back(w); 
    outs.push_back(tmp);
}
void addans2(int u, int v){
    output_str tmp;
    --t2;
    u = piz[u].idx; v = piz[v].idx;  
    tmp.num=2; tmp.v.push_back(u); tmp.v.push_back(v); 
    outs.push_back(tmp);
}
void rep(){
    vector<int> goodpiz;
    int cur = 0;
    for(int i = 0 ; i < 10; ++i){
        while(cur < n && vis[cur]){
            cur = cur + 1;
        }
        if(cur >= n) break;
        goodpiz.push_back(cur);
        cur = cur + 1;
    }
    P4.clear();
    if(goodpiz.size() == 0) return;
    #define restriction goodpiz.size() 
    for(int ki  = 0; ki < restriction; ++ki)
        for(int kj  = ki+1; kj < restriction; ++kj)
        {
            for(int kk  = kj+1; kk < restriction; ++kk){
                
                for(int kl  = kk+1; kl < restriction; ++kl){
                    int i = goodpiz[ki];
                    int j = goodpiz[kj];
                    int k = goodpiz[kk];
                    int l = goodpiz[kl];
                    set<int> cset;
                    pa4 tmp;
                    for(auto & x : piz[i].ing) cset.insert(x);
                    for(auto & x : piz[j].ing) cset.insert(x);
                    for(auto & x : piz[k].ing) cset.insert(x);
                    for(auto & x : piz[l].ing) cset.insert(x);
                    tmp.chara = cset.size();
                    tmp.v.push_back(i);
                    tmp.v.push_back(j);
                    tmp.v.push_back(k);
                    tmp.v.push_back(l);
                    P4.push_back(tmp);
                }
            }
        }
    sort(P4.begin(), P4.end(), [] (const pa4 & lhs,const pa4 & rhs) { return lhs.chara > rhs.chara;});
    vis[P4[0].v[0]] = vis[P4[0].v[1]] = vis[P4[0].v[2]] = vis[P4[0].v[3]] = 1; 
    addans4(P4[0].v[0],P4[0].v[1],P4[0].v[2],P4[0].v[3]);
}
void rep2(){
    vector<int> goodpiz;
    int cur = 0;
    for(int i = 0 ; i < 10; ++i){
        while(cur < n && vis[cur]){
            cur = cur + 1;
        }
        if(cur >= n) break;
        goodpiz.push_back(cur);
        cur = cur + 1;
    }
    P4.clear();
    if(goodpiz.size() == 0) return;
    #define restriction goodpiz.size() 
    for(int ki  = 0; ki < restriction; ++ki)
        for(int kj  = ki+1; kj < restriction; ++kj)
        {
            for(int kk  = kj+1; kk < restriction; ++kk){
                
                {
                    int i = goodpiz[ki];
                    int j = goodpiz[kj];
                    int k = goodpiz[kk];
                    set<int> cset;
                    pa4 tmp;
                    for(auto & x : piz[i].ing) cset.insert(x);
                    for(auto & x : piz[j].ing) cset.insert(x);
                    for(auto & x : piz[k].ing) cset.insert(x);
                    tmp.chara = cset.size();
                    tmp.v.push_back(i);
                    tmp.v.push_back(j);
                    tmp.v.push_back(k);
                    P4.push_back(tmp);
                }
            }
        }
    sort(P4.begin(), P4.end(), [] (const pa4 & lhs,const pa4 & rhs) { return lhs.chara > rhs.chara;});
    vis[P4[0].v[0]] = vis[P4[0].v[1]] = vis[P4[0].v[2]] = 1; 
    addans3(P4[0].v[0],P4[0].v[1],P4[0].v[2]);
}
void rep3(){
    vector<int> goodpiz;
    int cur = 0;
    for(int i = 0 ; i < 10; ++i){
        while(cur < n && vis[cur]){
            cur = cur + 1;
        }
        if(cur >= n) break;
        goodpiz.push_back(cur);
        cur = cur + 1;
    }
    P4.clear();
    if(goodpiz.size() == 0) return;
    #define restriction goodpiz.size() 
    for(int ki  = 0; ki < restriction; ++ki)
        for(int kj  = ki+1; kj < restriction; ++kj)
        {
                {
                    int i = goodpiz[ki];
                    int j = goodpiz[kj];
                    set<int> cset;
                    pa4 tmp;
                    for(auto & x : piz[i].ing) cset.insert(x);
                    for(auto & x : piz[j].ing) cset.insert(x);
                    tmp.chara = cset.size();
                    tmp.v.push_back(i);
                    tmp.v.push_back(j);
                    P4.push_back(tmp);
                }
            }
        
    sort(P4.begin(), P4.end(), [] (const pa4 & lhs,const pa4 & rhs) { return lhs.chara > rhs.chara;});
    vis[P4[0].v[0]] = vis[P4[0].v[1]] = 1; 
    addans2(P4[0].v[0],P4[0].v[1]);
}
void write_output(output_str & x){
    cout << x.num << " ";
    for(auto & y : x.v){
        cout << y << " ";
    }
    cout << endl;
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
    if(ret <= 10){
        cout << 0 << endl;
        return 0;
    }
    piz.resize(n);
    for(int i = 0; i < n; ++i)
    {
        piz[i].idx = i;
        for(int j = 0; j < p[i].size(); ++j)
            piz[i].ing.push_back(p[i][j]);
    }
    sort(piz.begin(), piz.end(), [] (const pizza & lhs, const pizza & rhs){ return lhs.ing.size() > rhs.ing.size(); });
    int cutoff = 0;
    for(int i = 0 ; i < n; ++i){
        if(piz[i].ing.size() < 200){
            cutoff = i;
            break;
        }
    }
    for(int i = 0; i < 50000; ++i)
    {
        rep();
        if(t4 <= 0 || P4.size() == 0){
            break;
        }
    }
    for(int i = 0; i < 50000; ++i)
    {
        rep2();
        if(t3 <= 0 || P4.size() == 0){
            break;
        }
    }
    for(int i = 0; i < 50000; ++i)
    {
        rep3();
        if(t2 <= 0 || P4.size() == 0){
            break;
        }
    }
    cout << outs.size() << endl;
    for(int i = 0; i < outs.size(); ++i){
        write_output(outs[i]);
    }
    
    return 0;
}