//Description: Place a knight on a cell (x, y), move the knight to every cell on the chessboard one time and come back to the original cell.
#include <iostream>

using namespace std;
bool founded = false;

void try2MoveAKnight(int x, int y, int n, bool** board, int**& step, int count)
{
	if (founded) {
		return;
	}
	board[x][y] = false;
	char c = 'A' + x;
	step[x][y] = count;
	if (count == n * n) {
		founded = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout.width(2);
				cout << step[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	else {
		if (x + 2 >= 0 && x + 2 < n && y + 1 >= 0 && y + 1 < n && board[x + 2][y + 1] == true && !founded) {
			try2MoveAKnight(x + 2, y + 1, n, board, step, count + 1);
			board[x + 2][y + 1] = true;
			step[x + 2][y + 1] = -1;
		}
		if (x + 2 >= 0 && x + 2 < n && y - 1 >= 0 && y - 1 < n && board[x + 2][y - 1] == true && !founded) {
			try2MoveAKnight(x + 2, y - 1, n, board, step, count + 1);
			board[x + 2][y - 1] = true;
			step[x + 2][y - 1] = -1;
		}
		if (x - 2 >= 0 && x - 2 < n && y + 1 >= 0 && y + 1 < n && board[x - 2][y + 1] == true && !founded) {
			try2MoveAKnight(x - 2, y + 1, n, board, step, count + 1);
			board[x - 2][y + 1] = true;
			step[x - 2][y + 1] = -1;
		}
		if (x - 2 >= 0 && x - 2 < n && y - 1 >= 0 && y - 1 < n && board[x - 2][y - 1] == true && !founded) {
			try2MoveAKnight(x - 2, y - 1, n, board, step, count + 1);
			board[x - 2][y - 1] = true;
			step[x - 2][y - 1] = -1;
		}
		if (x + 1 >= 0 && x + 1 < n && y + 2 >= 0 && y + 2 < n && board[x + 1][y + 2] == true && !founded) {
			try2MoveAKnight(x + 1, y + 2, n, board, step, count + 1);
			board[x + 1][y + 2] = true;
			step[x + 1][y + 2] = -1;
		}
		if (x + 1 >= 0 && x + 1 < n && y - 2 >= 0 && y - 2 < n && board[x + 1][y - 2] == true && !founded) {
			try2MoveAKnight(x + 1, y - 2, n, board, step, count + 1);
			board[x + 1][y - 2] = true;
			step[x + 1][y - 2] = -1;
		}
		if (x - 1 >= 0 && x - 1 < n && y + 2 >= 0 && y + 2 < n && board[x - 1][y + 2] == true && !founded) {
			try2MoveAKnight(x - 1, y + 2, n, board, step, count + 1);
			board[x - 1][y + 2] = true;
			step[x - 1][y + 2] = -1;
		}
		if (x - 1 >= 0 && x - 1 < n && y - 2 >= 0 && y - 2 < n && board[x - 1][y - 2] == true && !founded) {
			try2MoveAKnight(x - 1, y - 2, n, board, step, count + 1);
			board[x - 1][y - 2] = true;
			step[x - 1][y - 2] = -1;
		}
	}
}

void theKnightsTour(int x, int y, int n) {
	int count = 0;
	bool** board = new bool* [n];
	for (int i = 0; i < n; i++) {
		board[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			board[i][j] = true;
		}
	}
	int** step = new int* [n];
	for (int i = 0; i < n; i++) {
		step[i] = new int[n];
		for (int j = 0; j < n; j++) {
			step[i][j] = -1;
		}
	}
	if (x + 2 >= 0 && x + 2 < n && y + 1 >= 0 && y + 1 < n) {
		try2MoveAKnight(x + 2, y + 1, n, board, step, count + 1);
	}
	if (x + 2 >= 0 && x + 2 < n && y - 1 >= 0 && y - 1 < n) {
		try2MoveAKnight(x + 2, y - 1, n, board, step, count + 1);
	}
	if (x - 2 >= 0 && x - 2 < n && y + 1 >= 0 && y + 1 < n) {
		try2MoveAKnight(x - 2, y + 1, n, board, step, count + 1);
	}
	if (x - 2 >= 0 && x - 2 < n && y - 1 >= 0 && y - 1 < n) {
		try2MoveAKnight(x - 2, y - 1, n, board, step, count + 1);
	}
	if (x + 1 >= 0 && x + 1 < n && y + 2 >= 0 && y + 2 < n) {
		try2MoveAKnight(x + 1, y + 2, n, board, step, count + 1);
	}
	if (x + 1 >= 0 && x + 1 < n && y - 2 >= 0 && y - 2 < n) {
		try2MoveAKnight(x + 1, y - 2, n, board, step, count + 1);
	}
	if (x - 1 >= 0 && x - 1 < n && y + 2 >= 0 && y + 2 < n) {
		try2MoveAKnight(x - 1, y + 2, n, board, step, count + 1);
	}
	if (x - 1 >= 0 && x - 1 < n && y - 2 >= 0 && y - 2 < n) {
		try2MoveAKnight(x - 1, y - 2, n, board, step, count + 1);
	}
	if (!founded) {
		cout << "No solution" << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
	for (int i = 0; i < n; i++) {
		delete[] step[i];
	}
	delete[] step;
}

int main() {
	cout << "Enter the size of the chessboard: " << endl;
	int n;
	cin >> n;
	cout << "Enter the position of the knight (0 to " << n - 1 << "): " << endl;
	int firstX, firstY;
	cin >> firstX >> firstY;
	while (firstX < 0 || firstX >= n || firstY < 0 || firstY >= n) {
		cout << "Invalid input. Please enter again!" << endl;
		cin >> firstX >> firstY;
	}
	theKnightsTour(firstX, firstY, n);
	return 0;
}