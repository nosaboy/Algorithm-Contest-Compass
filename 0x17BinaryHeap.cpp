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
