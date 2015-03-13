#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		int result = 0; 
		
        int size = num.size();

		for(int i=0;i<size;i++){
			
			if(num[i]<num[i+1]){}
//			
//			int a,b,c;
//			
//			b = num[i];
//			if(i==0) a = INT_MIN; else {
//				a = num[i-1];
//			}
//			if(i==size-1) c = INT_MIN; else {
//				c = num[i+1];
//			}
//			
//			if(b>a && b>c){
//				result = i;
//			}
		}
		
		return result;
    }
};

int main(int argc, char *argv[]) {
	
}