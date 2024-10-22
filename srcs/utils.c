/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjossain <sjossain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:46:29 by sjossain          #+#    #+#             */
/*   Updated: 2024/10/21 13:46:29 by sjossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


size_t	get_current_time ( void )
{
	struct  timeval 	time ;

	if (gettimeofday(&time, NULL ) == -1 )
		write( 2 , "gettimeofday() error\n" , 22 );
	return (time.tv_sec * 1000 + time.tv_usec / 1000 );
}

void	writer_error(char *message)
{
	size_t	len;

	len = 0;
	while (message[len] != '\0')
		len++;
	write(STDERR , message, len);
}
