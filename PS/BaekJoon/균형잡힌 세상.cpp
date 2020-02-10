#include <iostream>
#include <stack>

using namespace std;

bool checkIfBalanced(stack<char> &st, const char ch) {
	if(st.empty()) return false;
	
	if(st.top()=='(' && ch==')') {
		st.pop();
		return true;
	}
	
	if(st.top()=='[' && ch==']') {
		st.pop();
		return true;
	}
	
	return false;
}

int main() {
	string s;
	
	while(1) {
		getline(cin,s);
		if(s==".") break;
		
		stack<char> st;
		bool check=true;
		
		for(int i=0; i<s.size(); i++) {
			if(s[i]=='(' || s[i]=='[') st.push(s[i]);
			
			if(s[i]==')') {
				check=checkIfBalanced(st,s[i]);
				if(!check) break;
			} else if(s[i]==']') {
				check=checkIfBalanced(st,s[i]);
				if(!check) break;
			}
		}
		
		if(st.empty() && check) cout<<"yes\n";
		else cout<<"no\n";
	}

	return 0;
}

/*
boj.kr/4949

INPUT:
So when I die (the [first] I will see in (heaven) is a score list).
[ first in ] ( first out ).
Half Moon tonight (At least it is better than no Moon at all].
A rope may form )( a trail in a maze.
Help( I[m being held prisoner in a fortune cookie factory)].
([ (([( [ ] ) ( ) (( ))] )) ]).
 .
.

OUTPUT:
yes
yes
no
no
no
yes
yes
*/
