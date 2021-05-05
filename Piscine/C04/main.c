#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
void ft_putnbr_base(int, char*);
int	ft_atoi_base(char *str, char *base);

void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}

int main(){
	print_line(0);
	char str_01[30] = "Hello~";
	int length;
	length = ft_strlen(str_01);
	printf("String : %s\n", str_01);
	printf("Length : %d", length);
	
	print_line(1);
	char str_11[50] = "Hello World, 42 Seoul Piscine";
	ft_putstr(str_11);

	print_line(2);	
	ft_putnbr(42);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(-2147483648);

	print_line(3);
	char str_31[100] = " ---+--+1234ab567";
	char str_32[100] = " \n\t ----+++-+2147483648b";
	int ans_31 = ft_atoi(str_31);
	printf("%d\n", ans_31);
	int ans_32 = ft_atoi(str_32);
	printf("%d\n", ans_32);

	print_line(4);
	char arr[20] = "0123456789";
	int num = 2147483647;
	ft_putnbr_base(num, arr);
	printf("\n");
	num = -2147483648;
	ft_putnbr_base(num, arr);

	print_line(5);
	char str[50] = "";
	char base[50] = "1023456789ABC";
	int ans = ft_atoi_base(str, base);
	printf("%d", ans);

	print_line(6);

	print_line(7);

	print_line(8);
}
