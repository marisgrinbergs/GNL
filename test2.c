
#include <stdio.h>
void change()
{
	static int i;
printf("%d\n", i);
	i = i + 5;
printf("%d\n", i);
}

int main()
{
	change();
		change();
		change();
		return(0);
}
