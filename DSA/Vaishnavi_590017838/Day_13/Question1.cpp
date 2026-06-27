class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedWords;
        for(string word : banned) {
            bannedWords.insert(word);
        }
        unordered_map<string, int> wordCount;
        string currentWord = "";
        string answer = "";
        int maxCount = 0;
        paragraph += ' ';
        for(char ch : paragraph) {
            if(isalpha(ch)) {
                currentWord += tolower(ch);
            }
            else {
                if(currentWord != "") {
                    if(bannedWords.find(currentWord) == bannedWords.end()) {
                        wordCount[currentWord]++;
                        if(wordCount[currentWord] > maxCount) {
                            maxCount = wordCount[currentWord];
                            answer = currentWord;
                        }
                    }
                    currentWord = "";
                }
            }
        }
        return answer;
    }
};
