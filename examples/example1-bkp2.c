#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Tipo de função para processar os argumentos
typedef int (*PrintFunc)(va_list); // Agora retorna o número de caracteres impressos

// Estrutura para armazenar o especificador e a função
typedef struct {
    char specifier;
    PrintFunc func;
} Specifier;

// Funções de processamento que retornam o número de caracteres impressos
int print_int(va_list args) {
    return printf("%d", va_arg(args, int));
}

int print_string(va_list args) {
    return printf("%s", va_arg(args, char*));
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

// Função que simula printf e retorna o número de caracteres impressos
int my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // Contador de caracteres impressos
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            PrintFunc func = find_function(format[i]);
            if (func) {
                count += func(args); // Chama a função que imprime e conta caracteres
            } else {
                putchar('%'); // Imprime '%' se não encontrar o especificador
                putchar(format[i]); // Imprime o caractere seguinte
                count += 2; // Conta os dois caracteres impressos
            }
        } else {
            putchar(format[i]);
            count++; // Conta o caractere impresso
        }
        i++;
    }

    va_end(args);
    return count; // Retorna o total de caracteres impressos
}

int main() {
    int printed_chars = my_printf("Hello %s, you have %d new messages.\n", "Alice", 5);
    printf("Total printed characters: %d\n", printed_chars);
    return 0;
}
