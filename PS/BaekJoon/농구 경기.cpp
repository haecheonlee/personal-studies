#include <iostream>
#include <map>

using namespace std;

int main() {
	map<char, int> m;
	
	int N;
	cin>>N;
	
	string name;
	for(int i=0; i<N; i++) {
		cin>>name;
		
		char first_ch = name[0];
		/*
		if(m.find(first_ch) == m.end()) {
			m.insert({first_ch, 1});
		} else {
			m[first_ch] += 1;
		}
		*/
		m[first_ch] += 1;
	}
	
	string result = "";
	for(auto it = m.begin(); it != m.end(); it++) {
		if(it->second >= 5) result += it->first; 
	}

	if(result == "") cout << "PREDAJA";
	else cout << result;

	return 0;
}

/*
boj.kr/1159

INPUT:
18
babic
keksic
boric
bukic
sarmic
balic
kruzic
hrenovkic
beslic
boksic
krafnic
pecivic
klavirkovic
kukumaric
sunkic
kolacic
kovacic
prijestolonasljednikovi

OUTPUT:
bk
*/
