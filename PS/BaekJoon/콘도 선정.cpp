#include <iostream>
#include <vector>

using namespace std;

class Condo {
public:
	int distance;
	int price;
	bool ifChecked;
	bool ifPossible;
	Condo(int d, int p) : distance(d), price(p) {
		this->ifChecked = false;
		this->ifPossible = false;
	}
};

bool checkOption1(const vector<Condo> &v, int index) {
	bool possible = true;

	for(int i=0; i<v.size(); i++) {
		if(i == index) continue;

		if((v[index].distance >= v[i].distance)) {
			if(v[index].price >= v[i].price) {
				possible = false;
				break;
			}
		}
	}
	return possible;
}

bool checkOption2(const vector<Condo> &v, int index) {
	bool possible = true;
	for(int i=0; i<v.size(); i++) {
		if(i == index) continue;

		if((v[index].price >= v[i].price)) {
			if(v[index].distance >= v[i].distance) {
				possible = false;
				break;
			}
		}
	}
	return possible;
}

int main() {
	int N=0;
	cin>>N;
	
	vector<Condo> v;
	int d, p;
	for(int i=0; i<N; i++) {
		cin>>d>>p;
		v.push_back({d, p});
	}
	
	bool possible = false;
	for(int i=0; i<N; i++) {
		possible = checkOption1(v, i);
		if(!possible) possible = checkOption2(v, i);
		v[i].ifPossible = possible;
	}
	
	int count = 0;
	for(int i=0; i<N; i++) {
		if(v[i].ifPossible) count++;
	}
	
	cout<<count;
	
	return 0;
}

/*
boj.kr/2246

INPUT:
5
300 100
100 300
400 200
200 400
100 500

OUTPUT:
2
*/
