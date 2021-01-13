#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<int> seg(1000000,0);
void update(int id, int value,int u, int v, int l, int r){
    if (l > r || u > r || v < l) return;
    if (u <= l && v >= r){
        seg[id] = value;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2,value, u,v,l,mid);
    update(id * 2 + 1, value,u,v,mid + 1,r);
    seg[id] = seg[id * 2] + seg[id * 2+ 1];
}
int get(int id, int u, int v, int l, int r){
    if (l > r || u > r || v < l) return 0;
    if (u <= l && v >= r) return seg[id];
    int mid = (l + r) / 2;
    return get(id * 2, u,v,l,mid) + get(id * 2 + 1, u,v,mid + 1, r);
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        update(1,1,i,i,0,n-1);
    }    
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        int pos = n + 1, l = 0, r = n - 1;
        while (l <= r){
            int mid = (l + r) / 2;
            //cout << get(1,0,mid,0,n-1) << endl;
            if (get(1,0,mid,0,n - 1) >= x){
                pos = mid;
                r = mid - 1;
            }
            else l = mid + 1;
            //cout << pos << ' ' << mid << endl;
        }
        if (pos <= n){
            update(1,0,pos,pos,0,n - 1);
            cout << a[pos] << ' ';
        }
    }
    return 0;
}