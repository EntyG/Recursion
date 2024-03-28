// Description: Find the maximum number of queens that can be placed on a chessboard of size N x N without attacking each other.
#include <iostream>

using namespace std;

bool canPlaceAQueen(int row, int col, int n, bool** placed) {
	for (int i = 0; i < n ; i++) {
		if (placed[i][col] == true) {
			return false;
		}
	}
	for (int j = 0; j < n; j++) {
		if (placed[row][j] == true) {
			return false;
		}
	}
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (placed[i][j] == true) {
			return false;
		}
	}
	for (int i = row, j = col; i < n && j < n; i++, j++) {
		if (placed[i][j] == true) {
			return false;
		}
	}
	for (int i = row, j = col; i < n && j >= 0; i++, j--) {
		if (placed[i][j] == true) {
			return false;
		}
	}
	for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
		if (placed[i][j] == true) {
			return false;
		}
	}
	return true;
}

void print(bool** placed, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << placed[i][j] << " ";
		}
		cout << endl;
	}
}

void putAQueenOnARow(int row, const int& n, bool**& placed, int& count, int& max, bool**& bestSolve) {
	if (row == n) {
		if (count > max) {
			max = count;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					bestSolve[i][j] = placed[i][j];
				}
			}
		}
		return;
	}
	for (int col = 0; col < n; col++) {
		if (canPlaceAQueen(row, col, n, placed)) {
			placed[row][col] = true;
			count++;
			putAQueenOnARow(row + 1, n, placed, count, max, bestSolve);
			placed[row][col] = false;
			count--;
		}
	}
	putAQueenOnARow(row + 1, n, placed, count, max, bestSolve);
}

int main() {
	int n;
	cin >> n;
	bool** placed = new bool* [n];
	for (int i = 0; i < n; i++) {
		placed[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			placed[i][j] = false;
		}
	}
	bool** bestSolve = new bool* [n];
	for (int i = 0; i < n; i++) {
		 bestSolve[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			bestSolve[i][j] = false;
		}
	}
	int max = 0;
	int count = 0;
	putAQueenOnARow(0, n, placed, count, max, bestSolve);
	cout << "Can place max " << max << " Queens" << endl;
	print(bestSolve, n);
	for (int i = 0; i < n; i++) {
		delete[] placed[i];
	}
	delete[] placed;
	for (int i = 0; i < n; i++) {
		delete[] bestSolve[i];
	}
	delete[] bestSolve;
	return 0;
}

// Print all solves version
//#include <list>
//
//void printlist(list<bool**> bestSolves, int n) {
//	for (auto it = bestSolves.begin(); it != bestSolves.end(); it++) {
//		bool** bestSolve = *it;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << bestSolve[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//}
//
//void putAQueenOnARow(int row, const int& n, bool**& placed, int& count, int& max, list<bool**>& bestSolves) {
//	if (row == n) {
//		if (count > max) {
//			max = count;
//			bool** bestSolve = new bool* [n];
//			for (int i = 0; i < n; i++) {
//				bestSolve[i] = new bool[n];
//				for (int j = 0; j < n; j++) {
//					bestSolve[i][j] = false;
//				}
//			}
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					bestSolve[i][j] = placed[i][j];
//				}
//			}
//			bestSolves.clear();
//			bestSolves.push_back(bestSolve);
//		}
//		else if (count == max) {
//			bool** bestSolve = new bool* [n];
//			for (int i = 0; i < n; i++) {
//				bestSolve[i] = new bool[n];
//				for (int j = 0; j < n; j++) {
//					bestSolve[i][j] = false;
//				}
//			}
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					bestSolve[i][j] = placed[i][j];
//				}
//			}
//			bestSolves.push_back(bestSolve);
//		}
//		return;
//	}
//	for (int col = 0; col < n; col++) {
//		if (canPlaceAQueen(row, col, n, placed)) {
//			placed[row][col] = true;
//			count++;
//			putAQueenOnARow(row + 1, n, placed, count, max, bestSolves);
//			placed[row][col] = false;
//			count--;
//		}
//	}
//	putAQueenOnARow(row + 1, n, placed, count, max, bestSolves);
//}
//
//int main() {
//	cout << "N = ";
//	int n;
//	cin >> n;
//	bool** placed = new bool* [n];
//	for (int i = 0; i < n; i++) {
//		placed[i] = new bool[n];
//		for (int j = 0; j < n; j++) {
//			placed[i][j] = false;
//		}
//	}
//	list<bool**> bestSolves;
//	int max = 0;
//	int count = 0;
//	putAQueenOnARow(0, n, placed, count, max, bestSolves);
//	cout << "Can place max " << max << " Queens" << endl;
//	printlist(bestSolves, n);
//	for (int i = 0; i < n; i++) {
//		delete[] placed[i];
//	}
//	delete[] placed;
//	return 0;
//}