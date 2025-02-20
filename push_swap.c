/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:32:23 by inbauman          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:01 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main(int argc, char *argv[])
{
	if (argc ==  1)
		return (1);
    if (argc <= 2)
	{
		printf("Error");
		return (1);
	}
    int i;
    int control;
    
    i = argc;
    control = control_duplicados(argv, argc);
    if (control == 0)
    {
        printf("Error");
        return(1);
    }
        
    
    printf("%s", argv[i -1]);
}
