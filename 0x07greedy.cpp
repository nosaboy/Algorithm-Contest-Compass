/*
First problem https://www.acwing.com/problem/content/112/ idk man kinda hard to prove


*/



/* the second problem https://www.acwing.com/problem/content/113/ is just room allocation from cses
In the optimal grouping the ending of a interval will always be smaller than the begining of interval after it. So its is optimal to sort
in begining time an go through. Just take the earliest ending cause there is no point in taking a later ending because all the interval beginings
after it are going to be bigger.
I should use a priority queue
*/
/*

int main() {
	int n;
	cin>>n;
	int ans = 0;	
	vector<tuple<int,int,int>> v;
	multiset<int> ms;
	vector <pair<int,int>> rooms;
	map <int,int> m;
	ms.insert(0);
	int room = 1;
	int ar[n];
	int comp = 1;
	vector <int> aj[200005];
	for(int i = 0;i<n;i++){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b,i});
		if(m[b] == 0){
			m[b] = comp;
			comp++;
		}
		
	}
	sort(v.begin(),v.end());
	for(int i = 0;i<n;i++){
		
		int a = get <0>(v[i]);
		int b = get<1>(v[i]);
		int num = get<2>(v[i]);;
		auto it = ms.lower_bound(a);
		--it;
 
		if(*it == 0){
			ans = max(ans,room);
			ar[num] = room;
			aj[m[b]].push_back(room);
			ms.insert(b);
			room++;
	
		}
		else{
			ar[num] = aj[m[*it]][0];
			aj[m[*it]].erase(aj[m[*it]].begin());
			aj[m[b]].push_back(ar[num]);
			ms.erase(ms.find(*it));
			ms.insert(b);
		}
		
	}
	cout<<ans<<endl;
	for(int i = 0;i<n;i++){
		cout<<ar[i]<<endl;
	}
	return 0;
}













*/



/* Problem 3: https://www.acwing.com/problem/content/114/ at first I thought all radar lengths are different so I was panicking a bit
but this is just simple greedy. One thing to notice is we can turn everything into intervals, with the begining being the smallest point
which a radar can contain this points and the ending being the largest. We can get this using distance formula. Im pretty sure this
is just longest interval such that nothing is between each other, so classic scheduling . Idk tho.
Sort by ending, go through the array and only add a point if prev point isnt in the interval
We will always set a new point as the last point that contains the interval
*/


/* 
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <tuple> 
#include <map>  
using namespace std;
 

const double eps = 1e-6;
int main(){
	
	int n;
	double d;
	cin>>n>>d;
	
	
	
	vector <pair<double,double>> v; 

	for(int i = 0;i<n;i++){
		double num1,num2;
		cin>>num1>>num2;
		num2 = abs(num2-0);
		if(abs(num2) > d){
		    cout<<-1;
		    return 0;
		}
		double ttv = abs(sqrt((d*d) - (num2*num2)));
		v.push_back({num1+ttv,num1-ttv});
        
 
	}
	sort(v.begin(),v.end());
	int i = 0;
	int ans = 0;
	double point = -10001;
	for(int i = 0;i<v.size();i++){
	   if(point >= v[i].second && point <= v[i].first){
	       continue;
	   }
	   else{
	       point = v[i].first;
	       ans++;
	   }
	}
	cout<<ans;
 
	return 0;
}
*/



/* Problem 4: https://www.acwing.com/problem/content/116/

"greedy involves guessing"- yxc
this is very mathy...
first we try to find a optimal way to swap adjacent ppl. We list out an equation for both values. 
We find that we should swap if for some pair of pairs a and b, it satifies max(b.second, a.first * a.second) < max(b.first * b.second, a.second)
We can use custom comparators for this.
It remains to find a way to calculate mult and div larger than 10^18
I think that this should be really easy to implement but rarely seen(except for that one fib cco problem). So I will leave it at that 
and do it when I have time



*/



/*


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
const ll MOD = 998244353;
 
bool cmp(pair<int,int> a, pair<int,int> b){
	return max(b.second, a.first * a.second) < max(b.first * b.second, a.second);
}
int main(){
	
	int n;

	cin>>n;
	pair <int,int> k;
	cin>>k.first>>k.second;
	vector <pair<int,int>> v;
	rep(i,0,n){
		int a,b;
		cin>>a>>b;
		v.pb({a,b});
	}
	sort(v.begin(),v.end(),cmp);
	int cnt = k.first;
	int ans = 0;
	rep(i,0,v.size()){
		ans = max(ans, cnt/v[i].second);
		cnt *= v[i].first;
	}
	cout<<ans<<endl;

 
	return 0;
}
*/



