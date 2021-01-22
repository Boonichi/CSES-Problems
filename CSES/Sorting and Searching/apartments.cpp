#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll a[1000000],b[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a,a + n);
    sort(b,b + m);
    int i = 0,j  =0,res = 0;
    while ( i < n && j < m){
        if (abs(a[i] - b[j]) <= k){
            res++;
            i++;
            j++;
        }
        else{
            if (a[i] > b[j]) j++;
            else i++;
        }
    }
    cout << res;
    return 0;
}