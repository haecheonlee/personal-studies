#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;
set<string> s;
vector<int> a;

void go(int index, int count, vector<int> &p) {
	if(count==K) {
		do {
			string num="";
			for(auto &x : p) num+=to_string(x);
			s.insert(num);
		} while(next_permutation(p.begin(), p.end()));

		return;
	}
	
	if(index>=N) return;
	p.push_back(a[index]);
	go(index+1,count+1,p);
	p.pop_back();
	go(index+1,count,p);
}

int main() {
	cin>>N>>K;	

	a.resize(N);
	for(int i=0; i<N; i++) cin>>a[i];
	sort(a.begin(), a.end());
	
	vector<int> p;
	go(0,0,p);
	cout<<s.size();
	
	return 0;
}
