#include <iostream>
#include <stack>
#include <cmath>

using namespace std;


class Solution {
public:
    string convertToTitle(int n) {	
		string result;
        
		stack<char> s;		
		int x,y;
		int r=0;
		do{
			int t;
			t = n%26;
			r++;
			n=n/26;
		
		}while(n>1);
		
		while(!s.empty()){
			char t = s.top();
			s.pop();
			cout<<t;
		}
		
		return result;
    }
	
};


int main(int argc, char *argv[]) {
	Solution s;
	cout<<s.convertToTitle(1)<<endl;
	cout<<s.convertToTitle(25)<<endl;
	cout<<s.convertToTitle(26)<<endl;
	cout<<s.convertToTitle(27)<<endl;
	
	cout<<s.convertToTitle(51)<<endl;
	cout<<s.convertToTitle(52)<<endl;
	cout<<s.convertToTitle(82)<<endl;
}