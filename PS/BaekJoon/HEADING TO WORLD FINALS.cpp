#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Team {
public:
	string univ;
	string name;
	int score;
	int penalty;
};

bool sorting(const Team &l, const Team &r) {
	if(l.score==r.score) return l.penalty<r.penalty;
	return l.score>r.score;
}

int main() {
	int n, k;
	cin>>n>>k;
	
	map<string,int> m;
	vector<Team> vec(n);
	for(int i=0; i<n; i++) {
		cin>>vec[i].univ>>vec[i].name>>vec[i].score>>vec[i].penalty;
	}
	
	sort(vec.begin(), vec.end(), sorting);
	int cnt=0;
	
	for(int i=0; i<n; i++) {
		if(!m[vec[i].univ]) {
			cout<<vec[i].name<<'\n';
			m[vec[i].univ]++;
			cnt++;
		}
		
		if(k==cnt) break;
	}
	
	return 0;
}

/*
boj.kr/10918

INPUT:
10 2
KAIST OriGoGi 10 1184
Seoul_Univ Wook_Norris 8 594
Yonsei_Univ Underwood 8 806
Seoul_Univ cpp 10 1148
Korea_Univ Let_Myungwoo_go_WF 10 1323
Seoul_Univ crazy_bus_driver 8 1065
Peking_Univ Nornir 8 837
Seoul_Univ KimChiWarrior 8 836
Hanyang_Univ StyleShare 8 1109
POSTECH CHOCOLATE 8 1085

OUTPUT:
cpp
OriGoGi
*/
