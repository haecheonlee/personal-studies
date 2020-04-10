#include <iostream>
using namespace std;
using Point = pair<long long, long long>;
using Line = pair<Point, Point>;
int ccw(Point p1, Point p2, Point p3) {
    long long temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    temp -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;
    if (temp > 0) return 1;
    if (temp < 0) return -1;
    return 0;
}
bool cross(Line l1, Line l2) {
    int l1l2 = ccw(l1.first, l1.second, l2.first) * ccw(l1.first, l1.second, l2.second);
    int l2l1 = ccw(l2.first, l2.second, l1.first) * ccw(l2.first, l2.second, l1.second);

    if (l1l2 == 0 && l2l1 == 0) {
        if (l1.first > l1.second) {
            swap(l1.first, l1.second);
        }
        if (l2.first > l2.second) {
            swap(l2.first, l2.second);
        }
        return l2.first <= l1.second && l1.first <= l2.second;
    }
    return l1l2 <= 0 && l2l1 <= 0;
}
int main() {
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    Line l1 = {{x1, y1}, {x2, y2}};
    Line l2 = {{x3, y3}, {x4, y4}};
    cout << cross(l1, l2) << '\n';
    return 0;
}

/*
INPUT:
1 1 5 5
1 5 5 1

OUTPUT:
1
*/
