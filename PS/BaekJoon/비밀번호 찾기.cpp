#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	
	unordered_map<string,string> sites;
	string site,pwd;
	
	for(int i=0; i<n; i++) {
		cin>>site>>pwd;
		sites[site]=pwd;
	}
	
	for(int i=0; i<m; i++) {
		cin>>site;
		cout<<sites[site]<<'\n';
	}

	return 0;
}

/*
boj.kr/17219

INPUT:
16 4
noj.am IU
acmicpc.net UAENA
startlink.io THEKINGOD
google.com ZEZE
nate.com VOICEMAIL
naver.com REDQUEEN
daum.net MODERNTIMES
utube.com BLACKOUT
zum.com LASTFANTASY
dreamwiz.com RAINDROP
hanyang.ac.kr SOMEDAY
dhlottery.co.kr BOO
duksoo.hs.kr HAVANA
hanyang-u.ms.kr OBLIVIATE
yd.es.kr LOVEATTACK
mcc.hanyang.ac.kr ADREAMER
startlink.io
acmicpc.net
noj.am
mcc.hanyang.ac.kr

OUTPUT:
THEKINGOD
UAENA
IU
ADREAMER
*/
