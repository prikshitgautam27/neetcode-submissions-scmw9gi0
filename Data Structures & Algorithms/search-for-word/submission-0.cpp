#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // Trigger DFS if the first character matches
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int r, int c, int index) {
        // Base case: full word is matched
        if (index == word.length()) {
            return true;
        }
        
        // Boundary checks and character mismatch validation
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }
        
        // Temporarily mark the current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';
        
        // Explore all 4 cardinal directions (up, down, left, right)
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);
        
        // Backtrack: Restore the cell's original value
        board[r][c] = temp;
        
        return found;
    }
};
