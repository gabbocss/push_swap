#include "libft.h"
#include "push_swap.h"

int	preparar_argumentos(int argc, char **argv, char ***args, int *arg_count)
{
	if (argc == 2)
	{
		*args = ft_split(argv[1], ' ');
		if (!*args || !(*args)[0] || !(*args)[1])
		{
			free_split(*args);
			return (0); 
		}
		*arg_count = contar_tokens(*args);
	}
	else
	{
		if (argc <= 2)
			return (0);
		*args = argv + 1;
		*arg_count = argc - 1;
	}
	return (1);
}

void	free_split(char **split)
{
	int	i = 0;

	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	contar_tokens(char **args)
{
	int	count;

	count = 0;
	if (!args)
		return (0);
	while (args[count])
		count++;
	return (count);
}


