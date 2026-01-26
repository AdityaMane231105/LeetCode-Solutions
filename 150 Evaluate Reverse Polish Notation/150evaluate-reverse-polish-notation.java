import java.util.Stack;

class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for (String s : tokens) {
            if (s.equals("+")) {
                stack.push(stack.pop() + stack.pop());
            } else if (s.equals("-")) {
                // Important: Second pop is the left operand (a - b)
                int b = stack.pop();
                int a = stack.pop();
                stack.push(a - b);
            } else if (s.equals("*")) {
                stack.push(stack.pop() * stack.pop());
            } else if (s.equals("/")) {
                // Important: Second pop is the left operand (a / b)
                int b = stack.pop();
                int a = stack.pop();
                stack.push(a / b);
            } else {
                // If it's a number, push it onto the stack
                stack.push(Integer.parseInt(s));
            }
        }

        return stack.pop();
    }
}
