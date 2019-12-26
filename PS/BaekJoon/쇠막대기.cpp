#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	stack<int> st;
	int total=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '(') {
			st.push(i);
		} else {
			int top = st.top();
			st.pop();
			
			if(top == (i-1)) total += st.size();
			else total++;
		}
	}

	cout<<total;

	return 0;
}

/*
boj.kr/10799

INPUT:
()(((()())(())()))(())

OUTPUT:
17
*/
