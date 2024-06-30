#include <stdio.h> //do usunięcia
#include <unistd.h>

int	converter(const char *str)
{
	int i;
	long long int	number;

	i = 0;
	number = 0;
	
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	if (number > 2147483647)
		return (-1);
	return (int)(number);
}

int main(int argc, char **argv)
{
	int i;
	int num_array[argc - 1];

	i = 1;
	if (argc == 1)
		return (write(2, "Error\n", 6));
	while (i < argc)
	{
		num_array[i - 1]  = converter(argv[i]);
		if (num_array[i - 1] == -1)
			return (write(2, "Error\n", 6));
		printf("%d\n", num_array[i - 1]);
		i++;
	}
	return (0);
}
