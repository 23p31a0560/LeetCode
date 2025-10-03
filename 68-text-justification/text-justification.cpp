class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;
        while (i < n) {
            int lineLen = words[i].length();
            int j = i + 1;
            // Greedily select words for current line
            while (j < n && lineLen + 1 + words[j].length() <= maxWidth) {
                lineLen += 1 + words[j].length();
                j++;
            }
            int numWords = j - i;
            string line;
            
            // Last line or single-word line: left-justify
            if (j == n || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int wordsLen = 0;
                for (int k = i; k < j; k++) wordsLen += words[k].length();
                int totalSpaces = maxWidth - wordsLen;
                int gaps = numWords - 1;
                int minSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spacesToAdd = minSpaces + (k - i < extraSpaces ? 1 : 0);
                        line += string(spacesToAdd, ' ');
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};