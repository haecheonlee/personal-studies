#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n,cnt=0;
	cin>>n;
	
	string s;
	while(n--) {
		cin>>s;
		
		stack<char> st;
		for(int i=0; i<s.size(); i++) {
			if(st.empty()) st.push(s[i]);
			else {
				if(st.top()==s[i]) st.pop();
				else st.push(s[i]);
			}
		}
		
		if(st.empty()) cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}

/*
boj.kr/3986

INPUT:
3
ABAB
AABB
ABBA

OUTPUT:
2
*/
