#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<int> mintree(1000000,INT_MAX);
void build(int id,int value, int u, int v,int l, int r){
    //cout << l << ' ' << r << ' ' << value << endl;
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r) {
        mintree[id] = min(mintree[id],value);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2,value,u,v,l,mid);
    build(id * 2 + 1,value,u,v,mid + 1, r);
    mintree[id] = min(value,min(mintree[2 * id],mintree[2 * id + 1]));
    //cout << id << ' ' << mintree[id] << endl;
}
int minnumber(int id, int u, int v, int l, int r){
    //cout << l << ' ' << r << ' ' << u << ' ' << v << endl;
    if (l > r || u > r || v < l) return INT_MAX;
    if (u <= l && v >= r) return mintree[id];
    return min(minnumber(id * 2,u,v,l,(l+r)/2),minnumber(id * 2+1,u,v,(l + r) / 2+1,r));
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        build(1,x,i,i,0,n - 1);
    }
    while (m--){
        int x,y;
        cin >> x >> y;
        x--; y--;
        cout << minnumber(1,x,y,0,n - 1);
        cout << endl;
    }
    return 0;
}