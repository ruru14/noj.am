#include <iostream>
#include <set>
#include <utility>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int n, input;
	multiset<pair<int, int>> h;
	vector<int> answer;
	cin >> n;
	while (n-- > 0) {
		cin >> input;
		if (input == 0) {
			if (h.empty()) answer.push_back(0);
			else {
				answer.push_back((*h.begin()).second);
				h.erase(h.begin());
			}
		} else {
			h.insert(make_pair(abs(input), input));
		}
	}
	for (auto& i : answer) {
		cout << i << "\n";
	}
}