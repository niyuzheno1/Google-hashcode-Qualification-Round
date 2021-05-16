#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <queue>
using namespace std;

#define MAXN 100010
#define MAXM 1010
int D, I, S, V, F,A;
int points;
map<string, pair<int,int>> BE;
map<string, int> L;
map<string, queue<int>> Que;
vector<pair<string,int>> arrival[MAXM];
typedef struct _car{
    vector<string> VE;
    int sit; 
    int loc0;
    int loc1;
    int timeonloc1;
    int cid;
    void update(int ctime = 0){
        if(sit == 0){
            
            timeonloc1 = 0;
            sit = 1;
        }else if(sit == 1){
            timeonloc1 = timeonloc1 + 1;
            if(timeonloc1 >= L[VE[loc1]]){
                sit = 0;
                loc0 = BE[VE[loc1]].second;
                arrival[loc0].push_back(make_pair(VE[loc1],ctime));
                timeonloc1 = 0;
                if(loc1 == VE.size()-1){
                    sit = 2;
                    return;
                }
                Que[VE[loc1]].push(cid);
                loc1 = loc1 + 1;
            }
        }
    }
}car;
typedef struct _int{
    vector<pair<string,int>> schedule;
    int curtime;
    int totaltime;
}ints;
car cars[MAXM];
ints inter[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ifstream fin("input.txt");
    ifstream fout("output.txt");
    cin >> D >> I >> S >> V >> F;
    for(int i = 0; i < S; ++i){
        int B,E,l; string name;
        cin >> B >> E >> name >> l;
        BE[name] = make_pair(B,E);
        L[name] = l;
    }
    for(int i = 0; i < V; ++i){
        int P; cin >> P;
        for(int j = 0; j < P; ++j){
            string x; cin >> x;
            cars[i].VE.push_back(x);

        }
        cars[i].cid = i;
        cars[i].sit = 1;
        cars[i].loc1 = 0;
        cars[i].loc0 = 0;
        cars[i].timeonloc1 = L[cars[i].VE[0]];
        cars[i].update();
    }
    fout >> A;
    for(int i = 0; i < A; ++i){
        int sid; fout >> sid;
        int num; fout >> num;
        int total = 0;
        for(int j = 0; j < num; ++ j){
            string x; int len; 
            fout >> x >> len;
            inter[sid].schedule.push_back(make_pair(x,len));
            total += len;
        }
        inter[sid].totaltime = total;
    }
    for(int i = 0; i <= D; ++i)
    {
        for(int j = 0; j < V; ++j){
            if(cars[j].sit == 1){
                cars[j].update(i);
                if(cars[j].sit == 2){
                    
                    points += F;
                    points += D-i;
                }
            }
        }
        for(int j = 0; j < V; ++j){
            if(cars[j].sit == 0){
                if(inter[cars[j].loc0].curtime > i) continue;
                inter[cars[j].loc0].curtime = i+1;
                if(inter[cars[j].loc0].totaltime == 0) continue;
                int u  = i % inter[cars[j].loc0].totaltime;
                ++u;
                int total = 0;
                for(int k = 0; k < inter[cars[j].loc0].schedule.size(); ++k){
                    if(total + inter[cars[j].loc0].schedule[k].second >= u){
                        //cout << cars[j].loc0 << " " << i << " " << inter[cars[j].loc0].schedule[k].first << endl;
                        auto & uu = Que[inter[cars[j].loc0].schedule[k].first];
                        if(!uu.empty()){
                            auto y = uu.front(); uu.pop();
                            cars[y].update();
                        }
                        break;
                    }
                    total += inter[cars[j].loc0].schedule[k].second;
                    
                }
            }
        }
    }
    cout << points << endl;
    for(int i = 0; i < I; ++i){
        if(arrival[i].size() > 0){
            cout << i << ":" << endl;
            for(auto & x : arrival[i]){
                cout << x.first << "---" << x.second << endl;
            }
        }
    }
    return 0;
}