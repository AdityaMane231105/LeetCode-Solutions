class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        lookup = {key: value for key, value in knowledge}
        res = []
        current_key = []
        in_bracket = False
        
        for char in s:
            if char == '(':
                in_bracket = True
            elif char == ')':
                in_bracket = False
                key_str = "".join(current_key)
                res.append(lookup.get(key_str, '?'))
                current_key = []
            elif in_bracket:
                current_key.append(char)
            else:
                res.append(char)
                
        return "".join(res)
