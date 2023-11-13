class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (std::all_of(nums.begin(), nums.end(), [&] (const int i) { return i == 0; } ) && nums.size() > 2) return { {0, 0, 0} };
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        
        std::sort(nums.begin(), nums.end());
      
        for (size_t i = 0; i < nums.size(); i++) {
            if (i && (nums.at(i) == (nums.at(i-1)))) continue;
            if (nums.size() > i + 2) {
                if (nums.at(i) + nums.at(i+1) + nums.at(i+2) > 0) continue;
            } else break; 
            if (nums.size() - 2 > 0) {
                if (nums.at(i) + nums.at(nums.size() - 1) + nums.at(nums.size() - 2) < 0) continue;
            } else break;
            int target = -nums[i]; 
            int l = i + 1, r = nums.size() - 1;
            while (l<r) {
                int summ = nums.at(l) + nums.at(r);
                if (summ == target) {
                    if (res.empty() || res.back().at(0) != nums.at(i) || res.back().at(1) != nums.at(l) || res.back().at(2) != nums.at(r))
                        res.push_back({nums.at(i), nums.at(l), nums.at(r)});
                    l++;
                    r--;
                } else if (summ < target) {
                    l++;
                } else {
                    r--;
                }//if (summ == target)
            }//while (l<r)
        }//for(int i = 0; i < sort_nums.size(); i++)
        return res;
    }// vector<vector<int>> threeSum()
};// Solution
