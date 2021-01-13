#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<int> seg(1000000,0);
void update(int id, int value, int u, int v, int l ,int r){
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r){
        seg[id]+= value;
        return;
    }
    int mid = (l +r ) / 2;
    update(id * 2, value, u , v,l, mid);
    update(id * 2 + 1, value, u ,v , mid + 1, r);
    seg[id] = max(seg[id * 2],seg[id * 2 + 1]);
}
int get(int id, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return -INT_MAX;
    if (u <= l && v >= r) return seg[id];
    int mid = (l + r) / 2;
    return max(get(id * 2,u,v,l,mid),get(id * 2 + 1, u,v,mid + 1, r));
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
        update(1,x,i,i,0,n - 1);
    }
    for (int i = 0; i < m; i++){
        int x;
        cin >> x;
        int pos = n + 1, l = 0,r = n - 1, decrease = 0;
        while (l <= r){
            int mid = (l + r) / 2;
            if (get(1,0,mid,0,n - 1) >= x){
                pos = min(pos,mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (pos <= n){
            update(1,-x,pos,pos,0,n - 1);
            cout << pos + 1 << ' ';
        }
        else cout << 0 << ' ';
    }
    return 0;
}