//Neil John 37
// First and follow

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 10

int n; 
char productions[MAX][MAX], firstSet[MAX][MAX], followSet[MAX][MAX];
char nonTerminals[MAX], terminals[MAX];

void findFirst(char, int, int);
void findFollow(char);
void addToSet(char[], char);
int isNonTerminal(char);

int main() {
    int i, choice;
    char symbol;
    
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions :\n");
    for (i = 0; i < n; i++) {
        scanf("%s", productions[i]);
        nonTerminals[i] = productions[i][0];
    }

    for (i = 0; i < n; i++) {
        symbol = productions[i][0];
        findFirst(symbol, i, 0);
    }

    for (i = 0; i < n; i++) {
        symbol = productions[i][0];
        if (i == 0) addToSet(followSet[i], '$');  
        findFollow(symbol);
    }

    printf("\nFIRST sets:\n");
    for (i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", nonTerminals[i]);
        for (int j = 0; firstSet[i][j] != '\0'; j++) {
            printf("%c ", firstSet[i][j]);
        }
        printf("}\n");
    }

   
    printf("\nFOLLOW sets:\n");
    for (i = 0; i < n; i++) {
        printf("FOLLOW(%c) = { ", nonTerminals[i]);
        for (int j = 0; followSet[i][j] != '\0'; j++) {
            printf("%c ", followSet[i][j]);
        }
        printf("}\n");
    }

    return 0;
}

void findFirst(char symbol, int productionIndex, int symbolIndex) {
    if (!isNonTerminal(symbol)) {
        addToSet(firstSet[productionIndex], symbol);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (productions[i][0] == symbol) {
            if (productions[i][2] == '#')  
                addToSet(firstSet[productionIndex], '#');
            else if (isNonTerminal(productions[i][2]))
                findFirst(productions[i][2], productionIndex, 2);
            else
                addToSet(firstSet[productionIndex], productions[i][2]);
        }
    }
}

void findFollow(char symbol) {
    if (!isNonTerminal(symbol)) return;

    for (int i = 0; i < n; i++) {
        for (int j = 2; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j+1] != '\0')
                    findFirst(productions[i][j+1], i, j+1);
                if (productions[i][j+1] == '\0' && productions[i][0] != symbol)
                    findFollow(productions[i][0]);
            }
        }
    }
}

void addToSet(char set[], char element) {
    int i;
    for (i = 0; set[i] != '\0'; i++)
        if (set[i] == element) return;
    set[i] = element;
    set[i+1] = '\0';
}

int isNonTerminal(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

/*
Enter the productions
S=AB
A=a|#
B=b|#

FIRST sets:
FIRST(S) = { a b }
FIRST(A) = { a }
FIRST(B) = { b }

FOLLOW sets:
FOLLOW(S) = { $ }
FOLLOW(A) = {b,$ }
FOLLOW(B) = { $}
*/