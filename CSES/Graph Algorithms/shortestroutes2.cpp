#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<vector<ll>> d(1000,vector<ll>(1000,1e17));
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 0 ; i < m; i++){
        int x,y;
        ll c;
        cin >> x >> y >> c;
        x--; y--;
        d[x][y] = min(d[x][y],c);
        d[y][x] = min(d[y][x],c);
    }
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j){
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
    }
    while (q--){
        int x,y;
        cin >> x >> y;
        x--; y--;
        if (d[x][y] != 1e17) cout << d[x][y];
        else cout << -1;
        cout << endl;
    }    
    return 0;
}