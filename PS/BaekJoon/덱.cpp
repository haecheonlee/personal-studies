#include <iostream>

using namespace std;

class Deque{
private:
	int data[100001];
	int start;
	int _size;
public:
	Deque() {
		this->start=0;
		this->_size=0;
	}
	
	void push_front(int X) {
		for(int i=_size; i>start; i--) this->data[i] = this->data[i-1];
		this->data[start]=X;
		this->_size++;
	}
	
	void push_back(int X) {
		this->data[_size]=X;
		this->_size++;
	}
	
	int pop_front() {
		if(_size > 0) {
			int value = this->data[start];
			
			for(int i=0; i<_size-1; i++) this->data[i]= this->data[i+1];
			this->_size--;
			
			return value;
		} else {
			return -1;
		}
	}
	
	int pop_back() {
		if(_size > 0) {
			int value = this->data[_size-1];
			
			this->data[_size+1]=0;
			this->_size--;
			
			return value;
		} else {
			return -1;
		}
	}
	
	int size() {
		return this->_size;
	}
	
	int empty() {
		if(this->_size==0) return 1;
		else return 0;
	}
	
	int front() {
		if(empty()) return -1;
		else return this->data[start];
	}
	
	int back() {
		if(empty()) return -1;
		else return this->data[_size-1];
	}
};

int main() {
	Deque d;
	
	int N, num;
	cin>>N;
	
	string order;
	for(int i=0; i<N; i++) {
		cin>>order;
		
		if(order == "push_back") {
			cin>>num;
			d.push_back(num);
		} else if(order == "push_front") {
			cin>>num;
			d.push_front(num);
		} else if(order == "front") {
			cout<<d.front()<<'\n';
		} else if(order == "back") {
			cout<<d.back()<<'\n';
		} else if(order == "size") {
			cout<<d.size()<<'\n';
		} else if(order == "empty") {
			cout<<d.empty()<<'\n';
		} else if(order == "pop_front") {
			cout<<d.pop_front()<<'\n';
		} else if(order == "pop_back") {
			cout<<d.pop_back()<<'\n';
		} 
	}
	
	return 0;
}

/*
boj.kr/10866

INPUT:
22
front
back
pop_front
pop_back
push_front 1
front
pop_back
push_back 2
back
pop_front
push_front 10
push_front 333
front
back
pop_back
pop_back
push_back 20
push_back 1234
front
back
pop_back
pop_back

OUTPUT:
-1
-1
-1
-1
1
1
2
2
333
10
10
333
20
1234
1234
20
*/
