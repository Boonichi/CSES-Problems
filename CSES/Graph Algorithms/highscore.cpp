#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
struct edge{
    int a,b;
    ll cost;
};
int n,m;
vector<edge> e(100000);
void solve(){
    vector<ll> d(100000,-1e12);
    d[0] = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 0 ; j < m; j++){
                if (d[e[j].b] < M)
                d[e[j].b] = max(d[e[j].b],d[e[j].a] + e[j].cost);
        }
    }
    cout << d[n - 1] << endl;
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x,y;
        ll c;
        cin >> x >> y >> c;
        x--; y--;
        e[i].a = x;
        e[i].b = y;
        e[i].cost = c;
    }
    solve();
    return 0;
}