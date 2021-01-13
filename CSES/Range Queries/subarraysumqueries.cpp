#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
struct data{
    ll sum,pref,suff,ans;
};
data make_data(ll value){
    data res;
    res.sum = value;
    if (value > 0) res.pref = res.suff = res.ans = value;
    else res.pref =res.suff = res.ans = 0;
    return res;
}
data combine(data l, data r){
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref,l.sum + r.pref);
    res.suff = max(r.suff,r.sum + l.suff);
    res.ans = max(max(l.ans,r.ans),l.suff + r.pref);
    return res;
}
data seg[1000000];
void update(int id, ll value, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r){
        seg[id] = make_data(value);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, value, u,v,l,mid );
    update(id * 2 + 1, value, u, v, mid + 1, r);
    seg[id] = combine(seg[id * 2],seg[id * 2 + 1]);
}
int res = 0;
data get(int id, int u,int v, int l,int r){
    if (l > r || u > r || v < l) return make_data(0);
    if (u <= l && v >= r) return seg[id];
    int mid = (l + r) / 2;
    return combine(get(id * 2, u,v, l, mid),get(id * 2 + 1, u,v,mid + 1, r));
}
int main(){ 
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        update(1,x,i,i,0,n - 1);
    }
    while (m--){
        ll x,y;
        cin >> x >> y;
        x--;
        update(1,y,x,x,0,n - 1);
        data res = get(1,0,n-1,0,n-1);
        cout << res.ans << endl;
    }
    return 0; 
}