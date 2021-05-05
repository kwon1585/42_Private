#include <unistd.h>

int main (){
	int a = 123;

	write(1, &a, 4);
	return 0;

}
