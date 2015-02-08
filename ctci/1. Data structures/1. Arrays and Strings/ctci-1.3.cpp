#include <iostream>
#include <cassert>

using namespace std;

/*
1.3 Given two strings, write a method to decide if one is a permutation of the other.
*/

bool ispermutation(string a, string b){
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return ( 0 == a.compare(b));
}

int main(int argc, char *argv[]) {
	assert(true == ispermutation("", ""));
	assert(true == ispermutation("a", "a"));
	assert(true == ispermutation("ab", "ba"));
	assert(false == ispermutation("ab", "Ca"));
	assert(true == ispermutation("abc", "bac"));
	assert(false == ispermutation("abc", "bab"));
	assert(false == ispermutation("abc", "baC"));
}