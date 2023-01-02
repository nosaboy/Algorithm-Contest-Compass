/*
Best Cow Fence
https://www.acwing.com/problem/content/description/104/

We can binary search on the answer. For each search, we see if there is abetter answer.
I didn't see a way to do this when I first got the problem, but maybe my binary search skills are just bad.
We can see if there is a better average by subtracting our answer from the entire array, we then see if 
there is a positive subarray. If so, there must be a better answer. We can find the maximum subarray sum
https://usaco.guide/silver/more-prefix-sums?lang=cpp. Of course, it has to be greater than k so we'll 
check for that as well. Then we binary search for maximum to find answer.


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
const int MOD = 1000000007;
 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    vector <long double> v;
    rep(i,0,n){
        long double num;
        cin>>num;
        v.pb(num);
    }
    long double lo = -1000000000;
	long double hi = 1000000000;
	long double ans;
	
	while (lo <= hi) {
		long double mid = (lo + hi) /2;
      
	
	
        long double a[n+1];
        a[0] = 0;
        rep(i,0,v.size()){
            a[i+1] = v[i]-mid;
            
            a[i+1]+=a[i];
          

        }


        long double max_subarray_sum = a[k];
        long double min_prefix_sum = a[0];
        for (int i = k; i <= n; i++) {
            // good manipulation to print only subarrays bigger or equal to k
            min_prefix_sum = min(min_prefix_sum, a[i-k]);
            max_subarray_sum = max(max_subarray_sum, a[i] - min_prefix_sum);
            
            
        }

		if(max_subarray_sum > 0){ //better answer
			lo = mid+0.0000001;
		}
		else{
 
			hi = mid-0.0000001;
			ans = mid;
		}
	}
    int ok= 1000*(ans/1.0);
    cout<<ok<<endl;
    
		
 
    
	
	return 0;
}
