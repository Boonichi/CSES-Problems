#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int x;
int res = INT_MIN;
vector<vector<int>> adj(1000000);
void dfsutil(int node,int n,int cnt,vector<int> check){
    check[node] = true;
    cnt++;
    for (auto i : adj[node]){
        if (check[i] == false){
            if (cnt >= res){
                res = cnt;
                x = i;
            }
            dfsutil(i,n,cnt,check);
        }
    }
}
void dfs(int node,int n){
    vector<int> check(1000000,false);
    int cnt = -1;
    dfsutil(node,n,cnt + 1,check);
}
int process(int n){
    dfs(1,n);
    dfs(x,n);
    return res;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << process(n) << endl;
    return 0;
}