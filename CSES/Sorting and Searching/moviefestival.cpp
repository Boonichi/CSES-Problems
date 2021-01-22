#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<ll,ll>> ti;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        ti.push_back({y,x});
    }    
    sort(ti.begin(),ti.end());
    int res = 0, temp = 0;
    int i = 0;
    while (i < n){
        if (temp <= ti[i].second){
            temp=ti[i].first;
            res++;
            i++;
        }
        else i++;
    }
    cout << res;
    return 0;
}