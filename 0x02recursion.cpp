/*
Generating subsets
1<=n<=20
One way is by using the binary representation of every number < 2^20 to represent if the number is included in the subset
But we can also use recursion

*/

#include <iostream>
#include <cstring> //memcpy
using namespace std;
int n,m;
//starting is gensubsets(0,0), gensubsets(where we are in the array, binary representation whether we use a number in the array)
void gensubsets(int u,int state){
  if(u == n){
    for(int i = 0;i<n;i++){
      if(1<<i & state == 1){
        cout<<i+1<<" ";
        
      }
    }
    cout<<endl;
    return;

  }
  gensubsets(u+1,state); //dont pick number
  gensubsets(u+1,state|1<<u); //pick number
  

}

/*
Generating subsets with m values in it
0<=n+(n-m)<=25
n > 0
0<=m<=n


starting state = gensubsetswithm(0,0,0)
sum is how many numbers we picked already

*/

void gensubsetswithm(int u,int state,int sum){
  if(sum + n = u < m){ //we can not pick m numbers even if we pick every number from now on, thus this state is impossible so we return
    return;
  }
  if(sum == m){ //we just print it

    for(int i = 0;i<n;i++){
      if(1<<i & state == 1){
        cout<<i+1<<" ";
        
      }
    }
    cout<<endl;
    return;

  }
  
  gensubsetswithm(u+1,sum+1,state|1<<u); //pick number
  gensubsetswithm(u+1,sum,state); //dont pick number

}

/*
generate all permutation of n numbers

1<=n<=9

we choose something that was not picked before
*/
#include <vector>
//state is did we pick this number before? Represented in binary
//starting state is genpermutations(0,0)
vector <int> path;
void genpermutations(int u,int state){
  if(u == n){
    for(auto x:path){
      cout<<x<<" ";
    }
    cout<<endl;
    return;

  }
  for(int i = 0;i<n;i++){
    if(!(state&1<<i)){ //if we did not choose this before
      path.push_back(i+1);
      genpermutations(u+1,state|(1<<i));
      path.pop_back(); //back tracking
    }
  }  

}


/*
Switching Lights
Given 5x5 matrix, you can turn a light to the opposite state, but if you do so the lights above, 
below, left, and right will also be turned to the opposite state. Can you make every light turn on with
6 or fewer moves? Print min moves or -1 if impossible

Consider the first column
if the column is 0, we know the light below it has to be switched(we are forced). After we simulate switching every light
such that the first column is all lit up, we can move onto the next column. Notice that the next column also 
follows the above rule. We can count the lights we switched. Thus, if our light switching exceeds 6 or the end result is impossible
(when we are at the nth column and there is a 0 in the nth column) we print -1, else print min moves


*/

char g[10][10];
//middle, up, right, down, left
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
void turn(int x,int y){ //we switch this light x,y
  for(int i = 0;i<5;i++){
    int a = x+dx[i];
    int b = y+dy[i];
    if(a >= 0 && a < 5 && b >= 0 && b < 5){
      g[a][b] ^= 1; //= '0' +!('1' - g[a][b]);
    }

  }

}

void work(){
  int ans = 0x3F;
  for(int k = 0;k< 1<<5;k++){
    char backup[10][10];
    memcpy(backup,g,sizeof g);
    for(int i = 0;i<5;i++){ //for the first column, we check every possible on and off state, then calculate the answer after which is fixed
      if(k >> j & 1){
        res++;
        turn(0,j);
      }
        
    }
    for(int i = 0;i<4;i++){ //simulate on and off switching with 'forced' answer
      for(int j = 0;j<5;j++){
        if(g[i][j] == '0'){ 
          res++;
          turn(i+1,j); //g[i][j] will turn into a 1 after this
        }
      }
    }
    bool is_one = true; //check if the last column is all '1's
    for(int i = 0;i<5;i++){
      if(g[4][i] == '0){
        is_one = false;
      }
    }
    if(is_one){ //if state is possible we take the minimum of answer
      ans = min(ans,res);
    }
    memcpy(g, backup, sizeof g)
  }
  if(ans > 6){
    ans = -1
  }
  return ans;

}

/*
Strange Hanoi Tower
n(n <= 12) disks put into 4 places for towers marked A,B,C,D
from A -> D
We need to calculate all minimum moves from n = 1->12
if there are 3 places
d[1] = 1; just move it
d[2] = 3
d[3] = d[2]*2 +1 
d[i] = move d[i-1] to second tower, move ith disk to third tower, move d[i-1] to third tower = d[i-1]*2 + 1

for 4 towers, we fix some value j such that was can move j to the 3rd tower, move the remaining n-j to the 4th tower, then move j disks to the fourth tower
we can use dp

*/


void toh(int u){
  int d[15],f[15];
  
  d[1] = 1;
  //threes
  for(int i = 2;i<=12;i++){
    d[i] = d[i-1]*2 + 1;
  }
  memset(f,0x3f,sizeof f)
  f[0] = 0; //0 steps to put 0 disks
  for(int i = 0;i<=12;i++){
    for(int j = 0;j<i;j++){ //we fix the number of disks we want to have on the fourth tower
      f[i] = min(f[i],2*f[j] + d[i-j]); //explanation above
    }

  }
  return f[u];
}

int drivertoh(){
  for(int i = 1;i<=12;i++){
    cout<<toh(i)<<" ";
  }
  cout<<endl;
  return 0;
}


/*
sum of the factors of a^b
Given a^b, find the sum of the factors of n mod 9901


we can find the prime factor of a
a = p1^k1 * p2^k2 ... * pn^kn
a^b = p1^(b*k1) * p2^(b*k2) ... * pn^(b*kn)
We will use choose some number 2^(0->ki) to get the factor, then add it up.
sum of factors formula : (p1^0 + p1&1 + ... + p1^k1) * (p2^0 + p2&1 + ... + p2^k2) ... * (pn^0 + pn&1 + ... + pn^kn)
we focus on (p1^0 + p1&1 + ... + p1^k1) = sum(p,k)
This would normally be o(k) but we can do better.
use some smart math manipulation to get

if k is odd we can do the following
sum(p,k) = p^0 + p&1 + ... + p^k
= p^0 + p&1 + ... + p^(k-1/2) + p^(k/2+1)(p^0 + p&1 + ... + p^(k-1/2))
= (1+p^(k/2+1))*sum(p,k-1/2)
if k is even we do p*(sum(p,k-1)) + 1
*/

int sumoffactors(int p,int k){
  if(k == 0){
     return 0;
  }
  if(k%2 == 1){
    return (1+pow(p,k/2+1))*sum(p,(k-1)/2) % 9901;
    //it is favorable to write your own pow function provided by the previous module
  }
  else{
    return (p% 9901 *sum(p,k-1) + 1)% 9901;  
  }
  
  

}

int driverforfactors(){ //mod 9901
  int a,b;
  cin>>a>>b;
  int res = 1;
  for(int i = 0;i<= a;i++){
    int cnt = 0;
    while(a%i == 0){
      a/=i;
      cnt++;
    }
    if(cnt > 0){
      res =res * sumoffactors(i,cnt*b) % 9901;
    }
    
  }

  if(a == 0) res = 0;

  return 0;
}
