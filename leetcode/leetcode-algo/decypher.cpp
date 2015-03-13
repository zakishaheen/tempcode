#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	string input = "fzq kpgwj vxbsa rbh lpniqe bdqx fzq uomy ebt";
	
	char crypt ='T' ^ 'y';
	
	//T+?=f; T=f-?;
	
	//o+?=b; ?=b-o; o=b-?;
	
	//e>q, h>z
	
	for(auto i : input){
		int diff = ('q'-'e');
		int x = (int)i;
		
		cout<<diff<<">"<<x<<endl;
		cout<<(char)(x+diff)<<endl;
//		cout<<(char)((char)i+(char)('q' - 'e'))<<endl;
	}
	
}