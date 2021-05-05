#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strdup(char *src);
int		*ft_range(int min, int max);
int		ft_ultimate_range(int **range, int min, int max);
char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	**ft_split(char *str, char *charset);

void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}
int main(void){
	
	print_line(0);
	char test01[15] = "Hello World";
	char  *test02;
	test02 = ft_strdup(test01);
	printf("ft_strdup : %s\n", test02);
	test02 = strdup(test01);
	printf("strdup : %s\n", test02);
	
	print_line(1);	
	int *test11 = ft_range(24, 42);
	for(int i = 0; i <= 42 - 24; i++)
		printf("%d ", *(test11 + i));	

	print_line(2);
	int *test21;
	int size = ft_ultimate_range(&test21, -2147483648, -2147483640);
	printf("size : %d\n", size);
	for(int i = 0; i <= 18; i++)
		printf("%d ", *(test21 + i));

	print_line(3);
	char *test3[7] = {"Hello", "World", "42", "Seoul", "Piscine", "", "-dokwon-"};
	char test31[5] = " / ";
	char *test32 = ft_strjoin(7, test3, test31);	
	printf("return value : %p\n%s\n", test32, test32);

	print_line(4);
	char test41[100] = "";
	char test42[100] = "0123456789ABCDEF";
	char test43[100] = "21";
	char *rtn;
	rtn = ft_convert_base(test41, test42, test43);
	printf("%s\n", rtn);

	print_line(5);
	char str51[50] = "a, b, c";
	char str52[50] = ",";
	char **str5 = ft_split(str51, str52);
	printf("str : %s | sep : %s\n", str51, str52);
	for(int i = 0; str5[i]; i++)
		printf("%s/", str5[i]);
	print_line(6);

	print_line(7);

	print_line(8);

	print_line(9);

	print_line(10);
}
