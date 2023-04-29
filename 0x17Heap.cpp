/* Problem 1:

This problem does not actually need binary heap because we can just use
multiset to simulate the deletion process.
We can first sort the best prices. Then, we can use a greedy algorithm
to choose the maximum number avaliable. 
Proof: At any given state, everything taken up by some day will be bigger
than the current price. Thus, if we HAD to delete anything, it will be less
optimal because the result will still be the same after.
Thus, we can keep a multiset of avaliable days to choose from. For every product,
we can find the lower_bound of days(latest day avaliable) and choose it as that. 
Then, we delete the day from ms. This way, it can be solved with greedy + multiset.
Impl below:

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
  int n;
  while(cin>>n){
    
    multiset <int> s;
    int osa[10005]={0};
    rep(i,1,10005){
      osa[i] = i;
      s.insert(i);
    }
    vector <pi> v;
    rep(i,0,n){
      int a,b;
      cin>>a>>b;
      v.pb({a,b});
    }
    sort(v.rbegin(),v.rend());
    orderedMultiset <int> ms;
    int ans = 0;
    rep(i,0,n){
      int ok = *s.lower_bound(osa[v[i].second]);
      auto nosa = s.upper_bound(osa[v[i].second]);

      //cout<<ok<<" "<<v[i].first<<" "<<v[i].second<<endl;
      if(nosa != s.begin()){
        --nosa;
        ans += v[i].first;
        ms.insert(v[i].second);
        s.erase(s.find(*nosa));
      }
      
    }
    cout<<ans<<endl;
  }


}



/* Problem 2: https://www.acwing.com/problem/content/148/

We can solve this in o(mnlogn).
First we can consider a case where m = 2. After getting the n minimum sums, we can sort then compare it with m = 3 etc...
So we must get the n minimal elements of 2 array length n inat most o(nlogn) time. Given the two arrays are a and b:
We can use the following strategy: Sort a in ascending order. Then for every element in b, we can get {a0+bi, j} into a priority queue.
Then, the pq will get the minimum element. Because every element a0bi <= ajbi where j>0, it will always be the min that has bi as an element.
Therefore, after eliminating the minimum element from pq and storing in vector, we can then insert aj+1bi etc...

After getting n element, we sort the vector.
Because  there is no "Remove" function and only "Extract", "Insert", "Get_min", pq will suffice
Impl below:
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
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vi a[n];
    
    rep(i,0,n){
      rep(j,0,m){
        int u;
        cin>>u;
        a[i].pb(u);
        
      }
    }


    sort(a[0].begin(),a[0].end());
    vector <int> ans[n];
    rep(i,0,m){
      ans[0].pb(a[0][i]);
    }
    rep(i,1,n){
      priority_queue <pi, vector<pi>, greater<pi>> pq;
      rep(j,0,m){
        pq.push({a[i][j]+ans[i-1][0],0});
        //cout<<a[i][j]+ans[i-1][0]<<endl;
      }
      
      int ok = m;
      while(ok--){
        pi osa = pq.top();
        pq.pop();
        ans[i].pb(osa.first);
        pq.push({osa.first-ans[i-1][osa.second]+ans[i-1][osa.second+1], osa.second+1});
      }
      
    
    }
    rep(j,0,m){
        cout<<ans[n-1][j]<<" ";
      }
      cout<<endl;
  }
	

  

}





/* Problem 3: https://www.acwing.com/problem/content/150/
Other wise known as Huffman Algo

We can always choose  the least two values and merge it because then it will turn into the same problem
whoever else it merges with will always be worst



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
  int n;
  cin>>n;
  vi v;
  priority_queue<int, vector<int>, greater<int> >pq;
  rep(i,0,n){
    int u;
    cin>>u;
    pq.push(u);
  }
  int ans = 0;
  while(pq.size()>1){
    int cnt = pq.top();
    pq.pop();
    cnt += pq.top();
    pq.pop();
    ans += cnt;
    pq.push(cnt);
  }
  cout<<ans<<endl;
    

}



/* Problem 4: https://www.acwing.com/problem/content/151/



