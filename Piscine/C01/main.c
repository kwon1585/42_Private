#include <stdio.h>

void ft_ft(int *nbr);
void ft_ultimate_ft(int *********nbr);
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
void ft_putstr(char *str);
int  ft_strlen(char *str);
void ft_rev_int_tab(int *tab, int size);
void ft_sort_int_tab(int *tab, int size);

void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}

int main(){
	print_line(0);
	int ans_00;
	int *nbr_00;
	nbr_00 = &ans_00;
	ft_ft(nbr_00);
	printf("%d", ans_00);

	print_line(1);
	int ans_11;
	int *nbr_11;
	int **nbr_12;
	int ***nbr_13;
	int ****nbr_14;
	int *****nbr_15;
	int ******nbr_16;
	int *******nbr_17;
	int ********nbr_18;
	int *********nbr_19;
	nbr_11 = &ans_11;
	nbr_12 = &nbr_11;
	nbr_13 = &nbr_12;
	nbr_14 = &nbr_13;
	nbr_15 = &nbr_14;
	nbr_16 = &nbr_15;
	nbr_17 = &nbr_16;
	nbr_18 = &nbr_17;
	nbr_19 = &nbr_18;
	ft_ultimate_ft(nbr_19);
	printf("%d", ans_11);
		
	print_line(2);
	int a_2 = 42;
	int b_2 = 24;
	printf("original values : %d %d\n", a_2, b_2);
	ft_swap(&a_2, &b_2);
	printf("changed  values : %d %d", a_2, b_2);
	
	print_line(3);
	int a_3 = 42;
	int b_3 = 10;
	int div, mod;
	printf("a : %d, b : %d \n", a_3, b_3);
	ft_div_mod(a_3, b_3, &div, &mod);
	printf("div : %d, mod : %d ", div, mod);

	print_line(4);
	int a_4 = 4242;
	int b_4 = 4200;
	printf("a : %d, b : %d \n", a_4, b_4);
	ft_ultimate_div_mod(&a_4, &b_4);
	printf("div(a) : %d, mod(b) : %d ", a_4, b_4);
	
	print_line(5);
	char str_5[50] = "Hello World, I am Dohyeok Kwon";
	ft_putstr(str_5);

	print_line(6);
	char str_6[30] = "Hello~";
	int length;
	length = ft_strlen(str_6);
	printf("String : %s\n", str_6);
	printf("Length : %d", length);

	print_line(7);
	int tab_7[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int size_7 = 10;
	ft_rev_int_tab(tab_7, size_7);
	for(int i = 0; i < size_7; i++)
		printf("%d ", tab_7[i]);

	print_line(8);
	int tab_8[13] = {0, 1, 342, 3, 188, 5, 6, 1, 5, 9, 34, 12, 4};
	int size_8 = 13;
	ft_sort_int_tab(tab_8, size_8);
	for(int i = 0; i < size_8; i++)
		printf("%d ", tab_8[i]);

	print_line(9);

	print_line(10);
}
