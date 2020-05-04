#include <iostream>

using namespace std;

int main() {
	string s;
	int index=1;
	
	while(1) {
		cin>>s;
		
		if(s[0]=='-') break;
		
		int cnt=0, ans=0, len=s.size();
		for(int i=0; i<len; i++) {
			if(s[i]=='{') {
				cnt++;
			} else {
				cnt--;
				if(cnt==-1) {
					cnt=1;
					ans++;
				}
			}
		}
		
		printf("%d. %d\n", index++, cnt/2+ans);
	}

	return 0;
}

/*
INPUT:
}{
{}{}{}
{{{}
---

OUTPUT:
1. 2
2. 0
3. 1
*/
