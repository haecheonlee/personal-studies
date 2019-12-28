#include <iostream>
#include <vector>

using namespace std;

#define max 1000000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> v;	
	bool check[1000001] {false};
	
	for(int i=2; i<=max; i++) {
		if(check[i] == false) {
			v.push_back(i);
			for(int j=i+i; j<=max; j+=i) check[j] = true;
		}
	}
	
	int num=1;
	while(1) {
		cin>>num;
		if(num == 0) break;
		
		bool answered=false;
		for(int i=0; i<v.size(); i++) {
			if(v[i] >= num) break;
			if(check[num-v[i]] == false) {
				cout<<num<<" = "<<v[i]<<" + "<<num-v[i]<<'\n';
				answered=true;
				break;
			}
		}
		if(!answered) cout<<"Goldbach's conjecture is wrong.\n";
	}

	return 0;
}

/*
boj.kr/6588

INPUT:
8
20
42
0

OUTPUT:
8 = 3 + 5
20 = 3 + 17
42 = 5 + 37
*/
