#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int D, I, S, V, F;
#define MAXN 100010
typedef struct _streets{
    int E;
    string name;
    int L;
}street;
typedef struct _schedule{
    int D;
    string name;
}schedule;
typedef struct _scheduling{
    int l;
    int r;
    string name;
}scheduling;
map<string,int> validist[MAXN];

vector<street> G[MAXN];
map<string,int> demand;
map<string,int> toEdge; 
map<string,int> endEdge; 
map<string,int> duration; 
map<string,int> dur2[MAXN]; 
int validin[MAXN];
int degin[MAXN], degout[MAXN];
vector<schedule> sched[MAXN];
vector<string> vehi[MAXN];
void output(){
    int cnt = 0;
    for(int i = 0; i < I; ++i){
        if(sched[i].size() == 0) continue;
        ++cnt;
    }
    cout << cnt << endl;
    for(int i = 0; i < I; ++i){
        if(sched[i].size() == 0) continue;
        cout << i << endl;
        cout << sched[i].size() << endl;
        for(auto & x : sched[i]){
            cout << x.name << " " << x.D << endl;
        }
    }
}

int main()
{
    srand(time(0));
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> D >> I >> S >> V >> F;
    for(int i = 0; i < S; ++i){
        int B;
        street tmp;
        cin >> B >> tmp.E >> tmp.name >> tmp.L;
        toEdge[tmp.name] = B;
        endEdge[tmp.name] = tmp.E;
        ++degin[tmp.E];
        duration[tmp.name] = tmp.L;
        ++degout[B];
    }
    for(int i = 0; i < V; ++i){
        int P; cin >> P;
        int TL = 0;
        while(P--){
            string s; cin >> s;vehi[i].push_back(s);
            TL += duration[s];
        }
        if(TL > D){
            vehi[i].clear();
        }
    }
    sort(vehi, vehi + V, [] (const vector<string> & lhs, const vector<string> & rhs) {return lhs.size() < rhs.size();} );
    for(int i = 0; i < V; ++i){
        int TL = 0;
        for(int j = 0; j < vehi[i].size(); ++ j){
            auto s = vehi[i][j];
            TL += duration[s];
            if(rand()% 2 == 0) continue;
            dur2[endEdge[s]][s] = max(dur2[endEdge[s]][s],TL);
            ++demand[s];
        }
    }
    for(int i = 0; i < S; ++i){
        if(dur2[i].size() == 0) continue;
        vector<pair<int,string>> ps;
        int sz = 0;
        for(auto & x: dur2[i]){
            ps.push_back(make_pair(x.second, x.first));
            ++sz;
        }
        sort(ps.begin(),ps.end());
        vector<scheduling> vs;
        vs.resize(sz);
        for(int j = 0; j < sz; ++j){
            auto & x = vs[j];
            x.l = x.r = 0;
            x.name = ps[j].second;
        }
        vs[0].r = max(vs[0].r, ps[0].first + demand[ps[0].second]);
        vs[0].r = min(vs[0].r,D);
        for(int j = 1; j < sz; ++j){
            vs[j].l = vs[j-1].r;
            vs[j].l = max(vs[j].l, ps[j].first);
            vs[j].r = min(D,vs[j].l+demand[ps[j].second]);
        }
        for(int j = 0; j < sz; ++j){
            schedule x;
            if(vs[j].r <= vs[j].l) break;
            x.D = vs[j].r-vs[j].l;
            x.name = vs[j].name;
            sched[i].push_back(x);
        }
    }
    output();
    return 0;
}