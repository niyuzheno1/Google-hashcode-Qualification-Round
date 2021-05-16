#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>
#include <algorithm>
using namespace std;
#define MAXN 100010
typedef bitset<3000> bset;
bset a[MAXN];
bool fix[MAXN];
bset refx;

typedef struct _aset{
    bset x;
    int u,v;
}aset;
int changes; 
vector<aset> vset;
aset v1[MAXN];
aset v2[MAXN];
int n;
int diff(const bset & a, const bset & b){
    bset c;
    c = a & (~(b));
    return c.count();
}
int inter(const bset & a, const bset & b){
    bset c;
    c = a & b;
    int ret = c.count();
    return ret;
}
int comp(const bset & a){
    int ret = inter(a,refx);
    ret = min(diff(a,refx),ret);
    ret = min(diff(refx,a),ret);
    return ret;
}
int comp2(const aset & a){
    if(a.v != -2){
        return -1000000;
    }
    return -inter(a.x,refx);
}
void process_output(int m){
    vector<pair<int,int>> ans;
    for(int i = 0; i < m; ++i){
        if(v1[i].v >= 0){
            ans.push_back(make_pair(v1[i].u, v1[i].v));
        }
        if(v1[i].v == -1){
            ans.push_back(make_pair(v1[i].u, -1));
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i< ans.size(); ++i){
        if(ans[i].second == -1){
            cout << ans[i].first << endl;
        }else{
            cout << ans[i].first << " " << ans[i].second << endl;
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
            a[i].set(x,1);
            
        }
        aset x;
        x.u = i;
        if(v == "H")
            x.v = -1;
        else
            x.v = -2;
        x.x = a[i];
        vset.push_back(x);
    }
    if(maxm > 3000){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i <= maxm; ++i)
        refx.set(i,1);
    int m = vset.size();
    for(int i = 0; i < vset.size(); ++i)
        v1[i] = vset[i];
    sort(v1, v1+m, [] (const aset & lhs, const aset & rhs){ return comp(lhs.x) > comp(rhs.x);} );
    for(int j = 0; j < m; ++j){
        refx = v1[j].x;
        if(v1[j].v != -2){
            sort(v1+j+1, v1+m, [] (const aset & lhs, const aset & rhs){ return comp(lhs.x) > comp(rhs.x);} );
        }else{
            if(v1[j].v == -2){
                sort(v1+j+1, v1+m, [] (const aset & lhs, const aset & rhs){ return comp2(lhs) > comp2(rhs);} );
                if(v1[j+1].v != -2){
                    m = j+1;
                    break;
                }else{
                    v1[j+1].v = v1[j].u;
                    v1[j+1].x |= v1[j].x;
                }
            }
        }
    }
    process_output(m);
    return 0;
}