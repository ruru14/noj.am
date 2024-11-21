#include "12813.h"

void nojam12813::solution()
{
	char a[100001];
	char b[100001];
	std::bitset<100000> bit_a;
	std::bitset<100000> bit_b;
	std::bitset<100000> tmp;
	scanf(" %s", &a);
	scanf(" %s", &b);

	for (int i = 0; i < 100000; i++) {
		bit_a.set(100000 - 1 - i, bool(a[i] - '0'));
		bit_b.set(100000 - 1 - i, bool(b[i] - '0'));
	}

	tmp = bit_a & bit_b;
	std::cout << tmp << "\n";
	tmp = bit_a | bit_b;
	std::cout << tmp << "\n";
	tmp = bit_a ^ bit_b;
	std::cout << tmp << "\n";
	std::cout << bit_a.flip() << "\n";
	std::cout << bit_b.flip();
}
