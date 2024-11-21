#include "1697.h"

int n, k;
bool visit[100001];
std::vector<std::vector<int>> adjList(100001);

void build(int start) {
	if (start < 0 | start > k)
		return;
	adjList[start].push_back(start + 1);
	adjList[start].push_back(start - 1);
	adjList[start].push_back(start * 2);
	build(start + 1);
	build(start - 1);
	build(start * 2);
	printf("? ");
}

void nojam1697::solution()
{
	scanf("%d %d", &n, &k);
	build(n);

	printf("%d", adjList.size());
}
