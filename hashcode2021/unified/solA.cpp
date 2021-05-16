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
vector<street> G[MAXN];
map<string,int> toEdge; 
vector<schedule> sched[MAXN];
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
        if(sched[tmp.E].size() == 0){
            schedule tmp2;
            tmp2.D = D;
            tmp2.name = tmp.name;
            if(rand()% 2 == 0){
                sched[tmp.E].push_back(tmp2);
            }
        }
    }
    output();
    return 0;
}