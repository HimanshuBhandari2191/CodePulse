#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef",
    "union","unsigned","void","volatile","while", NULL
};

int isKeyword(char *word) {
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(keywords[i], word) == 0) return 1;
    }
    return 0;
}

int isOperator(char c) {
    return strchr("+-*/%=<>!&|^", c) != NULL;
}

int isSeparator(char c) {
    return strchr("(){}[]:;\"'.,|", c) != NULL;
}

void printToken(const char *type, const char *token) {
    FILE *fp = fopen("tokens.txt", "a");
    if (fp) {
        fprintf(fp, "%s %s\n", type, token);
        fclose(fp);
    }
}

void tokenize(const char *code) {
    int i = 0;
    char token[256];
    FILE *clear = fopen("tokens.txt", "w");
    if (clear) fclose(clear);

    while (code[i] != '\0') {
        if (isspace(code[i])) {
            i++;
            continue;
        }

        // [Rest of your lexical analyzer code...]
        // Keep all your existing tokenization logic here
        // Make sure every printToken() call writes to tokens.txt
    }
}

int main() {
    FILE *fp = fopen("input.c", "r");
    if (!fp) {
        perror("Cannot open input file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *code = malloc(size + 1);
    fread(code, 1, size, fp);
    code[size] = '\0';
    fclose(fp);

    tokenize(code);
    free(code);
    return 0;
}
