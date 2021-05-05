#include <stdio.h>

void ft_putchar(char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int n);


void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}

int main(){
	print_line(0);
	ft_putchar('z');
	
	print_line(1);
	ft_print_alphabet();
	
	print_line(2);
	ft_print_reverse_alphabet();

	print_line(3);
	ft_print_numbers();
	
	print_line(4);
	ft_is_negative(-10);
	
	print_line(5);
	ft_print_comb();

	print_line(6);
	ft_print_comb2();
	
	print_line(7);
	ft_putnbr(0);
	ent();
	ft_putnbr(31149);
	ent();

	print_line(8);
 	ft_print_combn(8);
	ent();
	ft_print_combn(7);
	ent();
	ft_print_combn(9);

	print_line(9);


	print_line(10);
}
