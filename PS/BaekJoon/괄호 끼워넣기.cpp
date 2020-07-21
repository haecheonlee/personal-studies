#include <iostream>
#include <stack>

using namespace std;

bool check[51];

int main() {
	string s;
	cin>>s;
	
	stack<int> stk;
	for(int i=0; i<s.size(); i++) {
		if(s[i]=='(') stk.push(i);
		else {
			if(stk.empty()==false) {
				check[stk.top()]=check[i]=true;
				stk.pop();
			}
		}
	}
	
	int ans=0;
	for(int i=0; i<s.size(); i++) {
		if(check[i]==false) ans++;
	}
	cout<<ans;
	
	return 0;
}
