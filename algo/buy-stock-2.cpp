#include <iostream>

using namespace std;
/*Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

^^ The above question expected a greedy alo. 
*/

class Solution {
		 	public:
				
		 		int maxProfit(vector<int> &prices) {
					
		 			int sum = 0;
					int len = prices.size()-1;

		 			for(int i=0; i < len; i++){
						if(prices[i+1] > prices[i]){
							sum += (prices[i+1] - prices[i]);
						    
						}
						}
					
					return sum;
				}
		};
int main(int argc, char *argv[]) {
	
}