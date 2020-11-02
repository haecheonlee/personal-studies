#include <iostream>
#include <vector>

#define sz(x) (int)(x.size())

using namespace std;
using pii=pair<int,int>;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin>>T;

	while(T--) {
		int a, b;
		cin>>a>>b;

		string s;
		cin>>s;

		s += '0';	

		vector<pii> p;
		int L = 0, end = -1;
		for(int i = 0; i < sz(s); i++) {
			if(s[i] == '1') {
				end = i;				
				L++;
			} else {
				if(end != -1) p.push_back({end, L});
				
				end = -1;
				L = 0;
			}
		}
	
		if(sz(p) == 1) {
			cout<<a<<'\n';
		} else {
			long long A = sz(p) * a;
			long long B = a;
			for(int i = 1; i < sz(p); i++) {
				int d = p[i].first - p[i].second - p[i - 1].first;
				B += d * b; 
			}

			long long C = 0;
			int bomb = sz(p);
			for(int i = 1; i < sz(p); i++) {
				int d = p[i].first - p[i].second - p[i - 1].first;
			
				int c1 = d * b + a;
				int c2 = a * 2;

				if(c1 <= c2) {
					C += d * b;
					bomb--;
				}
			}

			C += a * bomb;
			cout<<min(A,min(B,C))<<'\n';
		}
	}
	
	return 0;
}
