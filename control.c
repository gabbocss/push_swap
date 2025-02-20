/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inbauman <inbauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:28:46 by inbauman          #+#    #+#             */
/*   Updated: 2025/02/19 15:29:04 by inbauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int control_duplicados2(const char *s1, const char *s2)
{
	int i;
	const unsigned char	*us1;
	const unsigned char	*us2;

	us1 = (const unsigned char *)s1;
	us2 = (const unsigned char *)s2;
	i = 0;
	while (us1[i] != '\0' && us2[i] != '\0')
	{
		if (us1[i] != us2[i])
			return (1);
		i++;
	}
	return (0);
}

int control_duplicados(char *argv[], int argc)
{
	
    int i;
    int n;
	int j;

	j = 0;
    i = 1;
    n = 0;
	while (i < argc - 1)
    {
		j = i +1;
		while(j < argc)
		{
			n = control_duplicados2(argv[i], argv[j]);
		
    	    if (n == 0)
				return (0);
			j++;
		}
        i++;
    }
    return (1);
}
