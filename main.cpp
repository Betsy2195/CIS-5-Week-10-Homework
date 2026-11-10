#include <iostream>

// Practice 10 — Betsy Caudel
// CIS 5 Week 10 · Gradebook tools

using std::cout;
using std::endl;

void printScores(const int scores[], int n) {
  for (int i = 0; i < n; i++) cout << scores[i] << " ";
  cout << endl;
}

void curve(int scores[], int n, int points) {
  // Adds points to every score
  for (int i = 0; i < n; i++) scores[i] += points;
}

void minMax(const int scores[], int n, int& lo, int& hi) {
  lo = scores[0];
  hi = scores[0];
  for (int i = 0; i < n; i++){
    // Checks for highest index value.
    if (scores[i] > hi) hi = scores[i];
    // Checks for lowest index value.
    if (scores[i] < lo) lo = scores[i];
  }
}

bool findScore(const int scores[], int n, int target, int* where) {
  for (int i = 0; i < n; i++){
    if (scores[i] == target){
      // Writes the index through pointer only if not null.
      if (where != nullptr){
          *where = i;
      }
      // If target is found, will finish.
      return true;
    }
  }
  // Target was not found at any index.
  return false;
}

int main() {
  int scores[5] = {72, 88, 95, 60, 81};
  const int N = 5;

  cout << "Before: ";
  printScores(scores, N);

  int lo = 0, hi = 0;
  minMax(scores, N, lo, hi);
  cout << "Low: " << lo << "  High: " << hi << endl;

  curve(scores, N, 5);
  cout << "After curve +5: ";
  printScores(scores, N);

  int at = -1;
  if (findScore(scores, N, 100, &at)) cout << "100 found at index " << at << endl;
  if (!findScore(scores, N, 50, nullptr)) cout << "50 not found" << endl;
  return 0;
}
