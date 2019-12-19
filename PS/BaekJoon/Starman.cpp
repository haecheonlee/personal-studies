#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, string>> v 
{
	{1967, "DavidBowie"},
	{1969, "SpaceOddity"},
	{1970, "TheManWhoSoldTheWorld"},
	{1971, "HunkyDory"},
	{1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"},
	{1973, "AladdinSane"},
	{1973, "PinUps"},
	{1974, "DiamondDogs"},
	{1975, "YoungAmericans"},
	{1976, "StationToStation"},
	{1977, "Low"},
	{1977, "Heroes"},
	{1979, "Lodger"},
	{1980, "ScaryMonstersAndSuperCreeps"},
	{1983, "LetsDance"},
	{1984, "Tonight"},
	{1987, "NeverLetMeDown"},
	{1993, "BlackTieWhiteNoise"},
	{1995, "1.Outside"},
	{1997, "Earthling"},
	{1999, "Hours"},
	{2002, "Heathen"},
	{2003, "Reality"},
	{2013, "TheNextDay"},
	{2016, "BlackStar"}
};

vector<pair<int, string>> getAlbums(const int &year_start,const int &year_end) {
	vector<pair<int, string>> albums;
	
	for(int i=0; i<v.size(); i++) {
		if(v[i].first >= year_start && v[i].first <= year_end) {
			albums.push_back(make_pair(v[i].first, v[i].second));
		}
		
		if(v[i].first > year_end) break;
	}
	
	return albums;
}

void showAlbums(const vector<pair<int, string>> &albums) {
	cout<<albums.size()<<endl;
	
	for(int i=0; i<albums.size(); i++) {
		cout<<albums[i].first<<" "<<albums[i].second<<endl;
	}
}

int main() {
	int Q;
	cin>>Q;
	
	int year1, year2;
	for(int i=0; i<Q; i++) {
		cin>>year1>>year2;
	
		vector<pair<int, string>> a = getAlbums(year1, year2);
		showAlbums(a);
	}

	return 0;
}

/*
boj.kr/12791

INPUT:
3
1973 1973
1977 1979
2014 2015

OUTPUT:
2
1973 AladdinSane
1973 PinUps
3
1977 Low
1977 Heroes
1979 Lodger
0
*/
