class Solution {
public:
    string convertToTitle(int n) {
        string result;  // This string will store the Excel column title
        while (n > 0) {
            n--;  // Decrement n by 1 to map it to 0-based index
            int rem = n % 26;  // Calculate the remainder when dividing n by 26
            char ch = rem + 'A';  // Convert the remainder to a character using ASCII offset ('A' is 65)
            result.push_back(ch);  // Add the character to the result string
            n /= 26;  // Divide n by 26 to move to the next position in the title
        }
        reverse(begin(result), end(result));  // Reverse the result string to get the correct order
        return result;  // Return the final Excel column title
    }
};
