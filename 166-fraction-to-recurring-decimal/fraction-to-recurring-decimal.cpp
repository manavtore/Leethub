class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string result;
        if ((numerator < 0) ^ (denominator < 0))
            result.push_back('-');

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        long long integerPart = n / d;
        result += to_string(integerPart);

        long long remainder = n % d;
        if (remainder == 0) return result;

        result.push_back('.');

        unordered_map<long long, int> remainderIndex;
        while (remainder) {
            if (remainderIndex.count(remainder)) {
                result.insert(remainderIndex[remainder], "(");
                result.push_back(')');
                break;
            }
            remainderIndex[remainder] = (int)result.size();
            remainder *= 10;
            result.push_back('0' + (remainder / d));
            remainder %= d;
        }

        return result;
    }
};
