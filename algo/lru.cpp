#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <map>
#include <stack>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <algorithm>
#include <queue>


using namespace std;

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/
class LRUCache{
private:
	priority_queue)
	list<int> lruStack;
	unordered_map<int, int> lookup;
	int capacity;
	int utilisation; 
	
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
		utilisation = 0;
    }
	void print(){
		for(auto i = lruStack.begin(); i!=lruStack.end(); i++){
			cout<<*i<<":"<<lookup[*i]<<",";
		}
		cout<<endl;
		
	}
    
	void upgrade(int key){
		auto it = find(lruStack.begin(), lruStack.end(), key);
		lruStack.erase(it);
		lruStack.push_back(key);
	}
	
    int get(int key) {
        if(lookup.count(key)){
			upgrade(key);
			return lookup[key];
		}else{
			return -1;
		}
    }
    
    void set(int key, int value) {

		if(lookup.count(key)){
			upgrade(key);
			lookup[key] = value;
		}else{
			if(utilisation==capacity){
				auto it = lruStack.begin();
				lruStack.erase(it);				
			}else{
				utilisation++;
			}
			
			lookup[key] = value;
			lruStack.push_back(key);
		}
		print();
		
    }
};


int main(int argc, char *argv[]) {
	
	LRUCache s(3);
	s.set(1,1);
	s.set(2,2);
	s.set(3,3);
	
	cout<<s.get(1)<<endl;
	cout<<s.get(2)<<endl;
	cout<<s.get(3)<<endl;
	cout<<s.get(2)<<endl;
	cout<<s.get(2)<<endl;
	cout<<s.get(3)<<endl;
	s.set(3,33);
	s.set(4,4);
	s.set(5,5);

	
}