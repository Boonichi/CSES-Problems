#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<ll> seg(1000000,0);
vector<ll> add(1000000,0);
void update(int id, int value, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r) {
        seg[id]+=value; add[id]+=value;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, value, u , v, l , mid);
    update(id * 2 + 1, value, u , v , mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}
ll getnum(int id,int u, int v,int l, int r){
    if (l > r || u > r || v < l) return 0;
    if (u <= l && v >= r) return seg[id];
    int mid = (l + r) / 2;
    return getnum(id * 2, u,v,l,mid) + getnum(id * 2+ 1, u ,v, mid + 1,r) + add[id];
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    for (int i = 0;i < n; i++){
        int x;
        cin >> x;
        update(1,x,i,i,0,n-1);
    }
    while (t--){
        int q,x,y,value;
        cin >> q;
        if (q == 1) {
            cin >> x >> y >> value;
            x--; y--;
            update(1,value,x,y,0,n-1);
        }
        else {
            cin >> x;
            x--;
            cout << getnum(1,x,x,0, n - 1) << endl;
        }
    }
    return 0;
}