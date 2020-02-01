#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,score,p,num;
	cin>>n>>score>>p;
	
	vector<int> vec;
	vec.push_back(score);
	
	for(int i=0; i<n; i++) {
		cin>>num;
		vec.push_back(num);
	}
	
	sort(vec.begin(), vec.end(), [](int l, int r) {
		return l>r;
	});
	
	int ranking[p];
	for(int i=0; i<p; i++) {
		ranking[i]=i+1;
		if(i>0 && vec[i]==vec[i-1]) {
			ranking[i]=ranking[i-1];
		}
		
		if(vec[i]==vec[i+1] && i<n) continue;
		if(vec[i]==score) {
			cout<<ranking[i];
			return 0;
		}
	}
	
	cout<<-1;
	
	return 0;
}

/*
boj.kr/1205

INPUT:
3 90 10
100 90 80

OUTPUT:
2
*/
