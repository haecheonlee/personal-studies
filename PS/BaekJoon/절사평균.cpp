#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void roundUpToTwoDecimal(double &mean) {
    mean = round(mean * 100) / 100;
}

int main()
{
    int N, K;
    cin>>N>>K;

    double trimmed_mean = 0;
    double adjusted_mean = 0;
    
    vector<double> v;
    double num = 0.0;
    for(int i=0; i<N; i++) {
        cin>>num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());

    auto begin = v.begin() + K;
    auto end = v.end() - K;
    
    // trimmed_mean
    for(auto it = begin; it<end; it++) {
        trimmed_mean += *it;    
    }
    
    trimmed_mean /= (N - (K *2));
    roundUpToTwoDecimal(trimmed_mean);
    cout<<fixed<<setprecision(2)<<trimmed_mean<<endl;

    // adjusted_mean
    for(auto it = begin; it<end; it++) {
        if(it == begin) adjusted_mean += (*it * (K+1)); 
        else if(it == (end-1)) adjusted_mean += (*it * (K+1));
        else adjusted_mean += *it;
    }
    
    adjusted_mean /= N;
    roundUpToTwoDecimal(adjusted_mean);
    cout<<fixed<<setprecision(2)<<adjusted_mean<<endl;

    return 0;
}

/*
boj.kr/6986

INPUT:
7 2
9.3
9.5
9.6
9.8
9.1
5.0
9.3

OUTPUT:
9.37
9.39
*/
