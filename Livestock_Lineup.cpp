#include <bits/stdc++.h>
using namespace std;
 
 string str;
 set<string> s;
 vector<pair<int,int>> constraint;
 map<int,string> cowmp;

 bool issatisfied(string s){
    int i,j;
    string c1,c2;
    for(auto c:constraint){
        c1 = to_string(c.first);
        c2 = to_string(c.second);
        i = s.find(c1); j = s.find(c2);
        if(abs(i-j)!=1){ return false;}
    }
 return true;
 }

 void permutation(int i, int l){

     if(i<l){
        for(int j=i;j<l;j++){
            swap(str[i],str[j]);
            permutation(i+1,l);
            swap(str[i],str[j]);
        }
     }else{
        s.insert(str);
     }

 }

void printthe(string x){
   // cout << "x-->  "  << x << endl;
    int l = 1;
    for(int i=0;i<8;i++){
        int j = (x[i]-'0'+0);
        //cout << j << " ";
        cout << cowmp[j];
        l++;
        if(l<=8)cout << '\n';
    }
    

}

int findKey(string s){
    for(auto m:cowmp){
        if(m.second==s) return m.first;
    }
    return 0;
}

void solve(){ 
  
  set<string> cow = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

  
  int i = 1;
  str = "";
  for(auto c:cow){
    str+=(to_string(i));
    cowmp[i] = c;
    i++;
  }
   
  permutation(0,8);

  int n;cin>>n;
  string temp,a,b;

  for(int i=0;i<n;i++){
      cin>>a;
      for(int i=0;i<4;i++)cin>>temp;
      cin>>b;
      int p,q; p = findKey(a); q = findKey(b);
      constraint.push_back({p,q});
     // cout << p << " " << q << endl;
  }

  for(auto x:s){
    if(issatisfied(x)){
        printthe(x);
        break;
    }
  }



}
 
 
int main(){
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ; cout.tie(0) ;
    cout.precision(20);


    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif 
    int T=1;//cin>>T;
    while(T--){
        solve();
        if(T)cout << endl;
    }
    return 0;
}
