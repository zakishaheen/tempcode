#include <iostream>
#include <string>

using namespace std;

int countOccurance(string input, string toFind){
	
	int result = 0;
	
	string::iterator i = input.begin();
	int findLen = toFind.length();
	
	while(i<=input.end()){
		if (*i==toFind[0]) {
			if(toFind.compare(string(i, i+findLen))==0){
				result++;
			}
		}
		i++;
	}
	
	return result;
}

int main(int argc, char *argv[]) {
	string input = "AUDRYBERNITAEATVIVANBROOKSEATJENIEATMICHALELASANDRALATIAEATLIDIAEATDEANDRAEATSYBILEATMONROEEATLATRISHAALTAEATDERICKEATROSANNLEVILIBBYKIRSTENCHARLESEATELLYNEATJANEEEATSTASIAEATJULIETTARANDIEATNORBERTSAGEEATARACELIKATINAMERNAEATISAIASWINNIEEATARLETHAEATMILOCAMIEEATANNABELEATLEANORABERTHASYBLECHANAEATREAGANERICKVALENTINAEATDORETHEASEBASTIANKRISROBERTAEATIVONNEEATAI";

	string toFind = "EAT";
	
	
	cout<<countOccurance(input,toFind)<<endl;
	return 0;
}