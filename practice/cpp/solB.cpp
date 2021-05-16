#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<int, int> f;
int tot;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,t2,t3,t4;
    cin >> n >> t2 >> t3 >> t4;
    int ret = -1;
    for(int i = 0 ; i < n; ++i){
        int m; cin >> m; 
        for(int j = 0; j < m; ++j){
            int s; cin >> s;
            ret = max(s,ret);
        }
        ++f[m];  
    }
    for(auto & x: f){
        cout << x.first << "," << x.second << endl;
    }
    cout << "maximum : " << ret << endl;
    return 0;
}