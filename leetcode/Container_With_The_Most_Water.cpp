/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

/*
Warning:
It's not finished!
2017-10-21
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int volume=0;
        for(int i=0;i!=height.size()-1;i++){
            for(int j=i+1;j!=height.size();j++){
                
                int temp=(height[i]<=height[j]?height[i]:height[j])*(j-i);
                if(temp>volume)
                    volume=temp;
            }
            //not efficient
            
            
        }
        return volume;
    }
};