#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, int> f;
int tot;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,t2,t3,t4;
    cin >> n >> t2 >> t3 >> t4;
    cout << n << " " << t2 << " " << t3 << " " << t4 << endl;
    for(int i = 0 ; i < n; ++i){
        int m; cin >> m; 
        cout << m << " ";
        for(int j = 0; j < m; ++j){
            string s; cin >> s;
            if(!f.count(s)){
                ++tot;
                f[s] = tot;
            }
            cout << f[s] << " ";
       }
       cout << endl;
    }
    
    return 0;
}