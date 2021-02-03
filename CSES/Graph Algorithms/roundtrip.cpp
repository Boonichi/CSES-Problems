#include <bits/stdc++.h>

using namespace std;
int n,m;
#define ll long long
vector<vector<int>> adj(1000000);
vector<int> check(1000000,0);
vector<int> parent(1000000,-1);
int cycle_end = -1, cycle_start = -1;
bool dfs(int node, int previous){
    check[node] = 1;
    for (auto i : adj[node]){
        if (i == previous) continue;
        if (check[i] == 1){
            cycle_end = node;
            cycle_start = i;
            return true;
        }
        parent[i] = node;
        if (dfs(i,node)) return true;
    }
    return false;
}
void cycle(){
    for (int i = 0; i < n; i++){
        if (check[i] == 0 && dfs(i,parent[i]) == true){
            break;
        }
    }
    if (cycle_start == -1) cout << "IMPOSSIBLE";
    else{
        vector<int> res;
        res.push_back(cycle_start);
        for (int i = cycle_end; i != cycle_start; i = parent[i]){
            res.push_back(i);
        }
        res.push_back(cycle_start);
        cout << res.size() << endl;
        for (int i : res) cout << i + 1 << ' ';
    }
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cycle();
    return 0;
}