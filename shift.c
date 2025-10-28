#include<stdio.h>
#include<string.h>

char stack[50];
char input[50];
int top=-1,i=0;

void check();
int main(){
    printf("Shift reduce Parser\n");
    printf("Grammar:\n");
    printf("E -> E+E | E*E | E/E | a | b\n");
    printf("Enter the input string: ");
    gets(input);
    strcat(input,"$");
    
    printf("\nStack\tInput\tAction\n");
    printf("-----------------------------\n");
    
    while(1){
        stack[++top]=input[i];
        input[i]=' ';
        i++;
        printf("%s\t%s\tShift\n",stack,input);
        check();
        
        if(top==0 && stack[0]=='E'&&input[i]=='$'){
            printf("%s\t%s\tAccepted\n",stack,input);
            break;
        }

        if(input[i]=='$' && !(top==0 && stack[top]=='E')){
             printf("%s\t%s\tReject\n",stack,input);
            break;

        }
    }
} 
void check(){
    if(top>=0){
        
        if(stack[top]=='a' || stack[top]=='b'){
            printf("%s\t\tReduce:E -> %c\n",stack,stack[top]);
            stack[top]='E';
        }
        
        if(top>=2 && stack[top]=='E' && ( stack[top-1]=='*'|| stack[top-1]=='+'|| stack[top-1]=='/')&&stack[top-2]=='E'){
            printf("%s\t\tReduce:E -> E%cE\n",stack,stack[top-1]);
            stack[top-2]='E';
            top-=2;
        }
    }
}
//output
// Shift reduce Parser
// Grammar:
// E -> E+E | E*E | E/E | a | b
// Enter the input string: a+a*b