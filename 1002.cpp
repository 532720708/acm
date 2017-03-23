#include <cstdio>

const int N = 101;

int main() {
	int a[N];
	int n, i, max, min;

	while (scanf("%d", &n) == 1) {
		max = -1, min = 101;

		for (i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i] > max) max = a[i];
			if (a[i] < min) min = a[i];
		}
		printf("%d %d\n", max, min);
	}
	return 0;
}
