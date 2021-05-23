#include <iostream>
#include <string>

using namespace std;

int ans = -1;
int N;
string T;
string s[20];
int p[20], cnt[26], need[26];

void go(int idx, int price) {
	if(idx == N) {
		bool flag = 1;
		for(int i = 0; i < 26; i++) if(cnt[i] < need[i]) flag = 0;
		
		if(flag) if(ans == -1 || ans > price) ans = price;
		return;
	}

	// skip
	go(idx + 1, price);
	
	// take
	for(auto& x : s[idx]) cnt[x - 'A']++;
	go(idx + 1, price + p[idx]);
	for(auto& x : s[idx]) cnt[x - 'A']--;
}

int main() {
	cin >> T >> N;
	for(int i = 0; i < N; i++) cin >> p[i] >> s[i];
	
	for(auto& x : T) need[x - 'A']++;
	
	go(0, 0);
	cout << ans << '\n';

	return 0;
}
