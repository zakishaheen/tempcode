#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>

using namespace std;

/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
	string *memo;
public:

	string lpr(string s, int i, int j){
		if(i==j) return s.substr(i,1);
		
		if(s[i]==s[j] && i+1==j){ return s.substr(i,2); }
		
		if(s[i]==s[j] && i+1!=j){
			string value =  string(1,s[i]) + lpr(s, i+1, j-1) + string(1,s[j]);
			
			return value;
		}
		else{
			string a = lpr(s, i+1, j);
			string b = lpr(s, i, j-1);
			
			if(a.size()>b.size()){
				return a;
			}else{
				return b;
			}
		}
	}
    string longestPalindrome(string s) {
		return lpr(s,0,s.size()-1);
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	
	cout<<s.longestPalindrome("a")<<endl;
	cout<<s.longestPalindrome("aa")<<endl;
	cout<<s.longestPalindrome("aaa")<<endl;
	cout<<s.longestPalindrome("aaaa")<<endl;
	cout<<s.longestPalindrome("aaaabaaaa")<<endl;
	cout<<s.longestPalindrome("abaaaabaaaab")<<endl;
	cout<<s.longestPalindrome("abaaaabaaaaba")<<endl;
}