class Solution {
public:
    long MOD=1e9+7;
       long long PowerCalc(long long base, long long power) {
        long long result = 1;
        base %= MOD;
        while (power > 0) {
            if (power % 2 == 1)
                result = (result * base) % MOD;

            base = (base * base) % MOD;
            power /= 2;
        }

        return result;
    }
    int countGoodNumbers(long long n) {
         long long even = (n + 1) / 2;
        long long odd = n/ 2;

        long long evenWays = PowerCalc(5, even);
        long long oddWays = PowerCalc(4, odd);

        return (evenWays * oddWays) % MOD;
    }
};