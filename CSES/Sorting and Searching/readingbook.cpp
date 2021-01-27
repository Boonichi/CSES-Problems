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
    ll sum = 0, maxx = 0;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        sum+=x;
        maxx = max(x,maxx);
    }    
    if (maxx > (sum - maxx)) cout << 2 * maxx;
    else cout << sum;
    return 0;
}