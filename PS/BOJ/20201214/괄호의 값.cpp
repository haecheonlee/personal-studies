/* reference: https://jaimemin.tistory.com/820 */

#include <iostream>
#include <stack>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	stack<char> stk;

	int ans = 0, temp = 1;
	bool is_good = true;
	for(int i = 0; i < (int)s.size(); i++) {
		if(s[i] == '(') {
			temp *= 2;
			stk.push('(');
		} else if(s[i] == '[') {
			temp *= 3;
			stk.push('[');
		} else if(s[i] == ')') {
			if(stk.empty() || stk.top() != '(') {
				is_good = false;
				break;
			} else {
				if(s[i - 1] == '(') ans += temp;
				stk.pop();
				temp /= 2;
			}
		} else if(s[i] == ']') {
			if(stk.empty() || stk.top() != '[') {
				is_good = false;
				break;
			} else {
				if(s[i - 1] == '[') ans += temp;
				stk.pop();
				temp /= 3;
			}
		}
	}
	
	cout << (!stk.empty() || !is_good ? 0 : ans) << '\n';
	
	return 0;
}
