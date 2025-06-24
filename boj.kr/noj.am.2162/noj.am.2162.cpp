// noj.am.2162.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

struct Point {
    int x;
    int y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct Line {
    Point pS;
    Point pE;
};

int ccw(Point a, Point b, Point c) {
    int flag = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (flag == 0) return 0;
    else return (flag > 0) ? 1 : -1;
}

bool isOnSegment(Point p, Point a, Point b) {
    return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
        min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

bool isIntersect(Line line1, Line line2) {
    Point a = line1.pS, b = line1.pE;
    Point c = line2.pS, d = line2.pE;

    int ab_c = ccw(a, b, c);
    int ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a);
    int cd_b = ccw(c, d, b);

    int ab1 = ab_c * ab_d;
    int ab2 = cd_a * cd_b;

    if (ab1 <= 0 && ab2 <= 0) {
        if (ab1 == 0 && ab2 == 0) {
            return isOnSegment(a, c, d) || isOnSegment(b, c, d) ||
                isOnSegment(c, a, b) || isOnSegment(d, a, b);
        } else {
            return true;
        }
    }

    return false;
}

class DisjointSet {
private:
    vector<int> parent;
public:

    DisjointSet(int n) {
        parent.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int Find(int n) {
        if (parent[n] != n) parent[n] = Find(parent[n]);
        return parent[n];
    }
    
    void Union(int a, int b) {
        parent[Find(a)] = Find(b);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, ans = 0;
	cin >> n;
	vector<Line> lines;
    set<int> group;
    vector<int> groupSize(n, 0);
    DisjointSet ds(n);
	for (int i = 0; i < n; i++) {
		Line foo;
		cin >> foo.pS.x >> foo.pS.y >> foo.pE.x >> foo.pE.y;
		lines.push_back(foo);
	}

    for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
            if (isIntersect(lines[i], lines[j])) {
                ds.Union(i, j);
            }
		}
	}

    for (int i = 0; i < n; i++) {
        int curRoot = ds.Find(i);
        group.insert(curRoot);
        groupSize[curRoot]++;
        ans = max(ans, groupSize[curRoot]);
    }

    cout << group.size() << "\n";
    cout << ans;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
