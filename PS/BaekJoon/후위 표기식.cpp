#include <iostream>
#include <stack>

using namespace std;

int getOpPriority(char op) {
	if(op=='*' || op=='/') return 5;
	if(op=='+' || op=='-') return 4;
	if(op=='(') return 3;
	
	return -1;
}

bool isPriority(char op1, char op2) {
	int priority_1=getOpPriority(op1);
	int priority_2=getOpPriority(op2);
	
	return priority_1>=priority_2;
}

int main() {
	string s;
	cin>>s;

	stack<char> st;	
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='A' && s[i]<='Z') cout<<s[i];
		
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') {
			while(!st.empty() && isPriority(st.top(), s[i])) {
				cout<<st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if(s[i]=='(') st.push(s[i]);
		else if(s[i]==')') {
			while(st.top()!='(') {
				cout<<st.top();
				st.pop();
			}
			st.pop();
		}
	}
	
	while(!st.empty()) {
		cout<<st.top();
		st.pop();
	}

	return 0;
}

/*
boj.kr/1918

INPUT:
A*(B+C)

OUTPUT:
ABC+*
*/
