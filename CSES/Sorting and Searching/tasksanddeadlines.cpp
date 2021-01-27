#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
vector<pair<int,int>> a;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }    
    sort(a.begin(),a.end());
    ll res = 0, sum = 0;
    for (int i = 0; i < n; i++){
        sum+=a[i].first;
        res+=a[i].second - sum;
    }
    cout << res << endl;
    return 0;
}