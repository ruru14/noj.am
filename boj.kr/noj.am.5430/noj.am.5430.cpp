#include <iostream>
#include <string>
#include <sstream>
#include <deque>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--) {
		deque<int> dq;
		bool flag = true, isError = false;
		string ord;
		cin >> ord;
		int n;
		cin >> n;
		string arr;
		cin >> arr;
		stringstream ss(arr.substr(1, arr.size() - 2));
		string num;
		while (getline(ss, num, ',')) {
			dq.push_back(stoi(num));
		}
		for (auto& i : ord) {
			if (i == 'R') {
				flag = !flag;
			} else {
				if (dq.empty()) {
					isError = true;
					break;
				}
				if (flag) {
					dq.pop_front();
				} else {
					dq.pop_back();
				}
			}
		}

		if (isError) {
			cout << "error\n";
		} else {
			cout << "[";
			while (!dq.empty()) {
				if (flag) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty()) cout << ",";
				} else {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}