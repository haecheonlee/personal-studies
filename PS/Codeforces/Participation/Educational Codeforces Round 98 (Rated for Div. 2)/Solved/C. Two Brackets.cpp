#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;
		
		int ans = 0;
		stack<char> a, b;
		for(int i = 0; i < sz(s); i++) {
			if(s[i] =='(') a.push(i);
			if(s[i] =='[') b.push(i);
			
			if(s[i] == ')' && !a.empty()) ans++, a.pop();
			if(s[i] == ']' && !b.empty()) ans++, b.pop();
		}

		cout << ans << '\n';
	}
	
	return 0;
}
