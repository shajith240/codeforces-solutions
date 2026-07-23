/*
 * Problem: Maximize Active Section with Trade II
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/maximize-active-section-with-trade-ii/
 * Language: cpp
 * Topics: Array, String, Binary Search, Segment Tree
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given a binary string s of length n , where:
 * • &#39;1&#39; represents an active section.
 * • &#39;0&#39; represents an inactive section.
 * You can perform at most one trade to maximize the number of active sections in s . In a trade, you:
 * • Convert a contiguous block of &#39;1&#39; s that is surrounded by &#39;0&#39; s to all &#39;0&#39; s.
 * • Afterward, convert a contiguous block of &#39;0&#39; s that is surrounded by &#39;1&#39; s to all &#39;1&#39; s.
 * Additionally, you are given a 2D array queries , where queries[i] = [l i , r i ] represents a substring s[l i ...r i ] .
 * For each query, determine the maximum possible number of active sections in s after making the optimal trade on the substring s[l i ...r i ] .
 * Return an array answer , where answer[i] is the result for queries[i] .
 * Note
 * • For each query, treat s[l i ...r i ] as if it is augmented with a &#39;1&#39; at both ends, forming t = &#39;1&#39; + s[l i ...r i ] + &#39;1&#39; . The augmented &#39;1&#39; s do not contribute to the final count.
 * • The queries are independent of each other.
 * Example 1:
 * Input: s = &quot;01&quot;, queries = [[0,1]]
 * Output: [1]
 * Explanation:
 * Because there is no block of &#39;1&#39; s surrounded by &#39;0&#39; s, no valid trade is possible. The maximum number of active sections is 1.
 * Example 2:
 * Input: s = &quot;0100&quot;, queries = [[0,3],[0,2],[1,3],[2,3]]
 * Output: [4,3,1,1]
 * Explanation:
 * •
 * Query [0, 3] &rarr; Substring &quot;0100&quot; &rarr; Augmented to &quot;101001&quot;
 * Choose &quot;0100&quot; , convert &quot;0100&quot; &rarr; &quot;0000&quot; &rarr; &quot;1111&quot; .
 * The final string without augmentation is &quot;1111&quot; . The maximum number of active sections is 4.
 * •
 * Query [0, 2] &rarr; Substring &quot;010&quot; &rarr; Augmented to &quot;10101&quot;
 * Choose &quot;010&quot; , convert &quot;010&quot; &rarr; &quot;000&quot; &rarr; &quot;111&quot; .
 * The final string without augmentation is &quot;1110&quot; . The maximum number of active sections is 3.
 * •
 * Query [1, 3] &rarr; Substring &quot;100&quot; &rarr; Augmented to &quot;11001&quot;
 * Because there is no block of &#39;1&#39; s surrounded by &#39;0&#39; s, no valid trade is possible. The maximum number of active sections is 1.
 * •
 * Query [2, 3] &rarr; Substring &quot;00&quot; &rarr; Augmented to &quot;1001&quot;
 * Because there is no block of &#39;1&#39; s surrounded by &#39;0&#39; s, no valid trade is possible. The maximum number of active sections is 1.
 * Example 3:
 * Input: s = &quot;1000100&quot;, queries = [[1,5],[0,6],[0,4]]
 * Output: [6,7,2]
 * Explanation:
 * Query [1, 5] &rarr; Substring &quot;00010&quot; &rarr; Augmented to &quot;1000101&quot;
 * Choose &quot;00010&quot; , convert &quot;00010&quot; &rarr; &quot;00000&quot; &rarr; &quot;11111&quot; .
 * The final string without augmentation is &quot;1111110&quot; . The maximum number of active sections is 6.
 * Query [0, 6] &rarr; Substring &quot;1000100&quot; &rarr; Augmented to &quot;110001001&quot;
 * Choose &quot;000100&quot; , convert &quot;000100&quot; &rarr; &quot;000000&quot; &rarr; &quot;111111&quot; .
 * The final string without augmentation is &quot;1111111&quot; . The maximum number of active sections is 7.
 * Query [0, 4] &rarr; Substring &quot;10001&quot; &rarr; Augmented to &quot;1100011&quot;
 * Because there is no block of &#39;1&#39; s surrounded by &#39;0&#39; s, no valid trade is possible. The maximum number of active sections is 2.
 * Example 4:
 * Input: s = &quot;01010&quot;, queries = [[0,3],[1,4],[1,3]]
 * Output: [4,4,2]
 * Explanation:
 * •
 * Query [0, 3] &rarr; Substring &quot;0101&quot; &rarr; Augmented to &quot;101011&quot;
 * Choose &quot;010&quot; , convert &quot;010&quot; &rarr; &quot;000&quot; &rarr; &quot;111&quot; .
 * The final string without augmentation is &quot;11110&quot; . The maximum number of active sections is 4.
 * •
 * Query [1, 4] &rarr; Substring &quot;1010&quot; &rarr; Augmented to &quot;110101&quot;
 * Choose &quot;010&quot; , convert &quot;010&quot; &rarr; &quot;000&quot; &rarr; &quot;111&quot; .
 * The final string without augmentation is &quot;01111&quot; . The maximum number of active sections is 4.
 * •
 * Query [1, 3] &rarr; Substring &quot;101&quot; &rarr; Augmented to &quot;11011&quot;
 * Because there is no block of &#39;1&#39; s surrounded by &#39;0&#39; s, no valid trade is possible. The maximum number of active sections is 2.
 * Constraints:
 * • 1 <= n == s.length <= 10 5
 * • 1 <= queries.length <= 10 5
 * • s[i] is either &#39;0&#39; or &#39;1&#39; .
 * • queries[i] = [l i , r i ]
 * • 0 <= l i <= r i < n
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: Split consecutive zeros and ones into segments and give each segment an ID.
 * Hint 2: The answer should be the maximum of ans[i] = len[i - 1] + len[i + 1] , where i is a one-segment.
 * Hint 3: For a zero-segment, define ans[i] = 0 .
 * Hint 4: Note that all three segments ( i - 1 , i , and i + 1 ) should be fully covered by the substring.
 * Hint 5: Use a segment tree to perform range maximum queries on the answer. The query to the segment tree is not straightforward since we need to ensure the zero-segments are fully covered. Handle the first and last segments separately.
 * 
 */

