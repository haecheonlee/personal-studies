/* reference: https://torbjorn.tistory.com/427 */

#include <iostream>
#include <queue>
#include <cstring>

#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

const int MAX = 2e2 + 1;

bool check[MAX][MAX];

int main() {
	int T;
	cin >> T;

	for(int tc = 1; tc <= T; tc++) {
		string a, b, c;
		cin >> a >> b >> c;
		
		if(sz(a) + sz(b) != sz(c)) {
			cout << "Data set " << tc << ": no" << '\n';
		} else {
			memset(check, false, sizeof(check));

			queue<pii> q;
			q.push({0,0});
			check[0][0] = true;
			
			bool is_good = false;
			while(!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				
				int k = x + y;
				if(x == sz(a) && y == sz(b) && k == sz(c)) {
					is_good = true;
					break;
				}

				if(x != sz(a) && a[x] == c[k] && !check[x + 1][y]) {
					check[x + 1][y] = true;
					q.push({x + 1, y});
				}

				if(y != sz(b) && b[y] == c[k] && !check[x][y + 1]) {
					check[x][y + 1] = true;
					q.push({x, y + 1});
				}
			}

			cout << "Data set " << tc << ": " << (is_good ? "yes" : "no") << '\n';
		}
	}

	return 0;
}
