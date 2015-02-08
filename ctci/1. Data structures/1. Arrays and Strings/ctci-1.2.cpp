#include <iostream>
#include <cassert>

using namespace std;

/*
Implement a function void reverse(char* str) in C or C++ which reverses a null- terminated string.
*/

void reverse(char *str){
	int len = strlen(str);
	
	for(int i=0,j=len-1;i<len/2;i++,j--){
		char temp = str[j];

		str[j]=str[i];
		str[i]=temp;
	}
}



int main(int argc, char *argv[]) {
	char t[] = "abcdef"; 
	reverse(t);
	assert(0 == strcmp(t, "fedcba"));
	
	char u[] = ""; 
	reverse(u);
	assert(0 == strcmp(u, ""));
	
	char v[] = "a"; 
	reverse(v);
	assert(0 == strcmp(v, "a"));
	
	char w[] = "aabb"; 
	reverse(w);
	assert(0 == strcmp(w, "bbaa"));
}