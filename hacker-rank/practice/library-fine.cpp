#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int calculateFine(int aD, int aM, int aY, int eD, int eM, int eY){
  
  int result  = 0;
  
  if(aY == eY && aM == eM && aD <= eD ) result = 0;
  if(aY == eY && aM == eM && aD > eD ) result = (aD - eD) * 15;
  if(aY == eY && aM > eM) result = (aM - eM) * 500;
  if(aY > eY) result = 10000;
  
  return result;
  
}
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int aD, aM, aY;
  int eD, eM, eY;
  
  cin>>aD>>aM>>aY>>eD>>eM>>eY;
  
  cout<<calculateFine(aD, aM, aY, eD, eM, eY)<<endl;
  
  return 0;
}

