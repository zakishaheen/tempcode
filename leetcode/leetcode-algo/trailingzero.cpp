#include <iostream>

using namespace std;
//

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
		
		for(long i=5;n/i>=1;i *= 5){
			result += n/i;
		}
		
		return result;	
    }
};


int main(int argc, char *argv[]) {
	
	Solution s;
	
	cout<<s.trailingZeroes(1808548329); 	
	
	
	return 0;
}