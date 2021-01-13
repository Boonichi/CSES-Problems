#include <bits/stdc++.h>

using namespace std;
set<string> res;
string s;
vector<int> permutation;
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) permutation.push_back(i);
    do{
        string s1 = "";
        for (int i : permutation) s1+=s[i];
        res.emplace(s1);
    } while(next_permutation(permutation.begin(),permutation.end()));
    cout << res.size() << endl;
    for (string s1 : res) cout << s1 << endl;
    return 0;
}