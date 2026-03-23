/*
 * Problem: A. Forked!
 * Contest: 1904 | Problem A
 * Link: https://codeforces.com/contest/1904/problem/A
 *
 * --- Input ---
 * Each test contains multiple test cases. The first line contains an integer $$$t$$$ ($$$1 \leq t \leq 1000$$$) — the number of test cases. The description of the test cases follows. The first line of each test case contains two integers $$$a$$$ and $$$b$$$ ($$$1 \le a, b \le 10^8$$$) — describing the possible moves of the knight. The second line of each test case contains two integers $$$x_K$$$ and $$$y_K$$$ ($$$0 \le x_K, y_K \le 10^8$$$) — the position of Lunchbox's king. The third line in a test case contains $$$x_Q$$$ and $$$y_Q$$$ ($$$0 \le x_Q, y_Q \le 10^8$$$) — the position of Lunchbox's queen. It is guaranteed that Lunchbox's queen and king will occupy different cells. That is, $$$(x_K,y_K) \neq (x_Q,y_Q)$$$. Output For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen. Example Input 4 2 1 0 0 3 3 1 1 3 1 1 3 4 4 0 0 8 0 4 2 1 4 3 4 Output 2 1 2 0
 *
 * --- Output ---
 * For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen. Example Input 4 2 1 0 0 3 3 1 1 3 1 1 3 4 4 0 0 8 0 4 2 1 4 3 4 Output 2 1 2 0
 *
 * --- Example Input ---
 * 4 2 1 0 0 3 3 1 1 3 1 1 3 4 4 0 0 8 0 4 2 1 4 3 4
 *
 * --- Example Output ---
 * 2 1 2 0
 *
 */

#include <bits/stdc++.h>
using namespace std;

// Arrays to represent the possible directions a knight can move
int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

int main()
{
	int t; // Number of test cases
	cin >> t;
	while (t--)
	{
		long long a, b; // Knight's move parameters
		cin >> a >> b;
		long long x_king, y_king; // Position of the king
		cin >> x_king >> y_king;
		long long x_queen, y_queen; // Position of the queen
		cin >> x_queen >> y_queen;
		// Inputs are read

		// Sets to store positions attacked by the knight when placed to attack king and queen
		set<pair<int, int>> king_hits, queen_hits;

		// Calculate all possible positions that can be attacked by the knight
		for (int j = 0; j < 4; j++)
		{
			// Calculate positions attacked by the knight when placed to attack the king
			king_hits.insert({x_king + dx[j] * a, y_king + dy[j] * b});
			king_hits.insert({x_king + dx[j] * b, y_king + dy[j] * a});

			// Calculate positions attacked by the knight when placed to attack the queen
			queen_hits.insert({x_queen + dx[j] * a, y_queen + dy[j] * b});
			queen_hits.insert({x_queen + dx[j] * b, y_queen + dy[j] * a});
		}

		int ans = 0; // Variable to store the number of positions where the knight can fork the king and queen
		// Check for common positions in both sets
		for (auto position : king_hits)
			if (queen_hits.find(position) != queen_hits.end())
				ans++;

		cout << ans << endl; // Output the result for the current test case
	}
	return 0;
}

// Time Complexity (TC): O(8*log2(8)) = O(8*3) = O(24)
// Space Complexity (SC): O(8)
