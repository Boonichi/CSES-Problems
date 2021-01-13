#include <bits/stdc++.h>

using namespace std;
int a[10000000],t[10000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int res = 0;
    t[0] = 1;
    for (int i = 1; i < s.length();i++){
        if (s[i] == s[i - 1]){
            t[i] = t[i - 1] + 1;
        }
        else {
            t[i] = 1;
            res = max(res,t[i - 1]);
        }
    }
    res=max(res,t[s.length() - 1]);
    cout << res;
    return 0;
}