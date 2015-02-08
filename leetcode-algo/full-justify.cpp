#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <deque>

using namespace std;

/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
    "This    is    an",
    "example  of text",
    "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        
        vector<string> result;
        
        vector<string> currentLineWords; 
        
        string currentLine;

        for(auto i = words.begin(); i!= words.end(); i++){
            
			string s = *i;
            
            if(s.size() + currentLine.size() + 1 > L){
            
			    int remaining = L - currentLine.size() - 1;
                int c = currentLineWords.size();//number of words. 
                int spaces = c - 1;
				 remaining+=spaces; 
                int equal = remaining/c;
                int remainder = remaining%c;

				 
                
                currentLine = "";
                
                for(int k=0;k<currentLineWords.size()-1;k++){
                    
                    currentLine+=currentLineWords[k];
					
					for(int j=0;j<=equal;j++){
                        currentLine+=" ";
                    }

					if(remainder>0){
						currentLine+=" ";
						remainder--;
					}
                }
				
				currentLine += currentLineWords[currentLineWords.size()-1];
                
                result.push_back(currentLine);
                currentLine = "";
                currentLineWords.clear();
				i--;
                
            }else{
                currentLine = currentLine + " " + s;
                currentLineWords.push_back(s);
            }
            
            
        }
        
        return result;
    }
};
int main(int argc, char *argv[]) {
	vector<string> input;
	input.push_back("This");
	input.push_back("is");
	input.push_back("an");
	input.push_back("example");
	input.push_back("of");
	input.push_back("text");
	input.push_back("justification.");
	
	Solution s;
	vector<string> result = s.fullJustify(input, 16);
	
	for(auto i = result.begin(); i!= result.end(); i++){
		cout<<*i<<endl;
	}
	
}