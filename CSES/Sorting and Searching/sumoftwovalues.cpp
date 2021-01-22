#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,ll>> a;
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
    sort(a.begin(),a.end());
    int i = 0, j = n - 1;
    bool check = false;
    while (i < j){
        if (a[i].first + a[j].first == t){
            cout << a[i].second + 1 << ' ' << a[j].second + 1;
            check = true;
            break;
        }
        if (a[i].first + a[j].first > t) j--;
        else if (a[i].first + a[j].first < t) i++;
    }
    if (check == false) cout << "IMPOSSIBLE" << endl;
    return 0; 
}