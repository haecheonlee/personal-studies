#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

void func_L(stack<char> &left, stack<char> &right) {
	if(!left.empty()) {
		int top=left.top();
		left.pop();
		right.push(top);
	}
}

void func_D(stack<char> &left, stack<char> &right) {
	if(!right.empty()) {
		int top=right.top();
		right.pop();
		left.push(top);
	}
}

void func_B(stack<char> &left, stack<char> &right) {
	if(!left.empty()) left.pop();
}

void func_P(stack<char> &left, char new_ch) {
	left.push(new_ch);
}

void print(stack<char> t) {
	while(!t.empty()) {
		cout<<t.top()<<" ";
		t.pop();
	}
	
	cout<<endl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	
	string N;
	cin>>N;
	
	stack<char> left;
	stack<char> right;
	
	for(int i=0; i<N.size(); i++) left.push(N[i]);
	
	int M;
	cin>>M;
	
	char order;
	for(int i=0; i<M; i++) {
		cin>>order;
		
		if(order == 'L') {
			func_L(left, right);
		}
		else if(order == 'D') {
			func_D(left, right);
		}
		else if(order == 'B') {
			func_B(left, right);
		}
		else if(order == 'P') {
			char new_ch;
			cin>>new_ch;
			
			func_P(left, new_ch);
		}
	}
	
	string _right="", _left="";
	while(!right.empty()) { _right += right.top(); right.pop(); }
	while(!left.empty()) { _left += left.top(); left.pop(); }

	reverse(_left.begin(), _left.end());
	cout<<_left+_right<<endl;
	
	return 0;
}

/*
boj.kr/1406

INPUT:
dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z

OUTPUT:
yxz
*/
