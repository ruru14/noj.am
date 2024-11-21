#include "11729.h"

int k = 0;
std::vector<std::pair<int, int>> logs;

int hanoi(int from, int to, int n) 
{
    if (n == 1)
    {
        logs.push_back(std::make_pair(from, to));
        k++;
        return 0;
    }

    hanoi(from, 6 - from - to, n - 1);
    logs.push_back(std::make_pair(from, to));
    k++;
    hanoi(6 - from - to, to, n - 1);
    return 0;
}

void nojam11729::solution()
{
	int n;
	scanf("%d", &n);

    hanoi(1, 3, n);
    printf("%d\n", k);
    for (int i = 0; i < logs.size(); i++) {
        printf("%d %d\n", logs[i].first, logs[i].second);
    }
}
