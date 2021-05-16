#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>
#include <algorithm>
#include <set>

using namespace std;
#define MAXN 850000
vector<int> a[MAXN];
vector<int> G[MAXN];
typedef struct _example{
    int xid;
    vector<int> b;
}example;
example b[MAXN];
map<int,int> ocr;
int n;
void build_graph(){
    for(int i = 0; i < n; ++i){
        for(auto & x : b[i].b){
            a[x].push_back(b[i].xid);
        }
    }
}

vector<int> feasible_solution;
vector<int> curans; 
int eval;
bool visited[MAXN];
int numsol = 0;
int timelimits = 0;
void dfs(int vx){
    visited[vx] = 1;
    bool flag = false;
    for(auto & x : b[vx].b){
        for(auto & y: a[x]){
            if(!visited[y]){
                flag = true;
                curans.push_back(y);
                if(feasible_solution.size() > 56000) return;
                dfs(y);
                if(feasible_solution.size() > 56000) return;
                curans.pop_back();
            }
            if(feasible_solution.size() > 56000) return;
        }
        if(feasible_solution.size() > 56000) return;
    }
    visited[vx] = 0;
    if(!flag){
        if(feasible_solution.size() < curans.size()){
            ++numsol;
            if(feasible_solution.size() > 56000) return;
            feasible_solution = curans;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    int maxm = 0;
    for(int i = 0; i < n; ++i){
        int m;
        string v; cin >> v >> m;
        
        for(int j = 0; j < m; ++j){
            int x; cin >> x;
            maxm = max(maxm,x);
            a[i].push_back(x);
            ++ocr[x];
        }
    }
    int sz = 0;
    for(int i = 0; i < n; ++i){
        for(auto & x : a[i]){
            if(ocr[x] != 1){
                b[i].b.push_back(x);
                ++sz;
            }
        }
        b[i].xid = i;
    }
    sort(b, b+n, [] (const example & lhs, const example & rhs) { return lhs.b.size() > rhs.b.size();} );
    for(int i = 0; i <= maxm; ++i) a[i].clear();
    build_graph();
    curans.push_back(b[0].xid);
    int ubegin = b[0].xid;
    sort(b, b+n, [] (const example & lhs, const example & rhs) { return lhs.xid < rhs.xid;} );
    dfs(ubegin);
    cout << feasible_solution.size() << endl;
    for(int i = 0; i < feasible_solution.size(); ++i){
        cout << feasible_solution[i] << endl;
    }
    return 0;
}