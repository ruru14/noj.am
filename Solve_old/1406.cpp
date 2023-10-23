#include "1406.h"

void clear() {
	while (getchar() != '\n');
}

void nojam1406::solution()
{
	char input;
	int m;
	std::list<char> editor;

	do {
		input = getchar();
		editor.push_back(input);
	} while (input != '\n');
	//getchar();
	editor.remove('\n');
	//clear();
	
	std::list<char>::iterator cur = editor.end();
	/*while (cur != editor.end()) {
		printf("%c", *cur);
		cur++;
	}
	putchar('\n');

	for (auto i = editor.begin(); i != editor.end(); i++) {
		printf("%c", *i);
	}*/

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char order, chr;
		clear();
		scanf("%c", &order);
		if (order == 'P') {
			scanf("%d");
			scanf("%c", &chr);
			editor.insert(cur, chr);
		}
		else if (order == 'L') {
			if (cur != editor.begin()) {
				cur--;
			}
		}
		else if (order == 'D') {
			if (cur != editor.end()) {
				cur++;
			}
		}
		else if (order == 'B') {
			if (cur != editor.begin()) {
				cur = editor.erase(--cur);
			}
		}
	}

	for (auto i = editor.begin(); i != editor.end(); i++) {
		printf("%c", *i);
	}

	/*printf("%d\n", editor.size());

	for (auto i : editor) {
		printf("%c", i);
	}*/
}
