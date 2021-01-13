#include <bits/stdc++.h>

using namespace std;
bool check[100000];
int father[100000],children[100000];
vector<pair<int,int>> path;
int findfa(int u){
    if (u == father[u]) return u;
    return father[u] = findfa(father[u]);
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for (int i = 0 ; i < n; i++) {
        father[i] = i;
        children[i] = 1;
    } 
    for (int i = 0; i < k; i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        u = findfa(u); v = findfa(v);
        //cout << u << ' ' << v << endl;
        if (u != v){ 
            if (children[u] >= children[v]) {
                father[v] = u;
                children[u]+=children[v];
            }
            else{
                father[u] = v;
                children[v]+=children[u];
            }
        }
    }    
    int res = 0;
    int godfather = findfa(0);
    check[godfather] = true;
    for (int i = 1; i < n; i++){
        int fatherhood = findfa(i);
        if (check[fatherhood] == false){
            res++;
            path.push_back({godfather,fatherhood});
            check[fatherhood] = true;
        }
    }
    cout << res << endl;
    for (pair<int,int> paths : path) cout << paths.first + 1<< ' ' << paths.second + 1 << endl;
    return 0;
}