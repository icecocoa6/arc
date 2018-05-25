#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;

using point = pair<long, long>;

// -1 ~ 1
double grad(point p) {
	return p.first / sqrt(p.first * p.first + p.second * p.second);
}

point operator -(const point &a, const point &b) {
	return {a.first - b.first, a.second - b.second};
}

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	int start, goal;
	cin >> start >> goal;

	deque<point> left;
	deque<point> right;
	vector<point> path;

	vector<pair<long, long>> roads(N+1);
	for (int i = 0; i <= N; i++) cin >> roads[i].first >> roads[i].second;
	roads[0] = {start, start};
	roads[N] = {goal, goal};

	for (int i = 0; i <= N; i++) {
		int l = roads[i].first, r = roads[i].second;
		for (int j = 1; j < left.size(); j++) {
			double m1 = grad(left[j] - left[j - 1]);
			double m2 = grad(point(l, i) - left[j - 1]);
			if (m2 < m1) continue;
			left.erase(begin(left) + j, end(left));
			break;
		}
		left.push_back({l, i});

		for (int j = 1; j < right.size(); j++) {
			double m1 = grad(right[j] - right[j - 1]);
			double m2 = grad(point(r, i) - right[j - 1]);
			if (m1 < m2) continue;
			right.erase(begin(right) + j, end(right));
			break;
		}
		right.push_back({r, i});

		while (left.size() > 1 && right.size() > 1) {
			double lm = grad(left[1] - left[0]);
			double rm = grad(right[1] - right[0]);
			if (lm <= rm) break;

			path.push_back(left[0]);
			if (left[1].second < right[1].second) {
				point s = left[1];
				left.pop_front();
				right.pop_front();
				right.push_front(s);
			} else {
				point s = right[1];
				right.pop_front();
				left.pop_front();
				left.push_front(s);
			}
		}
	}

	path.insert(end(path), begin(left), end(left));

	double ans = 0;
	for (int i = 1; i < path.size(); i++) {
		point d = path[i] - path[i - 1];
		ans += sqrt(d.first * d.first + d.second * d.second);
	}

	cout << fixed << setprecision(20) << ans << endl;


	return 0;
}
