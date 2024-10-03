#include <iostream>
#include <vector>

std::string longestCommonSubstring(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i - 1;
                }
            }
        }
    }

    return str1.substr(endIndex - maxLength + 1, maxLength);
}

int main() {
    std::string str1, str2;

    std::cout << "Enter string 1: ";
    std::cin >> str1;

    std::cout << "Enter string 2: ";
    std::cin >> str2;

    std::string longestSubstring = longestCommonSubstring(str1, str2);

    std::cout << "Longest Common Substring: " << longestSubstring << std::endl;

    // Create a lookup table for the strings
    std::vector<std::vector<int>> lookupTable(str1.length() + 1, std::vector<int>(str2.length() + 1, 0));
    for (int i = 1; i <= str1.length(); i++) {
        for (int j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                lookupTable[i][j] = lookupTable[i - 1][j - 1] + 1;
            }
        }
    }

    // Print the lookup table
    for (int i = 0; i <= str1.length(); i++) {
        for (int j = 0; j <= str2.length(); j++) {
            std::cout << lookupTable[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
