// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int x = nums.size();
        for(int i=0;i<x;i++){
            nums.push_back(nums[i]);
        }
        
        int n = nums.size();
        stack<int> st;
        vector<int> v;
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                v.push_back(-1);
            }
            else if(!st.empty() && st.top()>nums[i]){
                v.push_back(st.top());
            }
            else if(!st.empty() && st.top()<=nums[i]){
                while(!st.empty() && st.top()<=nums[i]){
                    st.pop();
                }
                if(st.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top());
                }
            }
            st.push(nums[i]);
        }
        
        reverse(v.begin(), v.end());
        for(int i=x;i<n;i++){
            v.pop_back();
        }
        return v;
    }
};
