//Neil John
//S7 CS2 37
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char expr[25];
int ptr,len;

void E()
{
    printf("\nE->TE'");
    T();
    E_();
}
void E_()
{
    
    if(expr[ptr]=='+' && ptr<len)
    {
        printf("\nE'->+TE'");
        ptr++;
        T();
        E_();
    }
    else{
        printf("\nE'->e");
        return;
    }
}
void T()
{
    printf("\nT->FT'");
    F();
    T_();
}
void T_()
{
    
    if(expr[ptr]=='*' && ptr<len)
    {
        printf("\nT'->*FT'");
        ptr++;
        F();
        T_();
    }
    else{
        printf("\nT'->e");
    }
}
void F()
{
    
   if(expr[ptr]>='0' && expr[ptr]<='9' &&ptr<len)
    {
        printf("\nF->i");
        ptr++;
    }
}
void main()
{
    printf("\nGrammar Parser");
    printf("\n\t E->TE' \n\t E'->+TE'|e \n\t T->FT' ");
    printf("\n\t T'->*FT'|e \n\t F->i");
    printf("\n Enter the input :");
    scanf("%s",expr);
    len=strlen(expr);
    E();
    if(ptr==len && expr[ptr]=='\0')
    {
        printf("\nString accepted");
    }
    else
    {
         printf("\n String not accepted");
    }
    
}
/*______________________OUTPUT________________________
Grammar Parser
         E->TE' 
         E'->+TE'|e 
         T->FT' 
         T'->*FT'|e 
         F->i
 Enter the input :2+7

E->TE'
T->FT'
F->i
T'->e
E'->+TE'
T->FT'
F->i
T'->e
E'->e
String accepted
*/