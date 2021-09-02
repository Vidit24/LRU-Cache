#include<bits/stdc++.h>
using namespace std;


class Node{
	public :
	string key;
	int value;
	Node(string key,int value){
		this->key = key;
		this->value = value;
	}

};
class LRUCache{
	public : 
	int maxSize;
	list<Node> l;
	unordered_map<string,list<Node>::iterator> m;

	LRUCache(int maxSize){
		this->maxSize = maxSize > 1 ? maxSize : 1 ;
	}

	void insertkeyValue(string key,int value){
		if(m.count(key) != 0){
			//replace old value and replace
			auto it = m[key];
			it->value = value;
		}
		else{
			if(l.size()==maxSize){
				Node last = l.back();
				m.erase(last.key);//remove from map
				l.pop_back();// remove from list
			}
			Node n(key,value);
			l.push_front(n);
			m[key] = l.begin();
		}
	}

	int* getValue(string key){

		if(m.count(key) != 0){
			auto it = m[key];
			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin()->value;
		}
		return NULL;

	}

	string mostRecentKey(){
		return l.front().key;
	}
};

int main(){
	LRUCache lru(3);
	lru.insertkeyValue("mango",10);
	lru.insertkeyValue("apple",20);
	lru.insertkeyValue("guava",30);
	cout<<lru.mostRecentKey()<<endl;

	lru.insertkeyValue("mango",40);
	cout<<lru.mostRecentKey()<<endl;

	lru.insertkeyValue("banana",20);

	if(lru.getValue("apple")==NULL){
		cout<<"apple doesn't exist";
	}
	if(lru.getValue("guava")==NULL){
		cout<<"guava doesn't exist";
	}
	if(lru.getValue("banana")==NULL){
		cout<<"banana doesn't exist";
	}
	if(lru.getValue("mango")==NULL){
		cout<<"mango doesn't exist";
	}
}