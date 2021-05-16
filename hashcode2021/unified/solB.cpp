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

map<string,int> validist[MAXN];
map<int,int> len;
map<int,int> Plen;
vector<street> G[MAXN];
map<string,int> toEdge; 
map<string,int> endEdge; 
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

map<string,int> duration; 
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
        ++degout[B];
        duration[tmp.name] = tmp.L;
        if(sched[tmp.E].size() == 0){
            schedule tmp2;
            tmp2.D = D;
            tmp2.name = tmp.name;
            if(rand()% 2 == 0){
                sched[tmp.E].push_back(tmp2);
            }
        }
        
    }
    for(int i = 0; i < V; ++i){
        int P; cin >> P;
        ++len[P];
        int TL = 0;
        while(P--){
            string s; cin >> s;vehi[i].push_back(s);
            ++validin[endEdge[s]];
            ++validist[endEdge[s]][s];
            TL += duration[s];
        }
        ++Plen[TL];
    }
    cout << "deg dist" << endl;
    cout << "in deg" << endl;
    for(int i = 0; i < S; ++i){
        if(degin[i] == 0){
            continue;
        }
        cout << i << ":" << degin[i] << endl;
    }
    cout << "valid deg dist" << endl;
    for(int i = 0; i < S; ++i){
        if(validin[i] == 0){
            continue;
        }
        cout << i << ":" << validin[i] << endl;
    }
    cout << "heaviness of edges" << endl;
    for(int i = 0; i < S; ++i){
        if(validin[i] == 0){
            continue;
        }
        cout << i << " stats" << endl;
        for(auto & x : validist[i]){
            cout << x.first << ":" << x.second << endl;
        }
    }
    cout << "size of edges" << endl;
    for(auto & x: len){
        cout << x.first << ":" << x.second <<endl;
    }
    
    cout << "length of edges" << endl;
    for(auto & x: Plen){
        cout << x.first << ":" << x.second <<endl;
    }
    //output();
    return 0;
}