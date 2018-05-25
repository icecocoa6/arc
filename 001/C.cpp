#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<int> &board) {
	for (int i = 0; i < 8; i++) {
		if (board[i] == -1) continue;
		for (int j = i + 1; j < 8; j++) {
			if (board[j] == -1) continue;
			if (board[i] == board[j] || abs(i - j) == abs(board[i] - board[j]))
				return false;
		}
	}
	return true;
}

bool dfs(int idx, vector<int> &board) {
	if (!check(board)) return false;
	if (idx == 8) return true;
	if (board[idx] != -1)
		return dfs(idx + 1, board);

	for (int i = 0; i < 8; i++) {
		board[idx] = i;
		if (dfs(idx + 1, board)) return true;
	}
	board[idx] = -1;
	return false;
}

int main(int argc, char *argv[]) {
	vector<int> board(8, -1);
	for (int i = 0; i < 8; i++) {
		string l;
		cin >> l;
		for (int j = 0; j < 8; j++) {
			if (l[j] == 'Q') {
				if (board[i] != -1) {
					printf("No Answer\n");
					return 0;
				}
				board[i] = j;
			}
		}
	}

	if (!dfs(0, board)) {
		printf("No Answer\n");
		return 0;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i] == j) printf("Q");
			else printf(".");
		}
		printf("\n");
	}

	return 0;
}