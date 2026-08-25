class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0, read = 0;
        while (read < n) {
            char c = chars[read];
            int count = 0;
            while (read < n && chars[read] == c) {
                read++;
                count++;
            }
            chars[write++] = c;
            if (count > 1) {
                string cnt = to_string(count);
                for (char d : cnt) chars[write++] = d;
            }
        }
        return write;
    }
};
