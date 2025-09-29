#include<string.h>
#include<stdio.h>
int temp,top=-1,pos=0;
char s[32],infix[32],postfix[32];
void push(char symb)
{
    if(top==31){
        printf("\n Stack overflow");
        return;
    }
    top+=1;
    s[top]=symb;
}
char pop()
{
    if(top == -1){
            printf("\n Stack Underflow");
            }
    char ch;
    ch=s[top];
    top--;
    return ch;
}
int prec(char sym)
{
    int p;
    switch(sym)
    {
        case '^':p=3; break;
        case '*':
        case '/':
        case '%':p=2; break;
        case '+':
        case '-':p=1; break;
        default:p=-1; break;
    }
    return p;
}
void infixtopostfix(char* exp)
{
    int length;
    length=strlen(exp);
    push('(');
    exp[length]=')';
    length+=1;
    for(int i=0;i<length;i++)
    {
        switch(exp[i])
        {
            case '(':push(exp[i]); break;
            case ')':temp=pop(); while(temp!='('){
                                       postfix[pos++]=temp;
                                       temp=pop();
                                       } break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':while(prec(s[top])>=prec(exp[i])){
                        temp=pop();
                        postfix[pos++]=temp;
                    } push(exp[i]); break;
            default:postfix[pos++]=exp[i]; break;
        }
    }
    printf("\n The postfix exp is %s",postfix);
}
int main()
{
    printf("\n Enter infix expression:");
    scanf("%s",infix);
    infixtopostfix(infix);
    return 0;
}

