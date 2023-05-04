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



/*
Now we can consider the Huffman tree problem. But with k children
The greedy sol for k=2 will not work because given a tree, after we choose k minimum
numbers many times there might be 2 to k-1 nodes left at the last merge.
This is not optimal because we can choose any node from a lower merge and decrease the distance to the root

Therefore, a good greedy approach is to add '0s' to the bottom of the root as late as possible.
This way, we can get rid of the 2 to k-1 roots as early as possible(so we cannot do the above trick)
More specifically, we can say if n - m(k-1) = 1 for some 1, this will have the best answer because everything is filled up(to k nodes per parent)
We ge n-1 = m(k-1), so (n-1)%(k-1) = 0 for this to work. 
We want to add 0s to the # of nodes and increase n(size) until (n-1)%(k-1) = 0 & have k nodes every other merge(and 'fill' the rest with '0s' for optimal solution).








*/


/* Problem 4: https://www.acwing.com/problem/content/151/

This is just huffman tree with k nodes. 
Things to keep note:
we can just make it so that we choose k-1-(k-1) if (n-1)%(k-1) != 0 and choose k otherwise. 
Anything else will segfault or runtime

We store the length that the node has travelled for every node(it starts at 0), and sort by min(value, length) 
to get optimal answer for min value + min length overall(we always choose least lengths for every merge)



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
  ll n,k;
  cin>>n>>k;
  priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > pq;

  rep(i,0,n){
    ll u;
    cin>>u;
    pq.push({u,0});
    
  }
  
  bool yn = 0;

  while((n-1)%(k-1)){
    pq.push({0,0});
    n++;
  }
  ll ans = 0;
  while(pq.size() > 1){
    ll x;
    
      
      x = k;
    
    
    ll ok = 0;
      ll mx = 0;
      //cout<<1<<endl;
      while(x--){
      
       
       // cout<<ans<<" "<<pq.top().first<<" "<<pq.top().second<<endl;
        ok += pq.top().first;
        mx = max(mx, pq.top().second);
        pq.pop();
      }
      ans += ok;
      pq.push({ok,mx+1});
      
     
  }
  
  cout<<ans<<"\n"<<pq.top().second<<endl;

}



/*
Problem 5:

Observation 1: We must choose adjcent pairs only, because if pairs are not adjacent, it takes up less space and value if we choose adjacent pair inside.
Now it turns into this: we can just store all min lengths and find min sum of lengths such that no two pairs uses the same node.
Observation 2: Trying k=1, we get the ans = min number, 
k=2 yields ans = min number+min excluding neighbours, min(leftneighbour + minnotneighbour, rightneighbour + minnotneighbour)

We can further note that for a given minimum, we either choose that minimum and the next POSSIBLE minimum, or choose its left and right. 
This is because if the minimum is not in optimal ans, if we choose its left and not its right, we can choose min node to make it even more optimal.
Therefore, we must choose both left and right if minimum is not chosen. 

*/
