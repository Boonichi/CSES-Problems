#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        auto low = lower_bound(dp.begin(),dp.end(),x);
        if (low == dp.end()){
            dp.push_back(x);
        } else *low = x;
    }    
    cout << dp.size() << endl;
    return 0;
}