#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll expo(ll x, ll y, ll m){
    //cout << x << ' ' << y << endl;
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return (expo(x,y / 2,m) * expo(x,y / 2,m)) % m;
    else return ((expo(x,y / 2,m) * expo(x,y / 2,m))% m * x) % m;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll x,y,z;
        cin >> x >> y >> z; 
        cout << expo(x,expo(y,z,M - 1),M) << endl;
    }    
    return 0;
}