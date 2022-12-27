/*
x&y  1&1 = 1 else 0
x|y  0|0 = 0 else 1
!x  !1 = 0, !0 = 1
x^y XOR

int 32
00000...1

补码
1 + x = 0000000000000
1 + 111111111111 = 000000000000
x + ? = 0000000000000

? = ~x + 1
(~x + 1) + x = 000000000000000

-n = ~n + 1

memset(f, 0x3F,sizeof f) arr,value,size
0x3F = INF = 00111111001111110011111100111111
0x3f3f3f3f * 2 < 0xffffffff

1 << n = 1 000...00 n-1 times = 2^n
n >> x = 1/(2^x)
*/

/*
a ^ b mod m

3^1000000 = ?

1000000 = 11110100001001000000
3^1 = 3
3^2 = 9
3^4 = 81
3^8 = 
3^16 =
...

it will take o(b) time for linear multiply 3*3*3*3*3...
we can optimize to o(log(b)) = multiply value by 3^k when 1<<k & b = 1
11110100001001000000 = 3^(2^20) * 3^(2^19) * 2^(2^18) ...



*/
#include <bits/stdc++.h> //not recommended i guess
#include <iostream>
using namespace std;


int apowbmodm(a,b,m){ //a,b,m < 10^9
  int res = 1%m; //mod m because if b = 0, m = 1, res should = 0 because a^0 = 1. If res = 1, we return 1 which is WA
  while(b){
    if(b&1){
      res = res * a*1ll % m //if value is 1, multiply a
    }
    a*=a*1ll; //we multiply a so that a = a^2^n
    b >>=1 //erase last bit of b, we dont have to deal with it anymore
  }
  return res;
}


/*
a * b mod m

= a+a+a+a+a...
3*1000000 = ?

1000000 = 11110100001001000000
a*1 = a
a*2 = a+a
a*4 = a+a+a+a
a*8 = a+a+a+a+a+a+a+a
a*b = a*(b-1)*2
...

same logic as last
it will take o(b) time for linear multiply a+a+a...
we can optimize to o(log(b)) = add value by a*(2^k) if 1<<k & b = 1

*/

long long atimesbmodm(long long a,long long b,long long m){ //a,b,m < 10^18
  while(b){
    if(b&1){
      res = (res+a)%m
    }
    a = a*2%m;
    b >>= 1
  }
  return res;
  
  
}

/*
1. Use XOR to get pairs
if a^x = b, then b^x = a
this is useful in graphs because we can quickly get edges

2. lowbit calculation

lowbit(1110010000) = 10000
*/

int lowbit(n){
  
  //~n + 1 = 0001101111 + 1 = 0001110000
  return (~n+1)&n; // 0001110000 & 1110010000 = 10000 = n&(-n)
}



