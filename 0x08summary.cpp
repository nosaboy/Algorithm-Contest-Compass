/* Problem 1: https://www.acwing.com/problem/content/118/

Brute force recursion


#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
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
const int MAX_N = 1000;


int main() {
	int grid[4][4];
	rep(i,0,4){
		string s;
		cin>>s;
		rep(j,0,4){
			if(s[j] == '-'){
				
				grid[i][j] = 1;
				
			}
			else{
				grid[i][j] = 0;
			}
		}
	}
	vector <pi> ans;
	int moves = 1000000;
	int dady = 131072;
	rep(c,0,131072){
		int pp[4][4];
		int d[4][4];
		memset(d,0,sizeof(d));
		rep(i,0,4){
			rep(j,0,4){
	
				
				d[i][j] = grid[i][j];
				
			}
		}
		rep(j,0,16){
			
			if((1<<j) & c){
				pp[(j/4)][(j%4)] = 1;
			}
			else{
				pp[(j/4)][(j%4)] = 0;
			}
		}
		rep(i,0,4){
			rep(j,0,4){
				if(pp[i][j] == 1){
					rep(l,0,4){
						if(l != j){
							d[i][l] = 1-d[i][l];
						}
						
					}
					rep(l,0,4){
						d[l][j] = 1-d[l][j];
					}
				}
			}
		}
		int yn = 1;
		rep(i,0,4){
			rep(j,0,4){
				
				if(d[i][j] == 0){
					yn = 0;
				
				}
			}
			
		}
		vector <pi> v;
		if(yn){
			rep(i,0,4){
				rep(j,0,4){
					if(pp[i][j]){
						v.pb({i+1,j+1});
					}
				}
			}
			if(v.size() < moves){
				ans.clear();
				rep(i,0,v.size()){
					ans.pb({v[i].first,v[i].second});
				}
				moves = v.size();
			}
			
		}
	}
	cout<<moves<<endl;
	rep(i,0,ans.size()){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
	}
	
}



*/

/* Problem 2: https://www.acwing.com/problem/content/119/ too lazy to impl simulation + cant read problem


*/


/* Problem 3: https://www.acwing.com/problem/content/120/ I've done fractals on a ccc problem before so its ok

*/


/* Problem 4: https://www.acwing.com/problem/content/121/   "classic problem"

  


*/
