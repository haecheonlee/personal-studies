#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validate(string pwd) {
	int count_vowel=0, count_consonant=0;
	for(const auto &c : pwd) {
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') count_vowel++;
		else count_consonant++;
	}
	
	return (count_vowel>=1 && count_consonant>=2);
}

void show(int length, const vector<char> &v, string password, int index) {
	if(password.size()==length) {
		if(validate(password)) cout<<password<<'\n';
		return;
	}
	
	if(index>=v.size()) return;
	show(length, v, password+v[index], index+1);
	show(length, v, password, index+1);
}

int main() {
	int L,C;
	cin>>L>>C;
	
	vector<char> v(C);
	for(int i=0; i<C; i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	show(L,v,"",0);
	
	return 0;
}

/*
boj.kr/1759

INPUT:
4 6
a t c i s w

OUTPUT:
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/
