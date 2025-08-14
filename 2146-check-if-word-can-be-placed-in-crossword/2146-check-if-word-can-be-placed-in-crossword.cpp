class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Check all rows (horizontal)
        for(int r = 0; r < m; r++){
            if(checkLine(board[r], word)) return true;
        }

        // Check all columns (vertical)
        for(int c = 0; c < n; c++){
            vector<char> col(m);
            for(int r = 0; r < m; r++) col[r] = board[r][c];
            if(checkLine(col, word)) return true;
        }

        return false;
    }

private:
    // Check a single line (row or column)
    bool checkLine(vector<char>& line, string& word){
        int n = line.size();
        int start = 0;

        while(start < n){
            // Skip blocked cells
            while(start < n && line[start] == '#') start++;
            if(start >= n) break;

            int end = start;
            while(end < n && line[end] != '#') end++;

            int len = end - start;

            // Check only segments matching word length
            if(len == word.size()){
                if(isMatch(line, start, word) || isReverseMatch(line, start, word))
                    return true;
            }

            start = end + 1; // Move to next segment
        }

        return false;
    }

    // Forward match
    bool isMatch(vector<char>& line, int start, string& word){
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(line[start+i] != ' ' && line[start+i] != word[i])
                return false;
        }
        // Check boundaries
        if((start > 0 && line[start-1] != '#') || (start+n < line.size() && line[start+n] != '#'))
            return false;
        return true;
    }

    // Backward match
    bool isReverseMatch(vector<char>& line, int start, string& word){
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(line[start+i] != ' ' && line[start+i] != word[n-1-i])
                return false;
        }
        // Check boundaries
        if((start > 0 && line[start-1] != '#') || (start+n < line.size() && line[start+n] != '#'))
            return false;
        return true;
    }
};
