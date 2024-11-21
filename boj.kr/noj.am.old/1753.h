#ifndef nojam1753
#define nojam1753
#include "../AlgorithmStudy.h"
namespace nojam1753 {
	int get_next(int current, int vertex, std::vector<std::vector<std::pair<int, int>>> map, std::vector<bool> visit);
	void dijkstra(int start, std::vector<std::vector<std::pair<int, int>>> map);
	void solution();
}

#endif