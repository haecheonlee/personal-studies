#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<char> st1;
	stack<char> st2;
	
	string a,b;
	cin>>a>>b;
	
	for(int i=0; i<a.size(); i++) st1.push(a[i]);
	for(int i=0; i<b.size(); i++) st2.push(b[i]);
	
	while(!st2.empty()) {
		if(st1.empty()) {
			cout<<"no";
			return 0;
		}

		if(st1.top()==st2.top()) {
			st1.pop();
			st2.pop();
		}
	}
	
	cout<<"go";
	
	return 0;
}

/*
boj.kr/4999

INPUT:
aaah
aaaaah

OUTPUT:
no
*/
