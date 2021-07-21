#include "10773.h"

void nojam10773::solution()
{
	int n, sum = 0;
	std::stack<int> st;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			st.pop();
		}
		else {
			st.push(tmp);
		}
	}

	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	printf("%d", sum);
}
