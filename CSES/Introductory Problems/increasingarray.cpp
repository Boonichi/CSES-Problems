#include <bits/stdc++.h>

using namespace std;
long long a[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    long long res = 0;
    for (int i = 1; i < n; i++){
        if (a [i] < a[i - 1]){
            res+= a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }    
    cout << res << endl;
    return 0;
}