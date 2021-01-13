#include <bits/stdc++.h>

using namespace std;
int n,m;
#define ll long long
#define INF 10e17
vector<vector<ll>> capacity;
vector<vector<ll>> adj;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < n; i++){
        vector<ll> v;
        for (ll j = 0; j < n; j++){
            v.push_back(0);
        }
        capacity.push_back(v);
        adj.push_back({});
    }
    for (int i = 0; i < m; i++){
        int x,y,c;
        cin >> x >> y >> c;
        x--; y--;
        capacity[x][y] += c;
        adj[x].push_back(y);
    }
    cout << maxflow(0,n - 1);
    return 0;
}