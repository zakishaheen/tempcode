#include <iostream>
#include <cassert>
#include <unordered_map>

using namespace std;

/*
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
*/
bool hasUniqueNaive(string s){
	if(s.size()<=1) return true;
	
	for(int i=0;i<s.size();i++){
		for(int j=i+1;i<s.size();j++){
			if(s[i]==s[j]) return false;
		}
	}
	return true;
}

bool hasUniqueBetter(string s){
	unordered_map<char,int> freq;
	
	for(int i=0;i<s.size();i++){
		if(freq.find(s[i])==freq.end()){
			freq[s[i]] = 1;}
			else {
				return false;
			}
	}
	return true;
}

bool hasUniqueBest(string s){
	sort(s.begin(), s.end());
	
	for(auto i = s.begin(); i!=s.end(); i++){
		if(*i == *(i+1)){
			return false;
		} 
	}
		
	return true;
}
int main(int argc, char *argv[]) {
	assert(true == hasUniqueNaive(""));
	assert(true == hasUniqueNaive("a"));
	assert(false == hasUniqueNaive("aba"));
	
	assert(true == hasUniqueBetter(""));
	assert(true == hasUniqueBetter("a"));
	assert(false == hasUniqueBetter("aba"));
	
	assert(true == hasUniqueBest(""));
	assert(true == hasUniqueBest("a"));
	assert(false == hasUniqueBest("aba"));
	
}