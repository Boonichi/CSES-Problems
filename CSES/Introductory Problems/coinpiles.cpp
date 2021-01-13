#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        long long a,b;
        cin >> a >> b;
        if (a == 0 && b == 0) cout << "YES";
        else{
        if (a > 0 && b > 0 && (a + b) % 3 == 0 && max(a,b)/2 <= min(a,b)) cout << "YES";
        else cout << "NO";
        }
        cout << endl;
    }    
    return 0;
}