#include "15829.h"

unsigned long long get_single_hash(long long word, long long r, int i, long long Mod) {
	unsigned long long hash = word;
	for (int j = 0; j < i; j++) {
		hash = ((hash % Mod) * (r % Mod)) % Mod;
	}
	hash = hash % Mod;
	return hash;
}

void nojam15829::solution()
{
	int l;
	unsigned long long ans = 0;
	std::string word;
	scanf("%d", &l);
	scanf("%d");
	std::getline(std::cin, word);
	for (int i = 0; i < word.size(); i++) {
		ans += get_single_hash(word[i] - 96, 31, i, 1234567891);
	}

	printf("%lld", ans);
}
