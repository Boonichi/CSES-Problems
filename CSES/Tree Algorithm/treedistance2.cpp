#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<vector<int>> tree(200001);
ll subtreeAns[200001];
ll ans[200001];
int subtreeSize[200001];
void reroot(int node, int parent){
    int children = 1;
    ll childsubtree = 0;
    for (int child : tree[node]){
        if (child != parent){
            reroot(child,node);
            children+=subtreeSize[child];
            childsubtree+=subtreeSize[child] + subtreeAns[child];
        }
    }
    subtreeSize[node]=children;
    subtreeAns[node]=childsubtree;
}
void solve(int src, int par,ll par_ans, int totalNodes){
    ans[src] = subtreeAns[src] + (par_ans + (totalNodes - subtreeSize[src]));
 
    for(int child : tree[src])
    {
        if(child != par)
            solve(child, src, ans[src] - (subtreeAns[child] + subtreeSize[child]), totalNodes);
    }
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int x,y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    } 
    reroot(1,0);
    solve(1,0,0,n);
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}