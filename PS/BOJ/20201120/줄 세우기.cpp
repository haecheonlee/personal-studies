#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<string> a(N), desc, inc;
	for(int i = 0; i < N; i++) cin >> a[i];
	desc = inc = a;
	
	sort(desc.rbegin(), desc.rend());
	sort(inc.begin(), inc.end());
	
	bool is_desc = true, is_inc = true;
	for(int i = 0; i < N; i++) {
		if(a[i] != desc[i]) is_desc = false;
		if(a[i] != inc[i]) is_inc = false;
	}
	
	if(!is_desc && !is_inc) cout <<"NEITHER";
	else cout << (is_desc ? "DECREASING" : "INCREASING");
	
	return 0;
}
