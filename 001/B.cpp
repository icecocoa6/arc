#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int A, B;
	cin >> A >> B;
	int d = abs(A - B);

	int cnt = 0;
	while (d > 0) {
		d = min(abs(d - 10), min(abs(d - 5), d - 1));
		cnt += 1;
	}

	cout << cnt << endl;
}