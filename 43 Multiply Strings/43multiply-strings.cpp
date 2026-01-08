class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> res(n1 + n2, 0);
        
        // Multiply each digit and add to the result array
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];
                
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        
        // Convert the vector to a string, skipping leading zeros
        string result = "";
        for (int i = 0; i < res.size(); i++) {
            if (!(result.empty() && res[i] == 0)) {
                result += to_string(res[i]);
            }
        }
        
        return result.empty() ? "0" : result;
    }
};
