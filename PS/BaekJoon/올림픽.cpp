#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Medal{
public:
	int position;
	int gold;
	int silver;
	int bronze;
};

bool medalSort(const Medal &a, const Medal &b) {
	if(a.gold != b.gold) return a.gold > b.gold;
	else if(a.silver != b.silver) return a.silver > b.silver;
	else if(a.bronze != b.bronze) return a.bronze > b.bronze;
}

int main() {
	vector<Medal> v;
	
	int N, K;
	cin>>N>>K;
	
	int p, g, s, b;
	for(int i=0; i<N; i++) {
		cin>>p>>g>>s>>b;
		v.push_back({p, g, s, b});
	}
	
	sort(v.begin(), v.end(), medalSort);

	int ranking = 1;
	Medal previous_one;
	for(int i=0; i<v.size(); i++) {
		if(i != 0) {
			if(v[i].gold != previous_one.gold || v[i].silver != previous_one.silver || v[i].bronze != previous_one.bronze) {
				ranking = i+1;
			}
		}

		if(v[i].position == K) {
			cout<<ranking<<endl;
			break;
		}
		
		previous_one = v[i];
	}

	return 0;
}

/*
boj.kr/8979

INPUT:
4 3
1 1 2 0
2 0 1 0
3 0 1 0
4 0 0 1

OUTPUT:
2
*/
