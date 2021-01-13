#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<long long> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        a.insert(x);
    }    
    cout << a.size() << endl;
    return 0;
}