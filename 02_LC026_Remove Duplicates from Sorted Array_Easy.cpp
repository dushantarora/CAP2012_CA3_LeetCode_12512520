#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int write_idx = 1;
        for (int read_idx = 1; read_idx < nums.size(); ++read_idx) {
            if (nums[read_idx] != nums[read_idx - 1]) {
                nums[write_idx] = nums[read_idx];
                write_idx++;
            }
        }
        return write_idx;
    }
};
