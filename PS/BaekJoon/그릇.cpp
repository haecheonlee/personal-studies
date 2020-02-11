#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	stack<char> st;
	int height=0;
	for(int i=0; i<s.size(); i++) {
		if(!st.empty()) {
			if(st.top()==s[i]) height+=5;
			else height+=10;
			
			st.push(s[i]);
		} else {
			st.push(s[i]);
			height+=10;
		}
	}
	cout<<height;
	
	return 0;
}

/*
boj.kr/7567

INPUT:
((((

OUTPUT:
25
*/
