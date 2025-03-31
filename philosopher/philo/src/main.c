/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 16:05:15 by pamallet          #+#    #+#             */
/*   Updated: 2025/03/31 15:53:11 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	mails = 0;

void	*routine()
{
	//printf "timestamp_in_ms X [action based on routine call]"
	sleep(3);
	for (int i = 0; i < 1000000; i++) {	//choose a big number to let OS context switch
		mails++;	//3 CPU's operations(read, increment, write)*
	}
	printf("Ending thread");
}

//* quantum time reached, OS interrupt it to let another one exec

// void	*routine2()
// {
// 	sleep(3);  
// 	printf("Ending thread");
// }

int	main(void)
{
	pthread_t		t1, t2;

	//fill 8 chars starting from str[13] with '.'
	//memset("A string with many chars."[13], '.', 8 * sizeof(char));

	//CREATE = start exec in calling process, by exec routine()
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (EXIT_FAILURE);
	pthread_create(&t2, NULL, &routine, NULL);

	//JOIN = wait for the ending of the target thread
	if (pthread_join(t1, NULL) != 0)
		return (EXIT_FAILURE);
	pthread_join(t2, NULL);

	//suspend thread exec
	//actual suspension time may be longer than the amount of time spe
	//(cause other activity / time to spent process call)
	unsigned int	usecs;

	usecs = 1500;
	usleep(usecs); //0(success) or -1(error)

	//for timestamp_in_ms, give n of microsec tv.tv_usec since Epoch(time)
	//if either tv or tz = NULL
	// struct timeval	*tv;
	// struct timezone	*tz; //?

	// gettimeofday(tv, tz);
	return (0);
}