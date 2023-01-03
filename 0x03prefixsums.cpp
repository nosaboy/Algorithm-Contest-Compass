/*
Tallest Cow
http://poj.org/problem?id=3263
notice that there will be no intersection of cows
using prefix sums we can set a upper bound for the cows


*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int main(){
  int n,j,h,r;
  cin>>n>>j>>h>>r;
  int ans[10005];
  memset(ans,0,sizeof ans);
  set <pair<int,int>> mp;
  for(int i = 0;i<r;i++){
    int a,b;
    cin>>a>>b;
    vector <int> v;

    v.push_back(a);
    v.push_back(b);
    sort(v.begin(),v.end());
    if(!mp.count({v[0],v[1]})){
      mp.insert({v[0],v[1]});
      mp.insert({v[1],v[0]});
      if(v[1] - v[0] > 1){
        ans[v[0]+1]--;
        ans[v[1]]++;
      }
    }
    
  }
  
  for(int i = 1;i<=n;i++){
    h+=ans[i];
    cout<<h<<endl;
  }
  return 0;
}
