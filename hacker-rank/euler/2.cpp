#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long  calculateExoticSumLowerThan( long N);

//https://www.hackerrank.com/contests/projecteuler/challenges/euler002
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
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
f(n) = f(n-1) + f(N-2)

//find the Nth fibo number... and we sort of know that the even numbers are like this:
  1,2,3,5,8,13,21,34....
  
  sum all the terms at these indices: 1,4,7,10,13....
  
  //Binet's theorem can lead to wrong values. but perhaps we can try. 

*/

long fib(long N){
  static long preCalc[10000000];

  if(N < 0 || N > 10000000){
    return 0;
  }else{
    long &t = preCalc[N];
    
    if(!t){
      if(N==0 || N==1){ t = 1; } 
      else { t = fib(N-1) + fib(N-2); }
    }
    
    return t;
  }
}

long calculateExoticSumLowerThan(long N){
  
  int i = 1; 
  long result = 0;
  
  while(true){
    
    long subResult = fib(i); 
    
    if(subResult >= N) break;
    if(subResult % 2 == 0){ result += subResult; }
        
    i++; 
  }
  
  return result;
}

//FAILED ATTEMPT BELOW - SOME ROUNDING ERRORS
//inline int64_t binet(int64_t n){
//  double phiPlus = (1.0 + sqrtl(5.0))/2.0;
//  double phiMinus = (1.0 - sqrtl(5.0))/2.0;
//  
//  int64_t v = (int64_t)((powl(phiPlus, (double)n) - powl(phiMinus, (double)n)) / sqrtl(5.0));
//  return v;
//}
//
//// 1, 1, 2, 3, 5, 8
//int64_t calculateExoticSumLowerThan(int64_t N){
//  
//  int64_t result = 0; 
//  int64_t i = 3; 
//  int64_t subResult = 0;
//  
//  while(true){
//    subResult = binet(i);
//    if(subResult >= N) break;
//    result += subResult;
//    i += 3; 
//  }
//  
//  
//  return result;
//}