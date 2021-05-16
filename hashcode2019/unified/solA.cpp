/*preprocessing*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef struct _p{
    string or;
    vector<int> n;
}pp;
#define MAXN 100010
pp u[MAXN];
map<string,int> sx;
int n, tot=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        int m;
        cin >> u[i].or >> m;
        for(int j = 0; j < m; ++j){ 
            string x; cin >> x;
            if(!sx.count(x)){
                ++tot;
                sx[x] = tot;
            }
            u[i].n.push_back(sx[x]);
        }
    }
    cout << n << endl;
    for(int i = 0; i < n; ++i){
        int m = u[i].n.size();
        cout << u[i].or << " " << u[i].n.size() << " ";
        for(int j = 0; j < m; ++j){ 
            cout << u[i].n[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}