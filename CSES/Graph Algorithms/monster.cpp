#include <bits/stdc++.h>

using namespace std;
#define ll long long
long long M = 1e9 + 7;
pair<int,int> adj[4] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<char>> a(1001,vector<char>(1001,'#'));
vector<vector<int>> mcnt(1000,vector<int>(1000,INT_MAX));
vector<vector<bool>> check(1000,vector<bool>(1000,false));
vector<vector<pair<int,int>>> parent(1000,vector<pair<int,int>>(1000));
pair<int,int> human,res;
queue<vector<int>> monster;
vector<char> ans;
int n,m;
bool checkexit(int x, int y){
    if (x == n - 1 || x == 0 || y == m - 1 || y == 0) return true;
    else return false;
}
bool checkexist(int x, int y){
    if (x < n && x >= 0 && y < m && y >= 0) return true;
    else return false;
}
void bfsm(queue<vector<int>> q){
    while (!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        for (auto i : adj){
            int adjx = x + i.first;
            int adjy = y + i.second;
            if (checkexist(adjx,adjy)){
            if (a[adjx][adjy] != '#' && a[adjx][adjy] != 'M' && cnt + 1 < mcnt[adjx][adjy]){
                mcnt[adjx][adjy] = cnt + 1;
                q.push({adjx,adjy,cnt+1});
            }
            }
        }
    }
}
bool bfsh(pair<int,int> start){
    queue<vector<int>> q;
    q.push({start.first,start.second,0});
    while (!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int cnt = q.front()[2];
        q.pop();
        for (auto i : adj){
            int adjx = x + i.first;
            int adjy = y + i.second;
            if (checkexist(adjx,adjy)){
            if (a[adjx][adjy] != '#' && a[adjx][adjy] != 'M' && check[adjx][adjy] == false && cnt < mcnt[adjx][adjy]){
                parent[adjx][adjy] = {i.first,i.second};
                check[adjx][adjy] = true;
                if (cnt + 1 < mcnt[adjx][adjy] && checkexit(adjx,adjy) == true){
                    res.first = adjx;
                    res.second = adjy;
                    return true;
                }
                q.push({adjx,adjy,cnt + 1});
            }
            }
        }
    }
    return false;
}
int main(){
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'M'){
                monster.push({i,j,0});
                mcnt[i][j] = 0;
            }
            if (a[i][j] == 'A'){
                human.first = i;
                human.second = j;
            }
        }
    }    
    if (checkexit(human.first,human.second) == true){
        cout << "YES" << endl;
        cout << 0;
    }
    else{
    bfsm(monster);
    if (bfsh(human) == false) cout << "NO";
    else{
        cout << "YES" << endl;
        pair<int,int> x;
        while (true){
            x = parent[res.first][res.second];
            if (x.first == 0 && x.second == 1) ans.push_back('R');
            if (x.first == 0 && x.second == -1) ans.push_back('L');
            if (x.first == 1 && x.second == 0) ans.push_back('D');
            if (x.first == -1 && x.second == 0) ans.push_back('U');
            res.first=res.first - x.first; res.second= res.second - x.second;
            if (a[res.first][res.second] == 'A') break;
        }
        cout << ans.size() << endl;
        reverse(ans.begin(),ans.end());
        for (auto i : ans) cout << i;
    }
    }
    return 0;
}