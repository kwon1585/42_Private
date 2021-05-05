#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ex01/ft_boolean.h"
#include "ex02/ft_abs.h"
#include "ex03/ft_point.h"
#include "ex04/ft_stock_str.h"

void print_line(int num){
	printf("\n\n==== %d =======================================\n", num);
}

void ent(){
	printf("\n\n");
}

void	ft_putstr(char *str)
{
	 while (*str)
       		 write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

void set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

void ft_show_tab(struct s_stock_str *par);

int main(int argc, char *argv[]){
	
	//print_line(0);
	
	print_line(1);	
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)	ft_putstr(EVEN_MSG);
	else								ft_putstr(ODD_MSG);

	print_line(2);
	printf("%d, %d\n", 0, ABS(0));
	printf("%d, %d\n", 1, ABS(1));
	printf("%d, %d\n", -1, ABS(-1));
	printf("%d, %d\n", 10, ABS(10));
	printf("%d, %d\n", -10, ABS(-10));
	printf("%d, %d\n", 2147483647, ABS(2147483647));
	printf("%ld, %ld\n", -2147483648, ABS(-2147483648));

	print_line(3);
	t_point point;
	set_point(&point);
	printf("%d %d\n", point.x, point.y);

	print_line(4);
	char **av = (char **)malloc(sizeof(char *) * 3);
	av[0] = "hello";
	av[1] = "world";
	av[2] = "dokwon";
	t_stock_str *rtn_04;
	rtn_04 = ft_strs_to_tab(3, av);
	for (int i = 0; i < 3; i++)
		printf("%d, %s, %s\n", rtn_04[i].size, rtn_04[i].str, rtn_04[i].copy);

	print_line(5);
	ft_show_tab(rtn_04);
	printf("\n\n");


/*	print_line(6);

	print_line(7);

	print_line(8);

	print_line(9);

	print_line(10); */
}
