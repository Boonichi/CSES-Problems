#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
ll base = 37;
ll p[2000000],h[2000000];
ll geth(ll h[],int i , int j){
    return (h[j] - h[i - 1] * p[j - i + 1] + M*M) % M;
}
int main(){
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    p[0] = 1;
    h[0] = 0;
    t = s;
    for (int i = 1; i <= s.size(); i++){
        hs[i] = (hs[i - 1] * base + (s[i - 1] - 'a')) % M;
        p[i] = (p[i - 1] * base) % M;
        ht[i] = (ht[i - 1] * base + (t[i - 1] - 'a')) % M;
    }
    int l = 0, r = s.size() - 1;
    while (l < r){
        int mid = (l + r) / 2;
        if (mid % 2) mid++;
        if (check(mid)) l = mid;
        else r = mid - 2;
    }
    cout << s.substr(l,l + mid);
    return 0;
}