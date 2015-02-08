#include <iostream>
#include <map>
#include <cassert>

/*
Implement a method to perform basic string compression using the counts of repeated characters. For example, the string a a b c c c c c a a a would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string.

*/

using namespace std;

string convertToString(int input){
	string result; 
	
	if(input==0) return "0";
	
	while(input>0){
		int x = input%10;
		result += '0' + x;
		input /= 10;
	}
	
	reverse(result.begin(), result.end());
	
	return result;
}

string compress(string input){
	//we need an ordered map here. 
	
	multimap<char, int> freq;
	
	bool willExceed = false; //it will exceed if any character is repeating. (i hope)
	//prefer iterators over bare-bone loops. 
	char currentChar = *(input.begin());
	int count = 0; 
	for(auto it = input.begin(); it!= input.end(); it++){
		if(*it == currentChar){
			count++;
			if(count>2) willExceed = true;
		} 
		else{
			freq.insert(pair<char,int>(currentChar, count));
			currentChar = *it;
			count = 1;
		}
	}
	
	freq.insert(pair<char,int>(currentChar, count));
	
	if(!willExceed) return input;
	
	string result;
	
	for(auto it = freq.begin(); it!=freq.end(); it++){
		auto pair = *it; 
		char x = pair.first;
		int value = pair.second;
		
		result += x; 
		result += convertToString(value);
		
	}
	
	return result; 
	
}

void test(string input, string expected){
	
	string actual = compress(input);
	cout<<input<<"\t"<<expected<<"\t"<<actual<<endl;
	
	assert(0 == expected.compare(actual));
}
int main(int argc, char *argv[]) {
	
	test("", "");
	test("a", "a");
	test("aa", "aa");
	test("aaaa", "a4");
	test("abcd", "abcd");
	test("aabb", "aabb");
	test("aabbccdd", "aabbccdd");
	test("aabbccddd", "a2b2c2d3");
	test("aabccccaaa", "a2b1c5a3"); // a very important test case. 
}