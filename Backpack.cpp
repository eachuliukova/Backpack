#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector <int> cost(n);
	vector <int> mass(n);

	for (int i = 0; i < n; i++) cin >> cost[i] >> mass[i];

	for (int i = 0; i < n-1; i++) {
		if (cost[i+1] > cost[i]) {
			swap(cost[i], cost[i+1]);
			swap(mass[i], mass[i+1]);
		}
	}
	for (int i = 0; i <= 0; i++) {
		if ((cost[i + 1] == cost[i]) and (mass[i + 1] < mass[i])) {
			swap(mass[i], mass[i + 1]);
			swap(cost[i], cost[i + 1]);
		}
	}

	int p = 0;
	int q = p;

	for (int i = 0; i < n; i++) {
		if (p + mass[i] <= m) {
			q += cost[i];
			p += mass[i];
		}
	}
	cout << q;
}