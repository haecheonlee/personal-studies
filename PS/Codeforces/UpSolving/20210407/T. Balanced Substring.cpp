/* editorial */

#include <iostream>
#include <map>

using namespace std;

const int MAX_N = 1e5 + 10;

char s[MAX_N];
map<int,int> mp;

int main() {
	int N; scanf("%d", &N);
	scanf("%s", s + 1);
	
	int ans = 0, p0 = 0, p1 = 0;
	mp[0] = 0;
	
	for(int i = 1; i <= N; i++) {
		p0 += (s[i] == '0');
		p1 += (s[i] == '1');
		
		mp.emplace(p0 - p1, i);
		if(mp.find(p0 - p1) != mp.end()) ans = max(ans, i - mp[p0 - p1]);
		else mp[p0 - p1] = i;
	}
	cout << ans << '\n';
	
	return 0;
}
