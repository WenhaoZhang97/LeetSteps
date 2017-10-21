/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        if(nums.size()<3)
            return result;
        for(auto first=nums.begin();first!=nums.end()-2;first++) {
            auto second=first+1,third=nums.end()-1;
            int temp;
            while(second!=third) {
                temp=*first+*second+*third;
                if(temp<0)
                    second++;
                else if(temp>0)
                    third--;
                else {
                    int temp1,temp2;
                    vector<int> vecTemp;
                    vecTemp.push_back(*first);
                    vecTemp.push_back(*second);
                    vecTemp.push_back(*third);
                    temp1=*second,temp2=*third;
                    result.push_back(vecTemp);
                    //process duplicates of second and third index
                    while(second<third&&*second==temp1)
                        second++;
                    while(second<third&&*third==temp2)
                        third--;
                }
            }
            //process duplicates of first index
        while(*first==*(first+1)&&(first+1)!=nums.end()-2)
            first++;
        }
        
        return result;
    }
};