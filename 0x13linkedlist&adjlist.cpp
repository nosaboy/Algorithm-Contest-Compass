/*
Problem 1: https://www.acwing.com/problem/content/138/
this is a free problem with sets tbh
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
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 1000000007;
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


void solve(){
    int n;
    cin>>n;
    multiset <pi> v;
    v.insert({-20000000005,-1});
    v.insert({20000000005,-1});
    rep(i,0,n){
        ll u;
        cin>>u;
        
        if(i > 0){
            auto it = v.upper_bound({u,-2});
            auto itr = v.lower_bound({u,-2});
            --itr;
            pi itt = *it;
            pi ittr = *itr;
            
            if(abs(u-itt.first) < abs(u-ittr.first)){
                cout<<abs(u-itt.first)<<" "<<itt.second<<endl;
            }
            else{
                cout<<abs(u-ittr.first)<<" "<<ittr.second<<endl;
            }
        }
        v.insert({u,i+1});
    }
  
}

int main(){
	auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t=1;
    

    while(t--){
        solve();
    }
  
    
		
 
    
	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
	return 0;
}



/*
you can also just sort then find l and r to solve this

*/

/*
Problem 2: find median in data stream
all solvable with multiset or ordered lol

*/
