/*
It like a tree
We can make a root and start at it
For every string, we scan every letter and the current node is the node before scanning.
If the letter in the position already exists as a child, we point to it
Otherwise, we make a new node(child, below current node) and connect it to that.
We end it with the string when finished scanning, marked as end
Now, we can find if any string exists.
Scanning the string, we find if there exists a child with that character
We move to the child if there is and declare string doesn't exist if there isn't

This is pretty useful when trying to find substrings
O(NC)
*/
int triear[1000005][26], tot =1; //base, assuming string is lowercase alphabet letters
int endi[1000005];
int ok = 0;
void trieinsert(string s){
  int p = 1;
  rep(i,0,(int)s.size()){
    if(triear[p][s[i]-'a'] == 0){
      
      tot++;
      triear[p][s[i]-'a'] =tot;
    }
    p = triear[p][s[i]-'a'];
  
  }
  endi[p]++;

}

bool triesearch(string s){
  int p = 1;
  rep(i,0,(int)s.size()){
    ok+=endi[p];
    if(triear[p][s[i]-'a'] == 0){
      
      return false;
    }
    
    p = triear[p][s[i]-'a'];
    
  }
  ok += endi[p];
  return endi[p];
  
}

/* 

Problem 1: https://www.acwing.com/problem/content/144/
This is literally just trie except you add a counter[MAXN][26] 
to count the number of strings ending in counter[MAXN][26] and
add them together.

Thus, modifying the functions, we get the above
*/


/*

Problem 2: https://www.acwing.com/problem/content/145/


We can make o(n * 32) by looking at every number as a binary string
For every binary number, we can find the max xor using greedy algorithm
Storing the number in the trie, we can try to find the biggest avaliable
bit that matches the reverse of the number(greedy, maximum xor of the number).
Therefore, we traverse the trie which has height 32 always because every string
is length 32(to be safe)


Impl below:

Also note that out of bounds may occur so we have to set the pointer to max(32*N = 32 * 10^5 + 1) to avoid segfault or out of bounds RTE
*/

#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 1000000007;
ll triear[3200005][2], tot =1; //base, assuming string is lowercase alphabet letters
ll endi[3200005];
string ok ="";
string dectobi(ll n)
{
    // array to store binary number
    string bi="";
 
    for (int i = 32; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1)
          bi +='1';
        else
          bi +='0';
    }
    // printing binary array in reverse order
    return bi;
}
void trieinsert(string s){
  ll p = 1;
  rep(i,0,(int)s.size()){
    if(triear[p][s[i]-'0'] == 0){
      
      tot++;
      triear[p][s[i]-'0'] =tot;
    }
    p = triear[p][s[i]-'0'];
  
  }
  endi[p]++;

}

bool triesearch(string s){
  ll p = 1;
  rep(i,0,(int)s.size()){

    if(triear[p][s[i]-'0'] == 0){
      if(s[i] == '0' ){
        ok += '1';
        p = triear[p][1];
      }
      else{
        ok += '0';
        p = triear[p][0];
      }
      
    }
    
    else{
      ok += s[i];
      p = triear[p][s[i]-'0'];
    }
    
    
  }

  return endi[p];
  
}


int main() {
	int n;
  cin>>n;

  vi v;
  ll ans = 0;
  rep(i,0,n){
    ll u;
    cin>>u;
  
   
    string nosa = dectobi(u);
    
    string osa="";
    for(int i = 0;i<nosa.size();i++){
      if(nosa[i] == '0'){
        osa+='1';
      }
      else{
        osa +='0';
      }
    }
    ok="";
    trieinsert(nosa);
    triesearch(osa);
    ll mx = 0;
    //cout<<nosa.size()<<" "<<ok.size()<<endl;
    rep(i,0,min(ok.size(),nosa.size())){
      if(ok[i] != nosa[i]){
        mx += 1<<(32-i);
      }
    }
    //cout<<mx<<endl;
    ans = max(ans,mx);
  }
  cout<<ans<<endl;


  

}


/*

Problem 3: https://www.acwing.com/problem/content/146/
We can visualize the problem as such: 
the xor path fro a to b = (the xor path from a to root) xor (the xor path from b to root)
We can find the xor path of node a to root as follows:
xorpath[a] = xorpath[parentofa] xor weight[parentofa][a]
This will then turn into the maximum xor between two numbers problem

Impl below AC first try:
*/

#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef unsigned long long ULL;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 1000000007;
ll triear[3200005][2], tot =1; //base, assuming string is lowercase alphabet letters
ll endi[3200005];
string ok ="";
string dectobi(ll n)
{
    // array to store binary number
    string bi="";
 
    for (int i = 32; i >= 0; i--) {
        ll k = n >> i;
        if (k & 1)
          bi +='1';
        else
          bi +='0';
    }
    // printing binary array in reverse order
    return bi;
}
void trieinsert(string s){
  ll p = 1;
  rep(i,0,(int)s.size()){
    if(triear[p][s[i]-'0'] == 0){
      
      tot++;
      triear[p][s[i]-'0'] =tot;
    }
    p = triear[p][s[i]-'0'];
  
  }
  endi[p]++;

}

bool triesearch(string s){
  ll p = 1;
  rep(i,0,(int)s.size()){

    if(triear[p][s[i]-'0'] == 0){
      if(s[i] == '0' ){
        ok += '1';
        p = triear[p][1];
      }
      else{
        ok += '0';
        p = triear[p][0];
      }
      
    }
    
    else{
      ok += s[i];
      p = triear[p][s[i]-'0'];
    }
    
    
  }

  return endi[p];
  
}

vi aj[100005];
int cnt[100005]={0};
int vis[100005];
map <pair<int,int>,int> mp;
vi v;
void dfs(int n){
  vis[n]=true;
  v.pb(cnt[n]);
  rep(i,0,aj[n].size()){
    if(!vis[aj[n][i]]){
      cnt[aj[n][i]] = (cnt[n]^mp[{n,aj[n][i]}]);
      dfs(aj[n][i]);
    } 
    
  }

}

int main() {
	int n;
  cin>>n;

  rep(i,0,n-1){
    int u,ur,w;
    cin>>u>>ur>>w;

    aj[u].pb(ur);
    aj[ur].pb(u);
    mp[{u,ur}]=w;
    mp[{ur,u}]=w;
  }
  dfs(0);
  ll ans = 0;
  rep(i,0,v.size()){
    ll u = v[i];
  
   
    string nosa = dectobi(u);
    
    string osa="";
    for(int i = 0;i<nosa.size();i++){
      if(nosa[i] == '0'){
        osa+='1';
      }
      else{
        osa +='0';
      }
    }
    ok="";
    trieinsert(nosa);
    triesearch(osa);
    ll mx = 0;
    //cout<<nosa.size()<<" "<<ok.size()<<endl;
    rep(i,0,min(ok.size(),nosa.size())){
      if(ok[i] != nosa[i]){
        mx += 1<<(32-i);
      }
    }
    //cout<<mx<<endl;
    ans = max(ans,mx);
  }
  cout<<ans<<endl;


  

}




