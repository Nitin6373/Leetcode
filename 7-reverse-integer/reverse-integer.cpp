class Solution {
public:
    int reverse(int x) {
        long long Rev = 0;

        while(x != 0){
            int Digit = x % 10;
            x /= 10;
            Rev = Rev * 10 + Digit;
            cout<<Rev<<endl;
            if(Rev > INT_MAX || Rev < INT_MIN)
                return 0;
        }

        return (int)Rev;
    }
};