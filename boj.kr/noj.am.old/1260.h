#ifndef nojam1260
#define nojam1260
#include "../AlgorithmStudy.h"
namespace nojam1260 {
	std::vector<std::vector<int>> adjList(1000);
	std::vector<bool> bfsVisit(1000);
	std::vector<bool> dfsVisit(1000);
	std::vector<bool> dfsVisitStack(1000);
	void adjacencyBFS(int);
	void adjacencyDFSStack(int);
	void adjacencyDFS(int);
	void solution();
}
#endif