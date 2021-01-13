#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll expo(ll x, ll y){
    //cout << x << ' ' << y << endl;
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return (expo(x,y / 2) * expo(x,y / 2)) % M;
    else return ((expo(x,y / 2) * expo(x,y / 2))% M * x) % M;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll x,y;
        cin >> x >> y;
        cout << expo(x,y) << endl;
    }    
    return 0;
}