class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
             while(q.size()&&q.front()<=i-k)q.pop_front();//记录的是坐标整个双端队列是单调递减的
             while(q.size()&&nums[q.back()]<nums[i])q.pop_back();
             q.push_back(i);//每次先插进去，不符合条件再弹出来
             if(i>=k-1)res.push_back(nums[q.front()]);
        }
        return res;
    }
};

 
