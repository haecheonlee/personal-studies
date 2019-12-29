#include <iostream>
#include <vector>

using namespace std;

bool check[1000001];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i=2; i<=1000000; i++) {
		if(check[i] == false) {
			v.push_back(i);
			for(int j=i+i; j<=1000000; j+=i) check[j]=true;
		}
	}
	
	int T;
	cin>>T;
	
	int num,total;
	for(int i=0; i<T; i++) {
		cin>>num;

		vector<int> used;
		total=0;
		for(int j=0; j<v.size(); j++) {
			if(v[j] > num) break;
			if(check[num-v[j]]==false && (v[j] - (num-v[j])) <= 0) total++;
		}
	
		cout<<total<<'\n';
	}
	
	return 0;
}

/*
boj.kr/17103

INPUT:
5
6
8
10
12
100

OUTPUT:
1
1
2
1
6
*/
