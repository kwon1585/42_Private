#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);


void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}

int main(){
	print_line(0);
	char str_01[10] = "What the ";
	char str_02[19] = "What the fu";
	int n;
	printf("1 : %s / 2 : %s\n", str_01, str_02);
   	n = strcmp(str_01, str_02);
	printf("strcmp : %d\n", n);
	n = ft_strcmp(str_01, str_02);
	printf("ft_strcmp : %d\n", n);

	print_line(1);
	char str_11[10] = "Hello~~";
	char str_12[19] = "Hello";
	printf("1 : %s / 2 : %s\n", str_11, str_12);
   	n = strncmp(str_11, str_12, 5);
	printf("strncmp : %d\n", n);
	n = ft_strncmp(str_11, str_12, 5);
	printf("ft_strncmp : %d\n", n);
	
	print_line(2);
	char str_21[50] = "42 Seoul Piscine";
	char str_23[50] = "42 Seoul Piscine";
	char str_22[50] = "r dokwon";
	printf("1 : %s / 2 : %s\n", str_21, str_22);
   	strcat(str_21, str_22);
	printf("strcat : %s\n", str_21);
	ft_strcat(str_23, str_22);
	printf("ft_strcat : %s\n", str_23);

	print_line(3);
	char str_31[50] = "42 Seoul ";
	char str_33[50] = "42 Seoul ";
	char str_32[50] = "Pisciner dokwon";
	printf("1 : %s / 2 : %s\n", str_31, str_32);
   	strncat(str_31, str_32, 9);
	printf("strncat : %s\n", str_31);
	ft_strncat(str_33, str_32, 9);
	printf("ft_strncat : %s\n", str_33);

	print_line(4);
	char str_41[50] = "r22e";
	char str_42[10] = "";
	char *point;
	point = ft_strstr(str_41, str_42);
	printf("%p %c\n", point, *point);
	point = strstr(str_41, str_42);
	printf("%p %c", point, *point);

	print_line(5);
	char str_51[50] = "42";
	char str_52[50] = "Seoul Pisciner";
	char str_53[50] = "42";
	int m;
	m = ft_strlcat(str_51, str_52, 16);
	printf("%s %d\n", str_51, m);
	m = strlcat(str_53, str_52, 16);
	printf("%s %d\n", str_53, m);

	print_line(6);

	print_line(7);

	print_line(8);
}
