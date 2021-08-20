#include "Libs.h"

//std::string Libs::plus_bignum(std::string a, std::string b) {
//	int carry = 0;
//	int a_size = a.size() - 1;
//	int b_size = b.size() - 1;
//	if (a_size < b_size) {
//		int tmp_i = a_size;
//		a_size = b_size;
//		b_size = tmp_i;
//
//		std::string tmp_s(a);
//		a = b;
//		b = tmp_s;
//	}
//	std::stack<char> tmp;
//	std::string ans;
//
//	while (b_size != -1) {
//		int res = a[a_size--] - 48 + b[b_size--] - 48 + carry;
//		carry = 0;
//		if (res >= 10) {
//			res -= 10;
//			carry++;
//		}
//		tmp.push(res + 48);
//	}
//
//	while (a_size != -1) {
//		if (carry != 0) {
//			carry = 0;
//			tmp.push(a[a_size--] + 1);
//		}
//		tmp.push(a[a_size--]);
//	}
//
//	while (!tmp.empty()) {
//		ans += tmp.top();
//		tmp.pop();
//	}
//
//	return ans;
//}
//
//std::string Libs::minus_temp(std::string a, std::string b) {
//	int a_size = a.size() - 1;
//	int b_size = b.size() - 1;
//	int borrow = 0;
//	std::stack<char> tmp;
//	std::string ans;
//
//	while (b_size != -1) {
//		int res = (a[a_size--] - 48) - (b[b_size--] - 48) + borrow;
//		borrow = 0;
//		if (res < 0) {
//			res += 10;
//			borrow = -1;
//		}
//		tmp.push(res + 48);
//	}
//
//	while (a_size != -1) {
//		if (a_size == 0 & a[a_size] + borrow == 48)
//			break;
//		tmp.push(a[a_size--] + borrow);
//		if (borrow != 0)
//			borrow = 0;
//	}
//
//	while (!tmp.empty()) {
//		ans += tmp.top();
//		tmp.pop();
//	}
//
//	return ans;
//}