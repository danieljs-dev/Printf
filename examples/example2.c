#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Estrutura para armazenar os caracteres e funções
typedef struct Node {
    char specifier; // caractere a ser impresso
    void (*func)(va_list); // ponteiro para a função de processamento
    struct Node* next;
} Node;

// Funções de processamento
void print_int(va_list args) {
    printf("%d", va_arg(args, int));
}

void print_string(va_list args) {
    printf("%s", va_arg(args, char*));
}

// Função para criar um novo nó
Node* create_node(char specifier, void (*func)(va_list)) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->specifier = specifier;
    new_node->func = func;
    new_node->next = NULL;
    return new_node;
}

// Função para adicionar um nó à lista
void add_node(Node** head, char specifier, void (*func)(va_list)) {
    Node* new_node = create_node(specifier, func);
    new_node->next = *head;
    *head = new_node;
}

// Função que simula printf
void my_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    Node* head = NULL;

    // Monta a lista encadeada com os especificadores
    for (const char* p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd':
                    add_node(&head, 'd', print_int);
                    break;
                case 's':
                    add_node(&head, 's', print_string);
                    break;
                // Adicione mais casos conforme necessário
                default:
                    break;
            }
        }
    }

    // Processa os nós da lista
    Node* current = head;
    while (current != NULL) {
        current->func(args);
        current = current->next;
    }

    va_end(args);

    // Libera a lista
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    my_printf("Hello %s, you have %d new messages.\n", "Alice", 5);
    return 0;
}
