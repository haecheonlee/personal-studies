/* reference: https://www.crocus.co.kr/1071 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<string> s(N);
	for(int i = 0; i < N; i++) cin >> s[i];

	int L = 0, R = M - 1, MID;
	bool ans;
	
	while(L <= R) {
		MID = (L + R) / 2;
		
		map<string,int> m;
		bool chk = true;
		
		for(int j = 0; j < M; j++) {
			string ss = "";
			for(int i = MID; i < N; i++) ss += s[i][j];
			
			if(m.find(ss) != m.end()) {
				chk = false;
				break;
			} else {
				chk = true;
				m[ss]++;
			}
		}
		
		if(chk) L = MID + 1;
		else R = MID - 1;
		
		ans = chk;
	}

	cout << (ans ? MID : MID - 1) << '\n';

	return 0;
}
