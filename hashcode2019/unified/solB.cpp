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
vector<aset> v;
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
    }
    if(maxm > 3000){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n-1; ++i){
        if(fix[i]) continue;
        int idx = -1;
        bset u = a[i];
        aset x;
        x.u = i;
        for(int j = i+1; j < n; ++j){
            if(fix[j]) continue;
            if(idx == -1)
                idx = j;
            if(inter(a[i],a[j]) < inter(a[i],a[idx])){
                idx = j;
            }
            if(inter(a[i],a[idx]) == 0) break;
        }
        x.v = idx;
        x.x = (a[i])|(a[idx]);
        fix[x.u] = 1;
        fix[x.v] = 1;
        v.push_back(x);
    }
    for(int i = 0; i <= maxm; ++i)
        refx.set(i,1);
    int m = v.size();
    for(int i = 0; i < v.size(); ++i)
        v1[i] = v[i];
    sort(v1, v1+m, [] (const aset & lhs, const aset & rhs){ return comp(lhs.x) > comp(rhs.x);} );
    for(int j = 0; j < m; ++j){
        if(j > 0){
            if(inter(v1[j].x,v1[j-1].x) == 0){
                refx = v1[j-1].x;
                sort(v1+j, v1+m, [] (const aset & lhs, const aset & rhs){ return comp(lhs.x) > comp(rhs.x);} );
            }
        }

    }
    cout << m << endl;
    for(int i = 0; i < m; ++ i)
    {
        cout << v1[i].u << " " << v1[i].v << endl;
    }
    return 0;
}