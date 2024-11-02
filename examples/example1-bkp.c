#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Tipo de função para processar os argumentos
typedef void (*PrintFunc)(va_list);

// Estrutura para armazenar o especificador e a função
typedef struct {
    char specifier;
    PrintFunc func;
} Specifier;

// Funções de processamento
void print_int(va_list args) {
    printf("%d", va_arg(args, int));
}

void print_string(va_list args) {
    printf("%s", va_arg(args, char*));
}

// Array de especificadores
Specifier specifiers[] = {
    {'d', print_int},
    {'s', print_string},
    {'\0', NULL} // Delimitador para o fim
};

// Função que encontra a função correspondente a um especificador
PrintFunc find_function(char specifier) {
    int i = 0;
    while (specifiers[i].specifier != '\0') {
        if (specifiers[i].specifier == specifier) {
            return specifiers[i].func;
        }
        i++;
    }
    return NULL; // Retorna NULL se não encontrar
}

// Função que simula printf
void my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            PrintFunc func = find_function(format[i]);
            if (func) {
                func(args);
            } else {
                putchar('%'); // Imprime '%' se não encontrar o especificador
                putchar(format[i]); // Imprime o caractere seguinte
            }
        } else {
            putchar(format[i]);
        }
        i++;
    }

    va_end(args);
}

int main() {
    my_printf("Hello %s, you have %d new messages.\n", "Alice", 5);
    return 0;
}
