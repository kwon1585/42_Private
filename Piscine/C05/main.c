#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_iterative_power(int nb, int power);
int	ft_recursive_power(int nb, int power);
int	ft_fibonacci(int index);
int	ft_sqrt(int nb);
int	ft_is_prime(int nb);
int	ft_find_next_prime(int nb);
int	ft_ten_queens_puzzle(void);

void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}
int main(void){
	int tmp;
	
	print_line(0);
	tmp = ft_iterative_factorial(5);
	printf("5! : %d\n", tmp);
	
	print_line(1);	
	tmp = ft_recursive_factorial(5);
	printf("5! : %d\n", tmp);

	print_line(2);
	tmp = ft_iterative_power(1, -9);
	printf("2 ^ 10 : %d\n", tmp);

	print_line(3);
	tmp = ft_recursive_power(1, -9);
	printf("2 ^ 10 : %d\n", tmp);
	
	print_line(4);
	tmp = ft_fibonacci(10);
	printf("10th : %d\n", tmp);
	
	print_line(5);
	tmp = ft_sqrt(2147395600);
	printf("2147395600 : %d\n", tmp);

	print_line(6);
	tmp = ft_is_prime(390408243);
	printf("390408243 : %d\n", tmp);

	print_line(7);
	tmp = ft_find_next_prime(2147483646);
	printf("2147483646 : %d\n", tmp);

	print_line(8);
/*	tmp = ft_ten_queens_puzzle();
	printf("\ncount : %d\n", tmp);
*/
	print_line(9);

	print_line(10);
}
