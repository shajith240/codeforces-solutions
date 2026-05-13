/*
 * Problem: Time Based Key-Value Store
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/time-based-key-value-store/
 * Language: cpp
 * Topics: Hash Table, String, Binary Search, Design
 * 
 * ── Problem ────────────────────────────────────────────
 * Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key&#39;s value at a certain timestamp.
 * Implement the TimeMap class:
 * • TimeMap() Initializes the object of the data structure.
 * • void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp .
 * • String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp . If there are multiple such values, it returns the value associated with the largest timestamp_prev . If there are no values, it returns &quot;&quot; .
 * Example 1:
 * Input
 * [&quot;TimeMap&quot;, &quot;set&quot;, &quot;get&quot;, &quot;get&quot;, &quot;set&quot;, &quot;get&quot;, &quot;get&quot;]
 * [[], [&quot;foo&quot;, &quot;bar&quot;, 1], [&quot;foo&quot;, 1], [&quot;foo&quot;, 3], [&quot;foo&quot;, &quot;bar2&quot;, 4], [&quot;foo&quot;, 4], [&quot;foo&quot;, 5]]
 * Output
 * [null, null, &quot;bar&quot;, &quot;bar&quot;, null, &quot;bar2&quot;, &quot;bar2&quot;]
 * Explanation
 * TimeMap timeMap = new TimeMap();
 * timeMap.set(&quot;foo&quot;, &quot;bar&quot;, 1); // store the key &quot;foo&quot; and value &quot;bar&quot; along with timestamp = 1.
 * timeMap.get(&quot;foo&quot;, 1); // return &quot;bar&quot;
 * timeMap.get(&quot;foo&quot;, 3); // return &quot;bar&quot;, since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is &quot;bar&quot;.
 * timeMap.set(&quot;foo&quot;, &quot;bar2&quot;, 4); // store the key &quot;foo&quot; and value &quot;bar2&quot; along with timestamp = 4.
 * timeMap.get(&quot;foo&quot;, 4); // return &quot;bar2&quot;
 * timeMap.get(&quot;foo&quot;, 5); // return &quot;bar2&quot;
 * Constraints:
 * • 1 <= key.length, value.length <= 100
 * • key and value consist of lowercase English letters and digits.
 * • 1 <= timestamp <= 10 7
 * • All the timestamps timestamp of set are strictly increasing.
 * • At most 2 * 10 5 calls will be made to set and get .
 * 
 */

class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) == mp.end()){
            return "";
        }
        
        vector<pair<int,string>>& vec = mp[key];

        int left = 0;
        int right = vec.size() - 1;

        string ans = "";
        
        while(left <= right){

            int mid = left + (right - left) / 2;
            if(vec[mid].first <= timestamp){
                ans = vec[mid].second;

                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */