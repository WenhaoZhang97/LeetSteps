/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums,const int target) {
        sort(nums.begin(),nums.end());
        vector<int>sums;
        auto first=nums.begin(),sec=nums.begin()+1,third=nums.end()-1;
        int temp,closest=*first+*sec+*third;
        for(;first<nums.end()-2;first++) {
            sec=first+1,third=nums.end()-1;
            while(sec!=third) {
                temp=*first+*sec+*third;
                if(temp==target) 
                    return temp;
                if(abs(temp-target)<abs(closest-target))
                    closest=temp;
                //判断结束，开始进行移动
                if(temp<target)
                    sec++;
                else
                    third--;
            }
        }
        return closest;
    }
};