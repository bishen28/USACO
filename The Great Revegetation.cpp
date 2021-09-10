/*
problem link ->>   http://www.usaco.org/index.php?page=viewproblem2&cpid=920
Topic --> DFS + Bipartiteness check
*/

#include <bits/stdc++.h>

using namespace std;
 // in this problem there is an weight to each edge; colour to identify weather the to connected 
 // edge are of same color of of different color.
 // my mistake is i am not storing the edge property
 // so that i am goofing up on my dfs;  how should i call my dfs fron a node, I dont know my 
 // adj_node is of same type or not;
 // another bulender mistake is I am giving the red(1) to all my same kind of node 
 // and treating it as already visited; but in actually this should be dynamic; all 
 // same colur(previsolly marked as red)  can be changed to all blue during my dfs operation
 // depending upon on from which node i am starting my dfs;


 // my biggest bullender is the i am making my same coloure node as red and keeping is 
 // static; kipping static is my biggest bullender on my life'
 // I am felling very happy that i have cracked my bullender;
 // and finally got AC
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
