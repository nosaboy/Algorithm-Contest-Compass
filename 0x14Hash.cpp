/* 
Problem 1: https://dmoj.ca/problem/cco07p2
I think this problem is honestly mildly stright forward however I still have no clue how hashing plays a role in this
might want to look at other peoples explanations cause there is basically none in the book
I used the same solution as yxc in order to AC on DMOJ(no hashing) https://dmoj.ca/src/5470846
So ya time for string hashing ig idk
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
typedef pair<int, int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 1000000007;
 vi aj[100001];
bool cmp(vector <int>& mn, vector <int>& osa){
	rep(i,0,6){
	            if(mn[i] < osa[i]){
	                   return true;
	            }
	            else if(osa[i] < mn[i]){
	                return false;
	                
	            }
	        }
			return false;
}
bool uwu(int a, int b){
	return cmp(aj[a],aj[b]);
	
}
int main() {
	int n;
	cin>>n;
	vi ar;
	
	rep(i,0,n){
	    vi v;
		vi a;
	    rep(j,0,6){
	       int u;cin>>u;v.pb(u);
	       a.pb(u);
	    }
		reverse(a.begin(),a.end());
	    vi mx;
	    rep(l,0,6){
	        mx.pb(v[l]);
	    }
	    rep(j,1,6){
	        vi osa;
	        rep(l,j,j+6){
	               osa.pb(v[l%6]);
	        }
	        if(!cmp(mx,osa)){
				 rep(o,0,6){
	                    mx[o] = osa[o];  
	                }
			}

	    }

		vi mn;
	    rep(l,0,6){
	        mn.pb(a[l]);
	    }
	    rep(j,1,6){
	        vi osa;
	        rep(l,j,j+6){
	               osa.pb(a[l%6]);
	        }
			if(!cmp(mn,osa)){
				 rep(o,0,6){
	                    mn[o] = osa[o];  
	                }
			}
	        

	    }
		if(cmp(mn,mx)){
			rep(j,0,6){
				aj[i].pb(mn[j]);
			}
		}	
		else{
			rep(j,0,6){
				aj[i].pb(mx[j]);
			}
		}
		ar.pb(i);
		


	}

	sort(ar.begin(),ar.end(),uwu);
	rep(i,0,ar.size()-1){
		if(!cmp(aj[ar[i]], aj[ar[i+1]]) && !cmp(aj[ar[i+1]], aj[ar[i]])){
			cout<<"Twin snowflakes found.\n";
			return 0;
		}
	}
	cout<<"No two snowflakes are alike.\n";
}



/* 
String hashing: turning string into integer so it is easy to find and shi(goes from o(n) to o(1))
Assuming all char of string are lowercase alphabetical letter
we can view the string as a 26 base integer
Then we mod some q: this is the result after hashing.
This thinking will be our common hashing algo

The best base usually set is 131 or 13331. And we should set q to 2^64 - long long
For example the string = "abd" we can calculate as 1*131^2 + 2*131 + 4
if the number is too big it won't matter because long long n + a > 2^64 means n = (n+a)mod(2^64) because thats now ints and lls work in c++

Thus, the correct hashing of strings will look as follows when string s is all lowercase and a = 1
We can now represent a string as a hash from 0 - 2^64-1

*/

ULL h[1000011];
ULL p[1000011];
ULL hashi(string s){
  
  h[0]=0;
  p[0]=1;
  rep(i,1,s.size()+1){
     h[i] = h[i-1]*131 + s[i-1]-'a' + 1;
      p[i] = p[i-1]*131;
  } 
  rep(i,1,s.size()+1){
    cout<<h[i]<<endl;
  }  
  return h[s.size()];
  
  
}

/*

Now, we can compute all substring hashes in o(1) using the following:
we can find p[n] such that p[n]= 131^n in o(n), then:
h(l-r) = h(r)-h(l-1)*131^(r-l+1) = h(r)-h(l)*p[r-l+1];

An implementation is shown below with regards to the previous impl
*/

