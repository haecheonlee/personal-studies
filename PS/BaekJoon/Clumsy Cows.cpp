#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	int L=0, R=0;
	stack<char> stk;
	for(auto& c : s) {
		if(c=='(') {
			L++;
			stk.push(c);
		}
		else {
			R++;
			if(stk.size()) {
				stk.pop();
				L--; R--;	
			}
		}
	}
	
	L=(L+1)/2, R=(R+1)/2;
	cout<<L+R;

	return 0;
}
