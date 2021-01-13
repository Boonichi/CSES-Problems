#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
int n,q;
int color[1000000]; 
bool bipartite() 
{
    for (int i = 0; i < 1000000; ++i) 
        color[i] = -1; 
    color[0] = 1; 
    queue <int> q; 
    q.push(0); 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop();  
        for (int i : adj[u]) 
        {
            if (u == i) return false;
            if (color[i] == -1) 
            { 
                color[i] = 1 - color[u]; 
                q.push(i); 
            }  
            else if (color[i] == color[u]) 
                return false; 
        } 
    } 
    return true; 
} 
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) adj.push_back({});
    while (q--){
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (bipartite() == true){
        for (int i = 0; i < n; i++){
            if (color[i] == 1 || color[i] ==-1) cout << '1' << ' ';
            else cout << '2' << ' ';
        }
    }
    else cout << "IMPOSSIBLE";
    return 0;
}