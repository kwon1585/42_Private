#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char *ft_strupcase(char *str);
char *ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);
void *ft_print_memory(void *addr, unsigned int size);

void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}

int main(){
	print_line(0);
	
	char str_01[30] = "Hello World";
	char str_02[30] = "";
	ft_strcpy(str_02, str_01);
	printf("%s\n", str_01);
	printf("%s\n", str_02);
	
	print_line(1);
	char str_11[100] = "42 Seoul Piscine";
	char str_12[100] = "";
	ft_strncpy(str_12, str_11, 8);
	printf("%s\n", str_11);
	printf("%s\n", str_12);
	
	print_line(2);
	char str_21[10] = "Alphabet";
	char str_22[10] = "!A#2 3";
	char str_23[10] = "";
	int rtn;
	rtn = ft_str_is_alpha(str_21);
	printf("%s : %d\n", str_21, rtn);
	rtn = ft_str_is_alpha(str_22);
	printf("%s : %d\n", str_22, rtn);
	rtn = ft_str_is_alpha(str_23);
	printf("Empty  : %d\n", rtn);

	print_line(3);
	char str_31[10] = "12345";
	char str_32[10] = "1234A";
	char str_33[10] = "";

	rtn = ft_str_is_numeric(str_31);
	printf("%s : %d\n", str_31, rtn);
	rtn = ft_str_is_numeric(str_32);
	printf("%s : %d\n", str_32, rtn);
	rtn = ft_str_is_numeric(str_33);
	printf("Empty : %d\n", rtn);
	
	print_line(4);
	char str_41[10] = "seoul";
	char str_42[10] = "Seoul";
	char str_43[10] = "";

	rtn = ft_str_is_lowercase(str_41);
	printf("%s : %d\n", str_41, rtn);
	rtn = ft_str_is_lowercase(str_42);
	printf("%s : %d\n", str_42, rtn);
	rtn = ft_str_is_lowercase(str_43);
	printf("Empty : %d\n", rtn);

	print_line(5);
	char str_51[10] = "SEOUL";
	char str_52[10] = "SeouL";
	char str_53[10] = "";

	rtn = ft_str_is_uppercase(str_51);
	printf("%s : %d\n", str_51, rtn);
	rtn = ft_str_is_uppercase(str_52);
	printf("%s : %d\n", str_52, rtn);
	rtn = ft_str_is_uppercase(str_53);
	printf("Empty : %d\n", rtn);

	print_line(6);
	char str_61[10] = "Seo \t ul";
	char str_62[10] = "SEOUL";
	char str_63[10] = "";

	rtn = ft_str_is_printable(str_61);
	printf("%s : %d\n", str_61, rtn);
	rtn = ft_str_is_uppercase(str_62);
	printf("%s : %d\n", str_62, rtn);
	rtn = ft_str_is_uppercase(str_63);
	printf("Empty : %d\n", rtn);


	print_line(7);
	char str_71[10] = "42 seoul";
	char str_72[10] = "SEOul";

	printf("%s\n", str_71);
	ft_strupcase(str_71);
	printf("%s\n", str_71);
	printf("%s\n", str_72);
	ft_strupcase(str_72);
	printf("%s\n", str_72);

	print_line(8);
	char str_81[10] = "HELlO~";
	char str_82[10] = "42 SeouL";

	printf("%s\n", str_81);
	ft_strlowcase(str_81);
	printf("%s\n", str_81);
	printf("%s\n", str_82);
	ft_strlowcase(str_82);
	printf("%s\n", str_82);

	print_line(9);
	char str_91[100] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char str_92[100] = "ReKt17+Lol MDr mDr 4242L42";

	printf("%s\n", str_91);
	ft_strcapitalize(str_91);
	printf("%s\n", str_91);
	printf("%s\n", str_92);
	ft_strcapitalize(str_92);
	printf("%s\n", str_92);


	print_line(10);
	char str_101[50] = "salut, comment tu vas?";
	char str_102[50];
	char str_1021[50];
	int rtn_10;
	int rtn_101;

	printf("%s\n", str_101);
	printf("\nreturn size : 10\n");
	rtn_10 = ft_strlcpy(str_1021, str_101, 10);
	printf("src size : %d\n", rtn_10);
	printf("%s\n", str_1021);
	rtn_101 = strlcpy(str_1021, str_101, 10);
	printf("src size : %d\n", rtn_101);
	printf("%s\n", str_1021);
	
	printf("\nreturn size : 5\n");
	rtn_10 = ft_strlcpy(str_102, str_101, 5);
	printf("src size : %d\n", rtn_10);
	printf("%s\n", str_102);
	printf("\nreturn size : 5\n");
	rtn_10 = strlcpy(str_102, str_101, 5);
	printf("src size : %d\n", rtn_10);
	printf("%s\n", str_102);

	print_line(11);
	char str_111[50] = "Coucou\ntu ­RÛÅÍ";
	printf("%s\n", str_111);
	ft_putstr_non_printable(str_111);


	print_line(12);
	char str_121[100] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";
	char str_122[100] = "­RÛÅÍ&î#z&UÊä¶l";
	ft_print_memory(str_121, 47);
	printf("\n");
	ft_print_memory(str_122, 20);
}
