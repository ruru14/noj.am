#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int tc;
    int n;
    int answer;
    string tmp;
    map<string, int> mp;
    cin >> tc;
    while (tc-- > 0) {
        answer = 1;
        mp.clear();
        cin >> n;
        getline(cin, tmp);
        while (n-- > 0) {
            getline(cin, tmp);
            tmp = tmp.substr(tmp.find(' ')+1);
            mp[tmp]++;
        }
        for (auto& i : mp) {
            answer *= i.second + 1;
        }
        cout << answer - 1 << "\n";
    }

}