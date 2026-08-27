import "strings"

func decodeString(s string) string {
    numStack := []int{}
    strStack := []string{}
    currStr := ""
    num := 0
    for _, ch := range s {
        if ch >= '0' && ch <= '9' {
            num = num*10 + int(ch-'0')
        } else if ch == '[' {
            numStack = append(numStack, num)
            strStack = append(strStack, currStr)
            num = 0
            currStr = ""
        } else if ch == ']' {
            repeat := numStack[len(numStack)-1]
            numStack = numStack[:len(numStack)-1]
            prevStr := strStack[len(strStack)-1]
            strStack = strStack[:len(strStack)-1]
            currStr = prevStr + strings.Repeat(currStr, repeat)
        } else {
            currStr += string(ch)
        }
    }
    return currStr
}
