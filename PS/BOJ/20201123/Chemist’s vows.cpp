/* reference: https://yabmoons.tistory.com/164 */

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int L = 114;

string a[] = { "h", "li", "na", "k", "rb", "cs", "fr", "be", "mg", "ca", "sr", "ba", "ra", "sc", "y", "ti", "zr", "hf", "rf", "la", "ac",
                  "v", "nb", "ta", "db", "ce", "th", "cr", "mo", "w", "sg", "pr", "pa", "mn", "tc", "re", "bh", "nd", "u", "fe", "ru", "os",
                  "hs", "pm", "np", "co", "rh", "ir", "mt", "sm", "pu", "ni", "pd", "pt", "ds", "eu", "am", "cu", "ag" ,"au", "rg", "gd", "cm",
                  "zn", "cd", "hg", "cn", "tb", "bk", "b", "al", "ga", "in", "tl", "dy", "cf", "c", "si", "ge", "sn", "pb", "fl", "ho", "es",
                  "n", "p", "as", "sb", "bi", "er", "fm", "o", "s", "se", "te", "po", "lv", "tm", "md", "f", "cl", "br", "i", "at", "yb", "no",
                  "he", "ne", "ar", "kr", "xe", "rn","lu", "lr" };

const int MAX = 5e4 + 1;
bool check[MAX];

bool go(string& s) {
	memset(check, false, sizeof(check));
	
	queue<int> q;
	q.push(0);
	check[0] = true;
	
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		
		if(now == (int)s.size()) return true;
		
		string s1 = s.substr(now, 1);
		string s2 = s.substr(now, 2);
		
		for(int i = 0; i < L; i++) {
			if(s1 == a[i] && check[now + 1] == false) {
				check[now + 1] = true;
				q.push(now + 1);
			}
			
			if(s2 == a[i] && check[now + 2] == false) {
				check[now + 2]= true;
				q.push(now + 2);
			}
		}
	}
	
	return false;
}

int main() {
	int T;
	cin >> T;

	while(T--) {
		string s;
		cin >> s;
		
		cout << (go(s) ? "YES" : "NO") << '\n';
	}
	
	return 0;
}
