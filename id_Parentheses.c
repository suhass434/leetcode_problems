bool isValid(char* s) 
{
    int top=-1;
    char stack[10000];
    
    for(int i=0;s[i] != '\0';++i)
    {
    char c = s[i];
    if(c == '(' || c == '{' || c == '[')
    {
        stack[++top] = c;
    }
    else if (c == ')' || c == '}' || c == ']')
    {
        if (top == -1) {
                return false;
            }
        char opening = stack[top--];
        if (opening != '(' && c == ')') {
                return false;
            } else if (opening != '{' && c == '}') {
                return false;
            } else if (opening != '[' && c == ']') {
                return false;
            }
        }
    }
    return top == -1;
}
