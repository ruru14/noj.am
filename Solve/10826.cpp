#include "10826.h"

std::string plus_bignum(std::string a, std::string b) {
	int carry = 0;
	int a_size = a.size() - 1;
	int b_size = b.size() - 1;
	std::stack<char> tmp;
	std::string ans;

	while (a_size != -1 & b_size != -1) {
		int res = a[a_size--] - 48 + b[b_size--] - 48 + carry;
		carry = 0;
		if (res >= 10) {
			res -= 10;
			carry++;
		}
		tmp.push(res + 48);
	}

	if (a_size == -1 & b_size == -1) {
		if (carry == 1) {
			carry = 0;
			tmp.push(49);
		}
	}
	while (a_size != -1) {
		tmp.push(a[a_size--] + carry);
		carry = 0;
	}
	while (b_size != -1) {
		tmp.push(a[b_size--] + carry);
		carry = 0;
	}

	while (!tmp.empty()) {
		ans += tmp.top();
		tmp.pop();
	}

	return ans;
}

std::string minus_temp(std::string a, std::string b) {
	int a_size = a.size() - 1;
	int b_size = b.size() - 1;
	int borrow = 0;
	std::stack<char> tmp;
	std::string ans;

	while (b_size != -1) {
		int res = (a[a_size--] - 48) - (b[b_size--] - 48) + borrow;
		borrow = 0;
		if (res < 0) {
			res += 10;
			borrow = -1;
		}
		tmp.push(res + 48);
	}

	while (a_size != -1) {
		if (a_size == 0 & a[a_size] + borrow == 48)
			break;
		if (a[a_size] + borrow < 48) {
			tmp.push(a[a_size--] + borrow + 10);
			borrow = -1;
		}
		else {
			tmp.push(a[a_size--] + borrow);
			borrow = 0;
		}
	}

	while (!tmp.empty()) {
		ans += tmp.top();
		tmp.pop();
	}

	return ans;
}

std::vector<std::string> mem(10001, "0");

std::string fibo(std::string n) {
	int index = std::stoi(n);
	if (std::stoi(n) < 2)
		return n;
	if (mem[index].compare("0") == 0) {
		mem[index] = plus_bignum(fibo(minus_temp(n, "1")), fibo(minus_temp(n, "2")));
	}

	return mem[index];
}

void nojam10826::solution()
{
	int n;
	scanf("%d", &n);
	printf("%s", fibo(std::to_string(n)).c_str());
}
