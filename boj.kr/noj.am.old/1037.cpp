#include "1037.h"

void nojam1037::solution()
{
    int n;
    std::vector<int> arr;
    scanf("%d", &n);

    while (n--) {
        int tmp;
        scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    std::sort(arr.begin(), arr.end());

    printf("%d", arr[0] * arr[arr.size() - 1]);
}
