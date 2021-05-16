#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAXN 1000000
ll V,E,R,C,X;
vector<ll> S;
typedef struct _endpoint_info{
    ll LD;
    map<ll,ll> server;
    vector<ll> sids;
    map<ll,ll> request;
    vector<pair<ll,ll>> req;
}einfo;
vector<ll> cap;
vector<vector<ll>> ans;
vector<vector<ll>> enp;
vector<map<ll,ll>> dp;
vector<einfo> ep;
ll ask(ll sid, ll val){
    
    if(dp[sid].count(val) && dp[sid][val] != -1) return dp[sid][val];
    ll & ret = dp[sid][val];
    for(auto & x : enp[sid]){
        if(ep[x].request.count(val) == 0) continue;
        auto req = ep[x].request[val];
        auto diff = (ep[x].LD-ep[x].server[sid])*req;
        ret += diff;
    }
    return ret;
}
void update(ll sid, ll val){
    ans[sid].push_back(val);
    cap[sid] += S[val];
    dp[sid][val] = -1;
    for(auto & x : enp[sid]){
        if(ep[x].request.count(val) == 0) continue;
        auto & req = ep[x].request[val];
        req = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> V >> E >> R >> C >> X;
    S.resize(V);

    cap.resize(C);
    enp.resize(C);
    ans.resize(C);
    dp.resize(C);
    
    for(int i = 0 ; i < V; ++i)
        cin >> S[i];
    ep.resize(E);
    for(int i = 0; i < E; ++i){
        cin>> ep[i].LD;
        int K; cin >> K;
        for(int j = 0; j < K;++j){
            ll s, l; cin >> s >> l;
            ep[i].server[s] = l;
            ep[i].sids.push_back(s);
        }
    }
    for(int i = 0; i < R; ++i){
        ll v, id, num; cin >> v >> id >> num;
        ep[id].request[v] += num;
        
    }
    for(int i = 0; i < E; ++i){
        for(auto & x : ep[i].server){
            enp[x.first].push_back(i);
        }
        for(auto & x : ep[i].request){
            ep[i].req.push_back(make_pair(x.second,x.first));
        }
        sort(ep[i].req.begin(), ep[i].req.end());
    }
    for(int i = 0; i < E; ++i){
        for(int j = 0; j < ep[i].req.size(); ++j){
            ll best = -1, bestserver = -1;
            if(ep[i].request[ep[i].req[j].second] == 0) continue;
            for(int k = 0; k < ep[i].sids.size(); ++ k){
                ll sid = ep[i].sids[k];
                if(cap[sid] + S[ep[i].req[j].second] > X) continue;
                auto  r = ask(sid,ep[i].req[j].second);
                if(r > best){
                    best = r;
                    bestserver = sid;
                }
            }
            if(best == -1){
                continue;
            }
            update(bestserver, ep[i].req[j].second);
        }
    }
    int cnt = 0;
    for(int i = 0; i < C; ++i){
        if(ans[i].size() > 0){
            ++ cnt;
        }
    }
    cout << cnt << endl;
    for(int i = 0; i < C; ++i){
        if(ans[i].size() > 0){
            cout << i << " ";
            for(auto & x : ans[i]){
                cout << x << " ";
            }
            
        cout << endl;
        }
    }
    return 0;
}