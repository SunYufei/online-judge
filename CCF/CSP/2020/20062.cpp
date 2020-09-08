#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b, x, y, i, j;
	long long innerProduct = 0;
	scanf("%d%d%d", &n, &a, &b);
    
	vector<pair<int, int>> v;

	for (i = 0; i < a; ++i) {
		scanf("%d%d", &x, &y);
		v.emplace_back(make_pair(x, y));
	}

	for (i = 0, j = 0; j < b; ++j) {
		scanf("%d%d", &x, &y);
		while(i < a) {
			if (x < v[i].first) {
				break;
			} else if (x > v[i].first) {
				++i;
			} else {
				innerProduct += y * v[i].second;
				++i;
			}
		}
	}
    
	printf("%lld", innerProduct);
	return 0;
}