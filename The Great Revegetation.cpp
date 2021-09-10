/*
problem link ->>   http://www.usaco.org/index.php?page=viewproblem2&cpid=920
Topic --> DFS + Bipartiteness check
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int>>> adj_list;
vector<int> color;
vector<bool> visited;
int n,m;
bool impossible = false;

void dfs(int node, int par){
      if(impossible) return;
      visited[node] = true;
      color[node] = par;
      for(auto adj_node:adj_list[node]){
        if(visited[adj_node.first]==false){
          if(adj_node.second==1) dfs(adj_node.first,color[node]);
          else dfs(adj_node.first,color[node]%2+1);
        }else{
          if(adj_node.second==1&&color[adj_node.first]!=color[node]) impossible = true;
          if(adj_node.second==2&&color[adj_node.first]==color[node]) impossible = true;
        }
      }  
}

void solve() {
      cin>>n>>m;
      adj_list.resize(n+1);
      visited.resize(n+1,false);
      color.resize(n+1,0);

      for(int i=1;i<=m;i++){
        char c;int u,v;
        cin>>c>>u>>v;
        if(c=='S'){
            adj_list[u].push_back({v,1});
            adj_list[v].push_back({u,1});
        }else{
            adj_list[u].push_back({v,2});
            adj_list[v].push_back({u,2});
        }
      } 


    
    int component = 0;
    for(int i=1;i<=n;i++){
        if(impossible) break;
        if(visited[i]==false){
          dfs(i,2);
          component++;
        }
    }
    if(impossible)cout << 0;
    else for(int i=0;i<=component;i++) i==0 ? cout << 1 : cout << 0;  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);
  
  solve();
   
  return 0;
}
