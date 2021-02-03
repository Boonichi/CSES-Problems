#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll base = 37;
ll p[2000000],h[2000000];
ll geth(int i , int j){
    return (h[j] - h[i - 1] * p[j - i + 1] + M*M) % M;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    p[0] = 1;
    h[0] = 0;
    s+=s;
    for (int i = 1; i <= s.size(); i++){
        h[i] = (h[i - 1] * base + (s[i - 1] - 'a')) % M;
        p[i] = (p[i - 1] * base) % M;
    }
    int res = 1;
    int n = s.length() / 2;
    for (int i = 2; i <= n; i++){
        int l = 0, r = n - 1, mid;
        while (l <= r){
            mid = (l + r) / 2;
            //cout << geth(i,i + mid) << ' ' << geth(res,res + mid) << ' ' << s << endl;
            if (geth(i,i + mid) == geth(res, res + mid)) l = mid + 1;
            else r = mid - 1;
        }
        if (l < n){
            if (s[i + l - 1] < s[res + l - 1]){
                res = i;
            }
        }
    }
    cout << s.substr(res - 1, n);
    return 0;
}