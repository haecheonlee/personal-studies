#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> signs;
vector<string> result;
bool check[10];

bool validate(char previous, char current, char sign) {
	if(sign=='>' && previous<current) return false;
	if(sign=='<' && previous>current) return false;
	return true;
}

void show(int index, string s) {
	if(index==signs.size()+1) {
		result.push_back(s);
		return;
	}
	
	for(int i=0; i<=9; i++) {
		if(check[i]) continue;
		if(index==0 || validate(s[index-1], i+'0', signs[index-1])) {
			check[i]=true;
			show(index+1, s+to_string(i));
			check[i]=false;
		}
	}
}

int main() {
	int k;
	cin>>k;

	signs=vector<char>(k);
	for(int i=0; i<k; i++) cin>>signs[i];
	
	show(0,"");
	
	auto p=minmax_element(result.begin(), result.end());
	cout<<*p.second<<'\n'<<*p.first;

	return 0;
}

/*
boj.kr/2529

INPUT:
2
< >

OUTPUT:
897
021
*/
