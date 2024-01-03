#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 1000
#define HUN 100
#define WARNING "WARNING!"
enum boolean {close, open};
enum answer {no, yes};
bool is_a_V_initialization(char *tmp);
bool is_a_V_declaration(char *tmp);
bool is_a_Prototype(char *tmp);
bool is_a_Definition(char *tmp);
bool is_a_Function(char *tmp);
bool is_a_Library(char *tmp);
int main(void){
    char line[500];
    char letters[HUN];
    char words[HUN][MAX];
    char *tmp = NULL;
    int c, i = 0;
    bool is_a_initialization = false;
    bool is_a_comparation = false;
    bool is_a_blank_line = false;
    bool is_a_declaration = false;
    bool is_a_definition = false;
    bool is_a_prototype = false;
    bool is_a_function = false;
    bool is_a_method = false;
    bool is_a_library = false;
    bool semicolon = false;
    bool parentheses_status = close;
    bool dq_status = close;
    int lcounter = 0, wcounter = 0;
    int column = 0;
    int row = 1;
    FILE *input = fopen("protoype.c", "r");
    if (input == NULL)
    {
        printf("INVALID FILE ADRESS\n");
    }
    while ((c = getc(input)) != EOF)
    {
        column++;
        if (c == '(' || c == ')'){
            parentheses_status = (parentheses_status == close) ? open : close;
            if (parentheses_status == close && dq_status == open){
                printf("\033[1;31m");
                printf("%s\n", WARNING);
                printf("\033[1;32m");
                printf("CLOSE DOUBLE QUOTES! COLUMN: %i ROW: %i\n", column, row);
                printf("\033[0m");
                dq_status = close;
            }
        }
        else if (c == '"'){
            dq_status = (dq_status == close && (parentheses_status == open || is_a_initialization == true)) ? open : close;
        }
        else if (c == ';'){
            semicolon = true; 
        }
        if (c != ' ' && c != '\n' && c != '\t' && c != '(' && c != ')')
        {
            letters[lcounter] = c;
            lcounter++;
        }
        else{
            int j;
            for (j = 0; j < lcounter; j++)
            {
                words[wcounter][j] = letters[j];
                letters[j] = 0;
            }
            words[wcounter][j] = '\0';
            tmp = words[wcounter];
            if (row == 3){
                printf("%s\n", tmp);
            }
            is_a_initialization = (is_a_initialization == false) ? is_a_V_initialization(tmp) : true;
            is_a_declaration = (is_a_declaration == false) ? is_a_V_declaration(tmp) : true;
            is_a_function = (is_a_function == false) ? is_a_Function(tmp) : true;
            is_a_prototype = (is_a_prototype == false && (is_a_declaration == true || strcmp(words[0], "void") == 0) && (strcmp(words[2], "void") == 0 || is_a_V_declaration(tmp))) ? true : is_a_prototype;
            is_a_library = (wcounter == 0 && is_a_Library(tmp)) ? true : is_a_library;
            is_a_definition = (wcounter == 0 && is_a_Definition(tmp)) ? true : is_a_definition;
            is_a_blank_line = (wcounter == 0) ? true : false;
            lcounter = 0;
            wcounter++;
            if (c == '\n')
            {
                for (int k = 0; k < wcounter; k++){
                    words[k][0] = '\0';
                    if (row ==1){
                        printf("%s\n", words[k]);
                    }
                }
                if (semicolon == false && is_a_prototype == false && is_a_comparation == false &&
                is_a_library == false && is_a_definition == false && is_a_blank_line == false){
                    printf("\033[1;31m");
                    printf("%s\n", WARNING);
                    printf("\033[1;33m");
                    printf("REQUIRED SEMICOLON ';' AT THE END OF THE EXPRESION ROW: %i\n\n", row);
                    printf("\033[0m");
                }
                if (is_a_function == true){
                    printf("This is a function call like printf\n");
                }
                if (parentheses_status == open){
                    printf("\033[1;31m");
                    printf("%s\n", WARNING);
                    printf("\033[1;32m");
                    printf("CLOSE PARENTHESES!\n\n");
                    printf("\033[0m");
                }
                if (dq_status == open){
                    printf("CLOSE DOUBLE QUOTES\n");
                }
                is_a_initialization = false;
                is_a_comparation = false; 
                is_a_declaration = false;
                is_a_definition = false;
                is_a_prototype = false;
                is_a_function = false;
                is_a_method = false;
                is_a_library = false;
                is_a_blank_line = false;
                semicolon = false;
                parentheses_status = close;
                dq_status = close;
                wcounter = 0;
                column = 0;
                row++;
            }
        }
    }
    printf("SUCCESS!\n");
    fclose(input);
    return 0;
}

bool is_a_V_initialization(char *tmp){
    if (strcmp(tmp, "=") == 0) 
    {
        return true;
    }
    return false;
}

bool is_a_V_declaration(char *tmp)
{
    if (strcmp(tmp, "char") == 0 || strcmp(tmp, "int") == 0 || strcmp(tmp, "short") == 0 || 
    strcmp(tmp, "long") == 0 || strcmp(tmp, "float") == 0 || strcmp(tmp, "double") == 0)
    {
        return true;
    }
    return false;
}

bool is_a_Function(char *tmp)
{
    if (strcmp(tmp, "printf") == 0 || strcmp(tmp, "getc") == 0 || strcmp(tmp, "putc") == 0)
    {
        return true;
    }
    return false;
}

bool is_a_Prototype(char *tmp){
    if (strcmp(tmp, "main") == 0){

    }
}

bool is_a_Library(char *tmp){
    if (strcmp(tmp, "#include") == 0){
        return true;
    }
    return false;
}

bool is_a_Definition(char *tmp){
    if (strcmp(tmp, "#define") == 0){
        return true;
    }
    return false;
}
