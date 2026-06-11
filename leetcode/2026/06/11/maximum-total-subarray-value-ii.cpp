/*
 * Problem: Maximum Total Subarray Value II
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/maximum-total-subarray-value-ii/
 * Language: cpp
 * Topics: Array, Greedy, Segment Tree, Heap (Priority Queue)
 * 
 * ── Problem ────────────────────────────────────────────
 * You are given an integer array nums of length n and an integer k .
 * You must select exactly k distinct subarrays nums[l..r] of nums . Subarrays may overlap, but the exact same subarray (same l and r ) cannot be chosen more than once.
 * The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]) .
 * The total value is the sum of the values of all chosen subarrays.
 * Return the maximum possible total value you can achieve.
 * Example 1:
 * Input: nums = [1,3,2], k = 2
 * Output: 4
 * Explanation:
 * One optimal approach is:
 * • Choose nums[0..1] = [1, 3] . The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2 .
 * • Choose nums[0..2] = [1, 3, 2] . The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2 .
 * Adding these gives 2 + 2 = 4 .
 * Example 2:
 * Input: nums = [4,2,5,1], k = 3
 * Output: 12
 * Explanation:
 * One optimal approach is:
 * • Choose nums[0..3] = [4, 2, 5, 1] . The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4 .
 * • Choose nums[1..3] = [2, 5, 1] . The maximum is 5 and the minimum is 1, so the value is also 4 .
 * • Choose nums[2..3] = [5, 1] . The maximum is 5 and the minimum is 1, so the value is again 4 .
 * Adding these gives 4 + 4 + 4 = 12 .
 * Constraints:
 * • 1 <= n == nums.length <= 5 * 10 ​​​​​​​4
 * • 0 <= nums[i] <= 10 9
 * • 1 <= k <= min(10 5 , n * (n + 1) / 2)
 * 
 * ── Hints ─────────────────────────────────────────────
 * Hint 1: For fixed l , the sequence v(l,r)=max(nums[l..r])−min(nums[l..r]) is non-increasing as r moves left.
 * Hint 2: Build RMQs (sparse tables) for range max/min so each v(l,r) is queryable in O(1) .
 * Hint 3: Use a max-heap with v(l,n-1) for all l ; pop the largest k times, and after popping an entry from (l,r) push (l,r-1) if r>l .
 * 
 */

class SegmentTree {
public:
    vector<int> segmentTree;
    bool isMinTree;

    SegmentTree(vector<int>& nums, bool flag) {
        int n = nums.size();
        this->isMinTree = flag;

        segmentTree.resize(4 * n);

        buildSegmentTree(0, 0, n - 1, nums);
    }

    void buildSegmentTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segmentTree[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;

        buildSegmentTree(2 * i + 1, l, mid, nums);
        buildSegmentTree(2 * i + 2, mid + 1, r, nums);

        if (isMinTree) {
            segmentTree[i] = min(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        } else {
            segmentTree[i] = max(segmentTree[2 * i + 1], segmentTree[2 * i + 2]);
        }
    }

    int querySegmentTree(int start, int end, int i, int l, int r) {
        //No overlap
        if (l > end || r < start) {
            return isMinTree ? INT_MAX : INT_MIN;
        }

        //Complete Overlap
        if (l >= start && r <= end) {
            return segmentTree[i];
        }

        int mid = l + (r - l) / 2;

        int a = querySegmentTree(start, end, 2 * i + 1, l, mid);
        int b = querySegmentTree(start, end, 2 * i + 2, mid + 1, r);

        if (isMinTree) {
            return min(a, b);
        }

        return max(a, b);
    }

    int query(int l, int r, int n) {
        return querySegmentTree(l, r, 0, 0, n - 1);
    }
};

class Solution {
public:
    typedef long long ll;

    ll getValue(int l, int r, SegmentTree& minST, SegmentTree& maxST, int n) {
        int minEl = minST.query(l, r, n);
        int maxEl = maxST.query(l, r, n);

        return (ll)maxEl - minEl;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        SegmentTree minST(nums, true);   //true is for minimum
        SegmentTree maxST(nums, false);  //false is for maximum

        //{val, l, r} max. heap
        priority_queue<tuple<ll, int, int>> pq;

        //Step-1 (Initialize the heap with best value)
        //O(n*logn)
        for (int l = 0; l < n; l++) {  //l to n-1
            ll value = getValue(l, n - 1, minST, maxST, n);  //log(n)
            pq.push({value, l, n - 1});
        }

        //Step-2 Find top k
        ll result = 0;
        //O(k * log(n))
        while (k--) {
            auto [value, l, r] = pq.top();
            pq.pop();

            result += value;

            ll nextBestValue = getValue(l, r - 1, minST, maxST, n);  //log(n)

            pq.push({nextBestValue, l, r - 1});  //log(n)
        }

        return result;
    }
};
