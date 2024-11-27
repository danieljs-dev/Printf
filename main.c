#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define RESET   "\033[0m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

int				ft_printf(const char *str, ...);

void compare_and_print_result(int ft_result, int printf_result) {
    assert(ft_result == printf_result);
    if (ft_result == printf_result)
        printf(GREEN "OK\n" RESET);
    else
        printf(RED "KO\n" RESET);
}

int main(void)
{
    unsigned int small_value;
    unsigned int large_value;
    unsigned int max_value;
    int ft_result, printf_result;
    unsigned int num;
    int a;
    int *ptr;

    small_value = 42;
    large_value = 4000000000;
    max_value = UINT_MAX;
    ft_result = 0;
    printf_result = 0;
    num = 255;
    a = 42;
    ptr = &a;

    printf(BLUE "\n____Testing character value____\n\n" RESET);
	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Character: %c\n", 'A');
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Character: %c\n", 'A');
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing string____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Hello %s, you have %% new messages.\n", "Alice", 5);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Hello %s, you have %% new messages.\n", "Alice", 5);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing negative decimal value____\n\n" RESET);
	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Negative value: %d\n", -42);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Negative value: %d\n", -42);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing negative integer value____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Negative integer: %i\n", -42);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Negative integer: %i\n", -42);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing hex lower____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Hex lower %x\n", num);
    printf(CYAN "len:  %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Hex lower %x\n", num);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

	
	printf(BLUE "\n____Testing hex upper____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Hex upper %X\n", num);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Hex upper %X\n", num);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing pointer____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("%p", ptr);
    printf(CYAN "\nlen: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("%p", ptr);
    printf(CYAN "\nlen: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing NULL parser____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("O endereço de NULL é: %p\n", NULL);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("O endereço de NULL é: %p\n", NULL);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing NULL argument____\n\n" RESET);

    ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf(NULL);
    printf(CYAN "%d\n" RESET, ft_result);
    printf(YELLOW "Testing printf: " RESET);
    printf_result = printf(NULL);
    printf(CYAN "%d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing invalid specifier____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Hello %s, you have %j new messages.\n", "Alice", 5);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Hello %s, you have %j new messages.\n", "Alice", 5);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    printf(BLUE "\n____Testing small unsigned values____\n\n" RESET);

	ft_printf(YELLOW "Testing ft_printf: " RESET);
    ft_result = ft_printf("Unsigned small value: %u\n", small_value);
    printf(CYAN "len: %d\n" RESET, ft_result);
	printf(YELLOW "Testing printf: " RESET);
    printf_result = printf("Unsigned small value: %u\n", small_value);
    printf(CYAN "len: %d\n\n" RESET, printf_result);
    compare_and_print_result(ft_result, printf_result);

    // Descomente os testes adicionais para valores grandes
    /*
    //i = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
    //j = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
    //printf("\nresult1 = %d\n", i);
    //printf("\nresult2 = %d", j);

    //ft_printf("Unsigned large value: %u\n", large_value);
    //ft_printf("Unsigned max value: %u\n", max_value);
    */

    return (0);
}

/*
cc main.c ft_printf.c hex_wrappers.c num_wrappers.c ptr_wrappers.c str_wrappers.c specifiers.c errors.c libft/ft_putchar_fd.c libft/ft_itoa.c libft/ft_putstr_fd.c libft/ft_strlen.c libft/ft_strchr.c libft/ft_putnbr_fd.c libft/ft_numlen_dec.c libft/ft_putunsigned_dec_fd.c libft/ft_numlen_hex.c libft/ft_putunsigned_hex_fd.c -Wall -Wextra -Werror
*/

