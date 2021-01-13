#include <bits/stdc++.h>

using namespace std;
vector<int> res;
bool check[10000000];
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long t = 0;
    for (int i = 1; i <= n; i++){
        t+=i;
        check[i] = true;
    }
    int sl = 0;
    if (t % 2) cout << "NO";
    else{
        cout << "YES" << endl;
        t/=2;
        int i = n;
        while (t > 0){
            t-=i;
            sl++;
            res.push_back(i);
            check[i] = false;
            if (t <= 1000000 && check[t] == true){
                check[t] = false;
                sl++;
                res.push_back(t);
                t-=t;
            }
            i--;
        }
        cout << sl << endl;
        for (int i : res) cout << i << ' ';
        cout << endl;
        sl = 0; res.clear();
        for (int i = 1; i <= n;i++) if (check[i] == true){sl++; res.push_back(i);};
        cout << sl << endl;
        for (int i : res) cout << i << ' ';
    }    
    return 0;
}