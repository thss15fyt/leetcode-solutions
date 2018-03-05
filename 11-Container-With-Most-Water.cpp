class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while(left < right) {
            int h_l = height[left], h_r = height[right];
            int area = (right - left) * min(h_l, h_r);
            max_area = (area > max_area) ? area : max_area;
            if(h_l <= h_r) {
                do {
                    left++;
                } while(height[left] <= h_l);
            }
            else {
                do {
                    right--;
                } while(height[right] <= h_r);
            }
        }
        return max_area;
    }
};