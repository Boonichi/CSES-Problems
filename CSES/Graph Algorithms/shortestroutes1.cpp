#include <bits/stdc++.h>

using namespace std;
int n,m;
#define ll long long
ll MAX = 1e17;
vector<vector<pair<int,ll>>> adj(1000000);
void dijkstra(int start){
    vector<ll> d(1000000,1e17);
    vector<int> p(1000000,-1);
    d[start] = 0;
    set<pair<ll,int>> q;
    q.insert({0,start});
    while (!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : adj[v]){
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]){
                q.erase({d[to],to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to],to});
            }
        }
    }
    for (int i = 0; i < n; i++) cout << d[i] << ' ';
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        int x,y;
        ll d;
        cin >> x >> y >> d;
        x--; y--;
        adj[x].push_back({y,d});
    }
    dijkstra(0);
    return 0;
}