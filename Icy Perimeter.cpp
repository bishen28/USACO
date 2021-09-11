#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> blobs;
vector<vector<bool>> visited;
int row[4] = {1,0,-1,0};
int clm[4] = {0,1,0,-1};

pair<int,int> dfs(int r, int c){
    if(r<0||r>=n||c<0||c>=n||blobs[r][c]=='.') return {0,1};
    if(visited[r][c]) return {0,0};
    visited[r][c] = true;
    pair<int,int> p = {1,0};

      for(int i=0;i<4;i++){
        pair<int,int> out = dfs(r+row[i],c+clm[i]);
        p.first+=out.first;
        p.second+=out.second;
      }
    return p;
}


void solve() {
      cin>>n;
      blobs.resize(n);
      visited.resize(n);
      for(int i=0;i<n;i++){
        cin>>blobs[i];
        visited[i].resize(n,false);
      }
int mxa = 0;
int pe  = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(blobs[i][j]=='#'&&visited[i][j]==false){
            pair<int,int>  out = dfs(i,j);
            //cout << i << " " << j << " --> ";
            int a = out.first;
            int p = out.second;
            if(a==mxa&&p<pe){
               mxa = a;
               pe = p;
            }else{
              if(a>mxa){
                mxa = a;
                pe = p;
              }
            }
            //cout << mxa << " " << pe << endl; 
          }
        }
      }
cout << mxa << " " << pe;

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);

 
  // #ifndef ONLINE_JUDGE
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  // #endif

  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  
  int T = 1;
 // cin >> T;
  while (T--) {
    solve();
    if (T) cout << endl;
  }
  return 0;
}
