/* 
Problem 1: https://www.acwing.com/problem/content/152/




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

int main() {
  string s;
  cin>>s;
  stack <pi> st;
  int itr =0;
  int ans =0;
  st.push({0,-1});
  rep(i,0,s.size()){
    if(s[i] == '('){
      st.push({1,i});
  
    }
    else if(s[i] == '{'){
      st.push({2,i});     
    }
    else if(s[i] == '['){
      st.push({3,i});
    }
    else if(s[i] == ']'){
      if(st.size() > 0 && st.top().first == 3){
        st.pop();
 
        
      }
      else{

        while(st.size()){
          st.pop();
        }
        st.push({0,i});
      }
      
    }
    else if(s[i] == '}'){
      if(st.size() > 0 && st.top().first == 2){
        st.pop();

        
      }
      else{
   
        while(st.size()){
          st.pop();
        }
        st.push({0,i});
      }
      
    }
    else if(s[i] == ')'){
      if(st.size() > 0 && st.top().first == 1){
        st.pop();

        
      }
      else{
      
        
        while(st.size()){
          st.pop();
        }
        st.push({0,i});
      }
      
    }
    
    if(st.size()){
      //cout<<i<<" "<<st.top().second<<endl;
      ans = max(ans,i - st.top().second);
    }
    
    
    
  }

  cout<<ans<<endl;

}




/* 
Problem 3:https://www.acwing.com/problem/content/154/

This is literally the largest histogram problem from stack but in 2d instead of 1d so I just made adjustments to the og code.

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

int main() {
  int n,m;
  cin>>n>>m;

  int a[n][m];
  rep(i,0,n){
    rep(j,0,m){
      char c;
      cin>>c;
      if(c == 'F'){
        a[i][j] = 1;

      }else{
        a[i][j] = 0;
      }
    }
  }
  rep(j,0,m){
    rep(i,1,n){
      a[i][j] += a[i][j] * a[i-1][j];
    }
  }
  /*
  rep(i,0,n){
    rep(j,0,m){
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }
  */
  ll ans =0;
  rep(i,0,n){
    stack <pi> st;
	
		int prev = -1;
		rep(j,0,m){
			if(a[i][j] >= prev){
				st.push({a[i][j] ,1});
				prev = a[i][j] ;
			}
			else{
				ll sum = 0;
				while(st.size() > 0 &&st.top().first > a[i][j]){
					sum += st.top().second;
					ans = max(ans, 1ll*st.top().first * sum);
					st.pop();
				}
			
				prev = a[i][j] ;
				st.push({a[i][j] , sum+1});
			}
		}
		ll sum = 0;
		while(st.size() > 0 ){
					sum += st.top().second;
					ans = max(ans, 1ll*st.top().first * sum);
					st.pop();
				}
    //cout<<ans<<endl;
		
  }
  cout<<ans*3<<endl;
}



/* 
Problem 5: https://www.acwing.com/problem/content/156/

Just use a multiset to keep track of min max

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

int main() {
  int n,k;
  cin>>n>>k;
  vi v;
  rep(i,0,n){
    int u;
    cin>>u;
    v.pb(u);
  }
  multiset <int> ms;

  rep(i,0,k){
    ms.insert(v[i]);
  }
  auto osa = ms.begin();
  auto nosa = ms.end();
  --nosa;
  vi l;
  vi r;
  l.pb(*osa);
  r.pb(*nosa);
  rep(i,1,n-k+1){
    ms.erase(ms.find(v[i-1]));
    ms.insert(v[i+k-1]);
    auto it = ms.begin();
    auto itr = ms.end();
    --itr;
    l.pb(*it);
    r.pb(*itr);
  } 
  rep(i,0,l.size()){
    cout<<l[i]<<" ";
  }
  cout<<endl;
  rep(i,0,l.size()){
    cout<<r[i]<<" ";
  }
  cout<<endl;
}


/*
Problem 7: https://www.acwing.com/problem/content/158/
Precompute hash of matrix

*/


