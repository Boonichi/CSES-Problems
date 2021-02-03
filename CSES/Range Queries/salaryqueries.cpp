#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int n,m;
ll res;
int a[10000000];
ll sum[10000000];
void update(int id, int value, int u ,int v, int l ,int r){
    if (l > r || l > v || u > r) return;
    if (u <= l && v >= r){
        sum[id]+=value;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, value, u,v, l, mid);
    update(id * 2+ 1, value, u ,v, mid + 1, r);
    sum[id] = sum[id * 2] + sum[id * 2 + 1];
}
ll get(int id, int u, int v, int l,int r){
    if (l > r || l > v || u > r) return 0;
    if (u <= l && v >= r) return sum[id]; 
    int mid = (l + r)  / 2;
    return get(id * 2, u,v,l, mid) + get(id * 2 + 1, u,v,mid + 1, r);
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        update(1,1,a[i],a[i],1,100000);
    }
    while (m--){
        char q;
        int x,y;
        cin >> q >> x >> y;
        if (q == '?'){
            cout << get(1,x,y,1,100000) << endl;
        }
        else{
            x--;
            update(1,-1,a[x],a[x],1,100000);
            a[x] = y;
            update(1,1,a[x],a[x],1,100000);
        }
    }
    return 0;
}