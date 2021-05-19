#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int N; cin >> N;
	string s; cin >> s;

	vector<int> ans;
	stack<int> list;
	stack<char> op;
	for(int i = 0; i < s.size(); i++) {
		int num = 0;
		while(s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + (s[i] - '0');
			i++;
		}
		
		int res = 0;
		if(list.empty()) {
			res = num;
		} else {
			res = list.top();
			list.pop();
		}
		
		if(!op.empty()) {
			char opr = op.top(); op.pop();

			if(opr == 'S') res -= num;
			else if(opr == 'M') res *= num;
			else if(opr == 'U') res /= num;
			else if(opr == 'P') res += num;
		}
		
		if(s[i] == 'C') ans.push_back(res);
		else op.push(s[i]);
		
		list.push(res);
	}
	
	if(ans.empty()) cout << "NO OUTPUT" << '\n';
	else for(auto& x : ans) cout << x << ' ';
	
	return 0;
}
