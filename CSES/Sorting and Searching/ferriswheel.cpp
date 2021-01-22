#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll a[1000000];
int coup[1000000];
int n;
ll t;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0 ; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = n - 1,res = n;
    while (i < j){
        if (t - (a[i] + a[j]) >= 0){
            i++;
            j--;
            res--;
        }
        else j--;
    }
    cout << res << endl;
    return 0;
}