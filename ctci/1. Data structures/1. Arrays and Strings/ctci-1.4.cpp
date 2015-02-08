#include <iostream>

/*
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end of the string to hold the additional characters, and that you are given the "true" length of the string. (Note: if implementing in Java, please usea character array so that you can perform this operation inplace.)
*/
using namespace std;

void replaceSpaces(char[] a, int trueSize){
	
	int tail = trueSize;
	int start = trueSize;
	while(a[start]!=' ') start--;
	
	// "this is how we do              %20it."
	//
	
	int current = start;//this is where the actual text starts. 
	
	//tail is always pointing at the far-end of the empty buffer. 
	//start is always pointing at the last text character.
	//current should always be = start before the loop. 
	//the above 3 are invariants which must hold true and they do in the following algorithm. 
	while(current>0){
		
		while(a[current]!=' ') current--; //find the space. 
		//go on, even if you know the solution and you feel like this is a drain of energy
		
		int wordLen = start - current; //count the wordlength
		int copyStart = tail - wordLen - 3;
		
		a[copyStart++] = '%'; a[copyStart++] = '2'; a[copyStart++] = '0';
		
		for(int i=copyStart, j=current; i<tail; i++, j++){
			a[copyStart] = a[j];
		}
		tail -= wordLen + 3;
		
		current--;
	}
	
	
}
int main(int argc, char *argv[]) {
	
}