class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> w(n + m, 0);
        vector<int> a;

        int k = 0;

        for (int i = n - 1; i >= 0; i--) {

            int carry = 0;
            a.clear();

            for (int j = m - 1; j >= 0; j--) {

                int num = (num1[i] - '0') * (num2[j] - '0');
                num += carry;

                carry = num / 10;
                a.push_back(num % 10);
            }

            if (carry)
                a.push_back(carry);

                 reverse(a.begin(), a.end());

            for (int h = 0; h < k; h++)
                a.push_back(0);

           

           int start = w.size() - a.size();

        for (int j = 0; j < a.size(); j++)
              w[start + j] += a[j];

            k++;
        }

        // propagate carry
        for (int i = w.size() - 1; i > 0; i--) {
            w[i - 1] += w[i] / 10;
            w[i] %= 10;
        }

        // remove leading zeros
        string s;
        int i = 0;
        while (i < w.size() - 1 && w[i] == 0)
            i++;

        while (i < w.size())
            s += char(w[i++] + '0');

        return s;
    }
};