ULL get(int l, int r){
  return h[r]-h[l-1]*p[r-l+1];

}



/*
Problem 2: https://www.acwing.com/problem/content/140/

This is a slight modification of our code with o(1) query
We can just check if the hash values are the same for two substrings


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

ULL h[1000011];
ULL p[1000011];
ULL hashi(string s){
  
  h[0]=0;
  p[0]=1;
  rep(i,1,s.size()+1){
     h[i] = h[i-1]*131 + s[i-1]-'a' + 1;
      p[i] = p[i-1]*131;
  } 
  rep(i,1,s.size()+1){
    //cout<<h[i]<<endl;
  }  
  return h[s.size()];
  
  
}

ULL get(int l, int r){
  return h[r]-(h[l-1]*p[r-l+1]);

}

int main() {
	string s;
	cin>>s;
	hashi(s);
	int q;
	cin>>q;
	while(q--){
		int l,r,a,b;
		cin>>l>>r>>a>>b;
    if(get(l,r) == get(a,b)){
      cout<<"Yes\n";
    }
    else{
      cout<<"No\n";
    }
		//cout<<get(l,r)<<endl;
	}
}

/*




/*

Problem 3: https://www.acwing.com/problem/content/141/
This took me time to figure out coordinates and debug but the overall logic is not that bad
we can use binary search to calculate the largest length.
We have to divide this into odd and even length palindromes.

Code below:
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

ULL h[1000011];
ULL hr[1000011];
ULL p[1000011];
ULL hashi(string s){
  
  h[0]=0;
  p[0]=1;
  rep(i,1,s.size()+1){
     h[i] = h[i-1]*131 + s[i-1]-'a' + 1;
      p[i] = p[i-1]*131;
  } 
  rep(i,1,s.size()+1){
    //cout<<h[i]<<endl;
  }  
  return h[s.size()];
  
  
}
ULL rhashi(string s){
  
  hr[s.size()+1]=0;
  
  for(int i = (int)s.size();i>=1;i--){
     hr[i] = hr[i+1]*131 + s[i-1]-'a' + 1;
  } 
  rep(i,1,(int)s.size()+1){
    //cout<<h[i]<<endl;
  }  
  return h[s.size()];
  
  
}
ULL get(int l, int r){
  return h[r]-(h[l-1]*p[r-l+1]);

}
ULL getr(int l, int r){
  return hr[l]-(hr[r+1]*p[r-l+1]);

}
int main() {
	string s;
	cin>>s;
  int cnt = 0;
  while(s!= "END"){
    cnt++;
    int lo = 1;
    int hi = (int)s.size()/2+1;
    lo--;
    hashi(s);
    rhashi(s);
    //cout<<hr[8]<<" "<<h[6]<<" "<<getr(8,13)<<endl;
    while (lo < hi) {
      // find the middle of the current range (rounding up)
      int mid = lo + (hi - lo + 1) / 2;
      int yn = 0;
      
        rep(i,1,(int)s.size()+1){
          if(i == 9){
            //cout<<get(i-(mid/2-1), i)<<" "<<getr(i+1,i+mid/2)<<" "<<i-mid/2+1<<" "<<i<<" "<<i+1<<" "<<i+mid/2<<endl;
          }
          if(i-(mid-1) > 0 && i+mid <= (int)s.size() && get(i-(mid-1), i) == getr(i+1,i+mid)){
            yn = 1;
            break;
          }
        }
      
        
      
      
      if (yn) {
        // if mid works, then all numbers smaller than mid also work
        lo = mid;
      } else {
        // if mid does not work, greater values would not work either
        hi = mid - 1;
      }
    }
    int lol = lo;

     lo = 1;
     hi = (int)s.size()/2+1;
    lo--;
    while (lo < hi) {
      // find the middle of the current range (rounding up)
      int mid = lo + (hi - lo + 1) / 2;
      int yn = 0;
      
        rep(i,1,(int)s.size()+1){
          if(i == 9){
            //cout<<get(i-(mid), i-1)<<" "<<getr(i+1,i+mid)<<" "<<i-mid<<" "<<i-1<<" "<<i+1<<" "<<i+mid<<endl;
          }
          if(i-(mid) > 0 && i+mid <= (int)s.size() && get(i-(mid), i-1) == getr(i+1,i+mid)){
            yn = 1;
            break;
          }
        }
      
        
      
      
      if (yn) {
        // if mid works, then all numbers smaller than mid also work
        lo = mid;
      } else {
        // if mid does not work, greater values would not work either
        hi = mid - 1;
      }
    }

    cout<<"Case "<<cnt<<": "<<max(lol*2,lo*2+1)<<endl;
    cin>>s;
  }

		

}




/* 

Problem 4: https://www.acwing.com/problem/content/142/
For this problem, you can use hashing + binary search to search for common substrings.
First, we must sort strings by custom comparator.


AC Code as follows:
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

ULL h[1000011];
ULL hr[1000011];
ULL p[1000011];
ULL hashi(string s){
  
  h[0]=0;
  p[0]=1;
  rep(i,1,s.size()+1){
     h[i] = h[i-1]*131 + s[i-1]-'a' + 1;
      p[i] = p[i-1]*131;
  } 
  rep(i,1,s.size()+1){
    //cout<<h[i]<<endl;
  }  
  return h[s.size()];
  
  
}
ULL rhashi(string s){
  
  hr[s.size()+1]=0;
  
  for(int i = (int)s.size();i>=1;i--){
     hr[i] = hr[i+1]*131 + s[i-1]-'a' + 1;
  } 
  rep(i,1,(int)s.size()+1){
    //cout<<h[i]<<endl;
  }  
  return h[s.size()];
  
  
}
ULL get(int l, int r){
  return h[r]-(h[l-1]*p[r-l+1]);

}
ULL getr(int l, int r){
  return hr[l]-(hr[r+1]*p[r-l+1]);

}
int n;
string s;
bool cmp(int a, int b){
  int lo = 0;
  int hi = min(n-a,n-b);
  
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
    //cout<<a<<" "<<a+mid-1<<" "<<get(a,a+mid-1)<<" "<<b<<" "<<b+mid-1<<" "<<get(b,b+mid-1)<<endl;
		if (get(a+1,a+mid) == get(b+1,b+mid)) {
			// if mid works, then all numbers smaller than mid also work
			lo = mid;
		} else {
			// if mid does not work, greater values would not work either
			hi = mid - 1;
		}
	}
  //cout<<a<<" "<<b<<" "<<lo<<" "<<min(n-a,n-b)<<endl;
  if(lo == min(n-a,n-b)){
    return n-a < n-b;
  }
  else{
    return s[a+lo]<s[b+lo];
  }
}
int main() {
	
	cin>>s;
  n = s.size();
  hashi(s);
  
  rhashi(s);
  vi v;
  rep(i,0,n){
    v.pb(i);
  }
	sort(v.begin(),v.end(),cmp);
  rep(i,0,n){
    cout<<v[i]<<" ";
  }
  cout<<endl;
  cout<<0<<" ";
  rep(i,0,v.size()-1){
    int a = v[i];
    int b = v[i+1];
    int lo = 0;
    int hi = min(n-a,n-b);
    
    while (lo < hi) {
      // find the middle of the current range (rounding up)
      int mid = lo + (hi - lo + 1) / 2;
      //cout<<a<<" "<<a+mid-1<<" "<<get(a,a+mid-1)<<" "<<b<<" "<<b+mid-1<<" "<<get(b,b+mid-1)<<endl;
      if (get(a+1,a+mid) == get(b+1,b+mid)) {
        // if mid works, then all numbers smaller than mid also work
        lo = mid;
      } else {
        // if mid does not work, greater values would not work either
        hi = mid - 1;
      }
    }
    //cout<<a<<" "<<b<<" "<<lo<<" "<<min(n-a,n-b)<<endl;
    cout<<lo<<" ";
  }
  cout<<endl;
}
