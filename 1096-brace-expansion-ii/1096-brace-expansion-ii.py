class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        stack = []
        current_union = []
        current_concat = {""}
        
        for char in expression:
            if char.isalpha():
                current_concat = {word + char for word in current_concat}
            elif char == '{':
                stack.append((current_union, current_concat))
                current_union = []
                current_concat = {""}
            elif char == ',':
                current_union.append(current_concat)
                current_concat = {""}
            elif char == '}':
                current_union.append(current_concat)
                resolved_brace_set = set.union(*current_union)
                
                prev_union, prev_concat = stack.pop()
                current_concat = {p + r for p in prev_concat for r in resolved_brace_set}
                current_union = prev_union
                
        final_set = set.union(current_concat, *current_union)
        return sorted(list(final_set))
