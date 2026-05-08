/*
 * Problem: Group Anagrams
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/group-anagrams/
 * Language: cpp
 * Topics: Array, Hash Table, String, Sorting
 * 
 * ── Problem ────────────────────────────────────────────
 * Given an array of strings strs , group the anagrams together. You can return the answer in any order .
 * Example 1:
 * Input: strs = [&quot;eat&quot;,&quot;tea&quot;,&quot;tan&quot;,&quot;ate&quot;,&quot;nat&quot;,&quot;bat&quot;]
 * Output: [[&quot;bat&quot;],[&quot;nat&quot;,&quot;tan&quot;],[&quot;ate&quot;,&quot;eat&quot;,&quot;tea&quot;]]
 * Explanation:
 * • There is no string in strs that can be rearranged to form &quot;bat&quot; .
 * • The strings &quot;nat&quot; and &quot;tan&quot; are anagrams as they can be rearranged to form each other.
 * • The strings &quot;ate&quot; , &quot;eat&quot; , and &quot;tea&quot; are anagrams as they can be rearranged to form each other.
 * Example 2:
 * Input: strs = [&quot;&quot;]
 * Output: [[&quot;&quot;]]
 * Example 3:
 * Input: strs = [&quot;a&quot;]
 * Output: [[&quot;a&quot;]]
 * Constraints:
 * • 1 <= strs.length <= 10 4
 * • 0 <= strs[i].length <= 100
 * • strs[i] consists of lowercase English letters.
 * 
 */

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string,vector<string>> mp;

         for(int i = 0 ; i < strs.size(); i++){
            string temp = strs[i];

            sort(temp.begin(),temp.end());

            mp[temp].push_back(strs[i]);
         }
         
         vector<vector<string>> ans;
         for(auto it : mp){
            ans.push_back(it.second);
         }

         return ans;   
    }
};