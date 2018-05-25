#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	string S;
	cin >> S;
	int ans[4] = {};
	for (auto c : S) ans[c - '1']++;

	cout << *max_element(begin(ans), end(ans)) << " " << *min_element(begin(ans), end(ans)) << endl;

	return 0;
}