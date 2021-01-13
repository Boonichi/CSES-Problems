#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 3 || n == 2) cout << "NO SOLUTION"; 
    else{
        for (int i = 2; i <= n; i+=2){
            cout << i << ' ';
        }
        for (int i = 1; i <= n; i+=2){
            cout << i << ' ';
        }
    }
    return 0;
}