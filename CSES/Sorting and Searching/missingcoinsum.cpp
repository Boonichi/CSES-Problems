#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll a[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a,a + n);
    ll res= 1;
    for (int i = 0; i < n && res >= a[i]; i++){
        res+=a[i];
    }
    cout << res << endl;
    return 0;
}