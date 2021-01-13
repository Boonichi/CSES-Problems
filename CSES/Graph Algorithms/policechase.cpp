#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<vector<int>> cap;
vector<vector<int>> res;
int a[1000][1000];
int n,m;
void dfs(vector<vector<int>> cap, int s, bool visited[]){
    visited[s] = true;
    for (int i = 0; i < n; i++){
        if (cap[s][i] && !visited[i]){
            dfs(cap,i,visited);
        }
    }
}
int bfs(int s, int t, vector<int>& parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s] = - 2;
    queue<pair<int,int>> q;
    q.push({s,1000000});
    vector<int> res;
    while (!q.empty()){
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next: adj[cur]){
            if (parent[next] == -1 && cap[cur][next]){
                parent[next] = cur;
                int new_flow = min(flow,cap[cur][next]);
                if (next == t) return new_flow;
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}
int maxflow(int s, int t){
    vector<int> parent(n);
    int flow = 0;
    int new_flow;
    while (new_flow = bfs(s,t,parent)){
        flow+=new_flow;
        int cur = t;
        while (cur != s){
            int prev = parent[cur];
            cap[cur][prev] +=new_flow;
            cap[prev][cur] -=new_flow;
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
    for (int i = 0; i < n; i++){
        vector<int> v;
        for (int j = 0; j < n; j++){
            v.push_back(0);
        }
        adj.push_back({});
        cap.push_back(v);
    }
    for (int i = 0; i < m; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        a[x][y] = 1;
        a[y][x] = 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
        cap[x][y] = 1;
        cap[y][x] = 1;
    }
    int ds =  maxflow(0,n - 1);
    cout << ds << endl;
    bool visited[n];
    memset(visited,false, sizeof(visited));
    dfs(cap, 0 , visited);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (visited[i] && !visited[j] && a[i][j]){
                cout << i + 1 << ' ' << j + 1 << endl;
            }
        }
    }
    return 0;
}