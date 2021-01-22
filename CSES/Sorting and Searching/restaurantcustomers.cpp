#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<pair<ll,ll>> ti;
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        ti.push_back({x,1});
        cin >> x;
        ti.push_back({x,-1});
    }
    sort(ti.begin(),ti.end());
    int res =0,ans = 0;
    for (auto i : ti){
        res+=i.second;
        ans = max(res,ans);
    }
    cout << ans << endl;
    return 0;
}