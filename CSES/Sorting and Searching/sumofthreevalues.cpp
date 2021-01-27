#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,ll>> a;
int bns(int l, int r, ll value){
    int mid;
    while (l <= r){
        mid = (l + r) / 2;
        if (a[mid].first == value) return mid;
        if (a[mid].first > value) r = mid - 1;
        else l = mid + 1;
    }
    return mid;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        a.push_back({x,i});
    }
    int k;
    sort(a.begin(),a.end());
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++){
            if (a[i].first + a[j].first < t)
            k = bns(j + 1,n - 1,t - a[i].first - a[j].first);
            if (a[i].first + a[j].first + a[k].first == t){
                cout << a[i].second + 1 << ' ' << a[j].second + 1 << ' ' << a[k].second + 1;
                return 0;
            }
        }
    } 
    cout << "IMPOSSIBLE";
    return 0;
}