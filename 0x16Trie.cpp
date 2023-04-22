/*
It like a tree
We can make a root and start at it
For every string, we scan every letter and the current node is the node before scanning.
If the letter in the position already exists as a child, we point to it
Otherwise, we make a new node(child, below current node) and connect it to that.
We end it with the string when finished scanning, marked as end
Now, we can find if any string exists.
Scanning the string, we find if there exists a child with that character
We move to the child if there is and declare string doesn't exist if there isn't

This is pretty useful when trying to find substrings
O(NC)
*/
int triear[1000005][26], tot =1; //base, assuming string is lowercase alphabet letters
int endi[1000005];
int ok = 0;
void trieinsert(string s){
  int p = 1;
  rep(i,0,(int)s.size()){
    if(triear[p][s[i]-'a'] == 0){
      
      tot++;
      triear[p][s[i]-'a'] =tot;
    }
    p = triear[p][s[i]-'a'];
  
  }
  endi[p]++;

}

bool triesearch(string s){
  int p = 1;
  rep(i,0,(int)s.size()){
    ok+=endi[p];
    if(triear[p][s[i]-'a'] == 0){
      
      return false;
    }
    
    p = triear[p][s[i]-'a'];
    
  }
  ok += endi[p];
  return endi[p];
  
}

/* 

Problem 1: https://www.acwing.com/problem/content/144/
This is literally just trie except you add a counter[MAXN][26] 
to count the number of strings ending in counter[MAXN][26] and
add them together.

Thus, modifying the functions, we get the above
*/


/*

Problem 2: https://www.acwing.com/problem/content/145/




*/



