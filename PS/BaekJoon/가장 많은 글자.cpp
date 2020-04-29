#include <iostream>

using namespace std;

int check[26]{0};

int main() {
	char c;
	
	int mx=0;
	while(cin>>c) {
		if(c>='a' && c<='z') { 
			check[c-'a']+=1; 
			mx=max(mx,check[c-'a']);
		}
	}
	
	for(int i=0; i<26; i++) {
		if(check[i]==mx) {
			cout<<(char)('a'+i);
		}
	}
	
	return 0;
}

/*
INPUT:
english is a west germanic
language originating in england
and is the first language for
most people in the united
kingdom the united states
canada australia new zealand
ireland and the anglophone
caribbean it is used
extensively as a second
language and as an official
language throughout the world
especially in common wealth
countries and in many
international organizations

OUTPUT:
a
*/
