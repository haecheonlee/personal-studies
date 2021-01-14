/* reference: baekjoon/codeplus */

#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 9901;

int N, M;
int d[14 * 14][1 << 14];

int go(int num, int state) {
	if(num == N * M && state == 0) return 1;
	if(num >= N * M) return 0;
	
	int& ret = d[num][state];
	if(ret != -1) return ret;
	ret = 0;
	
	// num 번칸 이미 채워짐
	if(state & 1) {
		ret = go(num + 1, (state >> 1));
	} else {
		// 세로 블럭 채우기
		ret = go(num + 1, (state >> 1) | (1 << (M - 1)));
		
		// 가로 블럭 채우기
		if((num % M) != (M - 1) && (state & 2) == 0) {
			// 가장 오른쪽 칸이 아닌지 && 오른쪽 칸이 비워 있는지
			ret += go(num + 2, state >> 2);
		}
	}
	
	ret %= MOD;
	return ret;
}

int main() {
	cin >> N >> M;
	
	memset(d, -1, sizeof(d));
	cout << go(0, 0) << '\n';
	
	return 0;
}
