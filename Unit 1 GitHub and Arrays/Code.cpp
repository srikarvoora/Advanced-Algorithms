#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int main() {
    int n, target;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::cout << "Enter the target value: ";
    std::cin >> target;

    std::vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        std::cout << "Output: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No two numbers add up to the target.\n";
    }

    return 0;
}
