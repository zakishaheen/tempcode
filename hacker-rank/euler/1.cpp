#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long calculateExoticSumLowerThan(long N);

//https://www.hackerrank.com/contests/projecteuler/challenges/euler001
int main() {
  int T = 0;
  cin>>T;

  for(int i=0;i<T;i++){
    long N = 0;
    cin>>N;
    cout<<calculateExoticSumLowerThan(N)<<endl;
  }
  
  return 0;
}
/*
for example for 100 100
find the multiple of 3: 99 - 3*1 + 3*2 + 3*3 + .... 3*32+3*33 = 3*(1+2+3+4+5....33) = n*(n+1)/2
similarly for 5 - find the largest multiple of 5 and do the math. 

and then delete the ones that are multiples of both. 
*/

long sumUpTo(long N){
  return (N * (N+1)) / 2;
}


long calculateExoticSumLowerThan(long N){
  long result = 0;
  
  //find largest multiple of 5 upto N
  long mul3 = (N-1) / 3;
  long mul5 = (N-1) / 5;
  long mul15 = (N-1) / 15;
    
  result = 3 * sumUpTo(mul3) + 5 * sumUpTo(mul5);
  result -= 15 * sumUpTo(mul15);
  
  return result;
  
}

