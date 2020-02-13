#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	cin>>n;

	unordered_map<string,int> book;
	string s, bookName="";;
	int largest=0;
	
	while(n--) {
		cin>>s;
		
		if(book[s]==0) book[s]=1;
		else book[s]++;
		
		if(largest<book[s]) {
			largest=book[s];
			bookName=s;
		} else if(largest==book[s]) {
			if(bookName.compare(s)>0) bookName=s;
		}
	}

	cout<<bookName;

	return 0;
}

/*
boj.kr/1302

INPUT:
5
top
top
top
top
kimtop

OUTPUT:
top
*/
