#include <bits/stdc++.h>
 
using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<ll> pizza1(1000000),pizza2(1000000);
void update1(int id, ll value, int u, int v, int l, int r){
    if (l > r || v < l || u > r) return;
    if (u <= l && v >= r){
        pizza1[id] = value + l;
        return;
    }
    int mid = (l + r) / 2;
    update1(id * 2, value, u, v, l, mid);
    update1(id * 2 + 1, value, u ,v , mid + 1 ,r);
    pizza1[id] = min(pizza1[2 * id],pizza1[2 * id + 1]);
    //cout << u << ' ' <<  l << ' ' << r << ' ' << pizza1[id] << endl;
}
void update2(int id, ll value, int u, int v, int l, int r){
    if (l > r || v < l || u > r) return;
    if (u <= l && v >= r){
        pizza2[id] = value - l;
        return;
    }
    int mid = (l + r) / 2;
    update2(id * 2, value, u, v, l, mid);
    update2(id * 2 + 1, value, u ,v , mid + 1 ,r);
    pizza2[id] = min(pizza2[id * 2],pizza2[id * 2 + 1]);
}
ll getpizza1(int id, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return INT_MAX;
    if (u <= l && v >= r) return pizza1[id];
    int mid = (l +r) / 2;
    return min(getpizza1(id * 2, u, v, l, mid),getpizza1(id * 2 + 1, u ,v, mid + 1, r));
}
ll getpizza2(int id, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return INT_MAX;
    if (u <= l && v >= r) return pizza2[id];
    int mid = (l +r) / 2;
    return min(getpizza2(id * 2, u, v, l, mid),getpizza2(id * 2 + 1, u ,v, mid + 1, r));
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        update1(1,x,i,i,0,n - 1);
        update2(1,x,i,i,0, n - 1);
    }
    while (t--){
        int q;
        ll x,y;
        cin >> q;
        if (q == 1){
            cin >> x >> y;
            x--;
            update1(1,y,x,x,0,n - 1);
            update2(1,y,x,x,0,n-1);
        }
        else{
            cin >> x;
            x--;
            ll left, right;
            left = getpizza2(1,0,x,0,n - 1);
            right = getpizza1(1,x,n - 1,0,n - 1);
            cout << min(left + x ,right - x) << endl; 
        }
    }        
    return 0;
}