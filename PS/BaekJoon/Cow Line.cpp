#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> dq;
	
	int n,i=1;
	cin>>n;
	
	while(n--) {
		string type,pos;
		int range;
		
		cin>>type>>pos;
		if(type=="A") {
			if(pos=="L") dq.push_front(i);
			else dq.push_back(i);
			i++;
		} else {
			cin>>range;
			
			if(pos=="L") {
				while(range--) dq.pop_front();
			} else {
				while(range--) dq.pop_back();	
			}
		}
	}
	
	while(!dq.empty()) {
		cout<<dq.front()<<'\n';
		dq.pop_front();
	}

	return 0;
}

/*
INPUT:
10
A L
A L
A R
A L
D R 2
A R
A R
D L 1
A L
A R

OUTPUT:
7
2
5
6
8
*/
