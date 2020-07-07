#include <iostream>
#include <stack>

using namespace std;

int calc(int x, int y, char op) {
	if(op=='+') return x+y;
	if(op=='-') return x-y;
	if(op=='*') return x*y;
	if(op=='/') return x/y;
}

int main() {
	stack<int> stk;

	string s;
	cin>>s;
	
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0' && s[i]<='9') {
			stk.push(s[i]-'0');	
		}
		else {
			int b=stk.top();
			stk.pop();
			int a=stk.top();
			stk.pop();
			
			int sum=calc(a,b,s[i]);
			stk.push(sum);
		}
	}
	cout<<stk.top();
	
	return 0;
}
