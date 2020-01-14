#include <iostream>

using namespace std;

bool checkIfVowel(char a) {
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return true;
	else return false;
}

bool checkCase(string s) {
	if(s.find('a') == string::npos && 
	   s.find('e') == string::npos &&
	   s.find('i') == string::npos &&
	   s.find('o') == string::npos && 
	   s.find('u') == string::npos) { return false; }

		if(s.size()>=3) {
			for(int i=0; i<s.size()-2; i++) {
		   		bool first=checkIfVowel(s[i]);
				bool second=checkIfVowel(s[i+1]);
				bool third=checkIfVowel(s[i+2]);
				
				if(first == second && first == third) return false;
			}
		}
	   
		if(s.size()>=2) {
			for(int i=0; i<s.size()-1; i++) {
	   			char first=s[i];
	   			char second=s[i+1];
	   		
	   			if(first==second) {
	   				if(first != 'e' && first != 'o') return false;
	   			}
			}
		}
	   
	   return true;
}

int main() {
	string s="";
	
	while(1) {
		cin>>s;
		if(s=="end") break;
		if(checkCase(s)) cout<<"<"<<s<<"> is acceptable.\n";
		else cout<<"<"<<s<<"> is not acceptable.\n";
	}

	return 0;
}

/*
boj.kr/4659

INPUT:
a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end

OUTPUT:
<a> is acceptable.
<tv> is not acceptable.
<ptoui> is not acceptable.
<bontres> is not acceptable.
<zoggax> is not acceptable.
<wiinq> is not acceptable.
<eep> is acceptable.
<houctuh> is acceptable.
*/
