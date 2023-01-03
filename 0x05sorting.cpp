
/*
Cinema
https://codeforces.com/contest/670/problem/C
submission: https://codeforces.com/contest/670/submission/187674171
We should count all languages then use a greedy algorithm to determine the answer no sorting involved



where to build storage
https://www.acwing.com/problem/content/106/

the optimal length is the mid lenght as we can use simple logic to determine this
so sort all elements and determine length from every store to the middle store

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
const int MOD = 998244353;
 
int main(){
  int n;
    cin>>n;
    vi v;
    rep(i,0,n){
        int num;
        cin>>num;
        v.pb(num);
    }
    int ans = 0;
    sort(v.begin(),v.end());
    if(n%2 == 1){
        rep(i,0,n){
            ans += abs(v[n/2] - v[i]);
        }
        cout<<ans;
    }
    else{
        rep(i,0,n){
            ans += abs((v[n/2]) - v[i]);
        }
        cout<<ans;
    }
  return 0;
}


/*
Running Median

I dont think this is the hardest thing ever, but it is definately challenging
if you dont know query data structures. I used multisets to keep track of the
median by having two multisets. One is lower, one is higher. Then I print the
median after


*/

int main(){
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>m>>n;
    multiset<int> v;
    multiset <int> l;
    vi ans;
    rep(i,0,n){
      int num;
      cin>>num;
      if(v.size() > 0){
        auto blt = v.end();
        --blt;
  
        if(num > *blt){
          l.insert(num);
        }
        else{
          v.insert(num);
        }
        
      }
      else{
        v.insert(num);
      }
      
      if(i%2 == 0){
        while(v.size() > l.size()){
          auto it = v.end();
          --it;
          l.insert(*it);
          v.erase(v.find(*it));
          
        }
        while(l.size() > v.size()){
          auto it = l.begin();
        
          v.insert(*it);
          l.erase(l.find(*it));
          
        }
        auto itr = v.end();
        --itr;
        ans.pb(*itr);
      }
    }
    cout<<m<<" "<<ans.size();
    rep(i,0,ans.size()){
      if(i%10 == 0){
        cout<<endl;
      }
      cout<<ans[i]<<" ";
    }
    cout<<endl;
  }
  
    
    
  return 0;
}

/*
ill do distributing candies tommorrow
looks hard lol


*/
