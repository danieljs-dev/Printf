#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h> // Para write

// Tipo de função para processar os argumentos
typedef int (*PrintFunc)(va_list); // Define um tipo para funções de impressão

// Função que imprime um caractere em um descriptor de arquivo
void ft_putchar_fd(char c, int fd) {
    write(fd, &c, 1);
}

// Função que imprime uma string em um descriptor de arquivo
void ft_putstr_fd(char *s, int fd) {
    if (!s || fd < 1)
        return;
    while (*s) {
        ft_putchar_fd(*s, fd);
        s++;
    }
}

// Função que converte um número inteiro em uma string
static int ft_int_to_ascii(int n) {
    if (n < 0)
        n = -n;
    return (n + '0');
}

static int ft_numlen_dec(int n) {
    int len = 0;
    if (n == 0)
        return (1);
    while (n != 0) {
        n = n / 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n) {
    int sign = 0;
    int digits_len = ft_numlen_dec(n);
    char *num;
    
    if (n < 0) sign = 1;
    num = (char *)malloc((digits_len + sign + 1) * sizeof(char));
    if (!num)
        return (NULL);
    num[digits_len + sign] = '\0';
    if (sign)
        num[0] = '-';
    while (digits_len > 0) {
        num[digits_len + sign - 1] = ft_int_to_ascii(n % 10);
        n = n / 10;
        digits_len--;
    }
    return (num);
}

// Estrutura para armazenar o especificador e a função de impressão
typedef struct {
    char specifier;
    PrintFunc func; // Usa o tipo PrintFunc
} Specifier;

// Função que imprime um número inteiro
int print_int(va_list args) {
    int value = va_arg(args, int);
    char *str = ft_itoa(value); // Converte o inteiro para string
    if (str) {
        ft_putstr_fd(str, 1); // Imprime a string
        int len = strlen(str); // Conta o número de caracteres
        free(str); // Libera a memória
        return len; // Retorna o comprimento da string
    }
    return 0; // Se a conversão falhar, retorna 0
}

// Função que imprime uma string
int print_string(va_list args) {
    char *str = va_arg(args, char*);
    if (str) {
        ft_putstr_fd(str, 1); // Imprime a string
        return strlen(str); // Retorna o comprimento da string
    }
    return 0; // Se a string for nula, retorna 0
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
                count += func(args); // Chama a função diretamente
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
