#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<ll> sum(1000000,0),lazy(1000000,0);
void push(int id, int l, int r){
    int mid = (l +r ) / 2;
    if ((mid - l + 1) % 2 == 0) sum[id * 2] += lazy[id] * (mid - l + 1) * ((mid + l) / 2);
    else sum[id * 2] += lazy[id] * (mid - l + 1) * ((mid + l) / 2) + ((mid + l) / 2 + 1);
    if ((r - mid % 2) == 0) sum[id * 2 + 1] += lazy[id] * (r - mid) * ((r + mid) / 2);
    else sum[id * 2 + 1] += lazy[id] * (r - mid) * ((r + mid) / 2) + ((r + mid) / 2 + 1);
    lazy[id * 2+ 1] += (lazy[id] );
    lazy[id * 2] +=(lazy[id] );
    lazy[id] = 0;
}
void update(int id, ll value, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r){
            sum[id] += value * (r - l  + 1);
            lazy[id] +=value;
        return;
    }
    push(id,l,r);
    int mid = (l +r ) / 2;
    update(id * 2, value, u,v,l,mid);
    update(id * 2 + 1, value, u ,v, mid + 1, r);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}
ll getsum(int id, int u ,int v, int l, int r){
    if (l > r || u > r || v < l) return 0;
    if (u <= l && v >= r) return sum[id];
    push(id,l,r);
    int mid = (l + r) / 2;
    ll ans = getsum(id * 2, u,v, l , mid) + getsum(id * 2 + 1, u ,v, mid + 1, r);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
    return ans;
}
void build(int id, ll value, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r){
        sum[id] = value;
        return;
    }
    int mid = (l + r ) / 2;
    build(id * 2, value, u ,v , l, mid);
    build (id * 2 + 1, value, u , v, mid + 1, r);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        build(1,x,i,i,0,n- 1);
    }
    while (t--){
        int q;
        cin >> q;
        if (q == 1){
            int x,y;
            cin >> x >> y;
            x--; y--;
            update(1,1,x,y,0,n - 1);
        }
        else {
            int x,y;
            cin >> x >> y;
            x--; y--;
            cout << getsum(1,x,y,0,n-1) << endl;
        }
    }
    return 0;
}