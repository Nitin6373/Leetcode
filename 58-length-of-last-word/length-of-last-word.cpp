class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int Start = -1;
        int End = -1;
        bool Word = false;

        for(int i=n-1;i>=0;i--){
            if(Word == false && s[i] != ' ')
            {
                Word = true;
                End = i;
                continue;
            }

            if(Word == true && s[i] == ' '){
                Start = i;
                break;
            }
        }

        return End - Start;
    }
};