void buildSegmentTree(int i, int l, int r, int segmentTree[], int arr[]) {
    if (l == r) {
        segmentTree[i] = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, arr);
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, arr);
    segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
}

int* constructST(int arr[], int n) {
    int* segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, arr);
    return segmentTree;
}

int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[]) {
    if (l > end || r < start) {
        return INT_MIN;
    }

    if (l >= start && r <= end) {
        return segmentTree[i];
    }

    int mid = l + (r - l) / 2;
    return max(querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree),
               querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree));
}

int RMQ(int st[], int n, int a, int b) {
    return querySegmentTree(a, b, 0, 0, n - 1, st);
}

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int activeCount = count(begin(s), end(s), '1');

        vector<int> blockStart;
        vector<int> blockEnd;


        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;
                blockStart.push_back(start);
                blockEnd.push_back(i-1);
            } else {
                i++;
            }
        }  

        int m = blockStart.size();

        //If there is only one block of zeros
        //example : s = "11000011" , answer = simply count of 1s "activeCount"
        if(m < 2) {
            return vector<int>(queries.size(), activeCount);
        }

        vector<int> blockSize(m);
        for(int i = 0; i < m; i++) {
            blockSize[i] = blockEnd[i] - blockStart[i] + 1;
        }

        //Pairsum : blockSize[i] = blockSize[i] + blockSize[i+1]
        int N = blockSize.size()-1; //this many pairs will be there in pairSum
        //{2, 3, 4, 5, 2}
        vector<int> pairSum(N);
        for(int i = 0; i < N; i++) {
            pairSum[i] = blockSize[i] + blockSize[i+1];
        }

        int *st = constructST(pairSum.data(), N);

        vector<int> result;
        for(auto &q : queries) { //O(q*log)
            int l = q[0];
            int r = q[1];

            //first block in this range
            int low  = lower_bound(begin(blockEnd), end(blockEnd), l) - begin(blockEnd); //log
            int high = upper_bound(begin(blockStart), end(blockStart), r) - begin(blockStart) - 1; //log

            int maxPairSum = 0;
            if(low < high) { //we need atleast two blocks
                int firstLen = blockEnd[low] - max(blockStart[low], l) + 1; 
                int lastLen  = min(blockEnd[high], r) - blockStart[high] + 1;

                if(high - low == 1) { //exactly two blocks are there only
                    maxPairSum = firstLen + lastLen;
                } else {
                    int pair1 = firstLen + blockSize[low+1];
                    int pair2 = blockSize[high-1] + lastLen;
                    int RMQMaxPairSum = RMQ(st, N, low+1, high-2); //log
                    maxPairSum = max({pair1, pair2, RMQMaxPairSum});
                }
            }
            result.push_back(maxPairSum + activeCount);
        }

        return result;
    }
};