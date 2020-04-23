#include <iostream>

using namespace std;

int main() {
	string n,s;
	getline(cin,n);

	while(getline(cin,s)) {
		cout<<(char)toupper(s[0])<<s.substr(1,s.size())<<'\n';
	}

	return 0;
}

/*
INPUT:
5
powdered Toast Man
skeletor
Electra Woman and Dyna Girl
she-Ra Princess of Power
darth Vader

OUTPUT:
Powdered Toast Man
Skeletor
Electra Woman and Dyna Girl
She-Ra Princess of Power
Darth Vader
*/
