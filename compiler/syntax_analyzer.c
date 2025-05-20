#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[30];
    char value[100];
} Token;

Token tokens[1000];
int pos = 0, total = 0;

void loadTokens() {
    FILE *fp = fopen("tokens.txt", "r");
    if (!fp) {
        perror("Cannot open tokens file");
        exit(1);
    }
    while (fscanf(fp, "%s %s", tokens[total].type, tokens[total].value) != EOF) {
        total++;
    }
    fclose(fp);
}

void parse() {
    loadTokens();
    FILE *out = fopen("parse_tree.txt", "w");
    if (!out) {
        perror("Cannot create parse tree file");
        exit(1);
    }
    
    // [Your existing parsing logic here]
    // Write output to parse_tree.txt
    
    fclose(out);
}

int main() {
    parse();
    return 0;
}
