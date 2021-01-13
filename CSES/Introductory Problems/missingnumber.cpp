#include <bits/stdc++.h>

using namespace std;
int a[1000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x] = 1;
    }    
    for (int i = 1; i <= n;i++){
        if (a[i] != 1){
            cout << i;
            break;
        }
    }
    return 0;
}