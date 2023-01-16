/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:30:14 by mmensing          #+#    #+#             */
/*   Updated: 2023/01/16 15:50:01 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

// for threads
# include <pthread.h>

// for get time 
#include <sys/time.h>

// libft
# include "../include/libft/libft.h"

//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"



typedef struct s_data
{
    int32_t     amount_philos;
    char        **av;
    
//  !! till now i dont need the next 4 here!
    // int32_t     tt_die;
    // int32_t     tt_eat;
    // int32_t     tt_sleep;
    // int32_t     times_philo_eats;
    
    
	
}				t_data;

typedef struct s_philo
{	
    pthread_t   thread;
    
    int64_t     time_routine_start;
    
    int32_t     amount_philos;
    
    int32_t     id;
    
    int32_t     tt_die;
    int32_t     tt_eat;
    int32_t     tt_sleep;
    int32_t     times_philo_eats;
    
    // array of forks -> amount of philosophers forks
    pthread_mutex_t *mutex_forks;
    pthread_mutex_t mutex_left_fork;
    pthread_mutex_t mutex_right_fork;
    pthread_mutex_t mutex_message;
}				t_philo;

//      handle_input.c
void check_input(t_data *data, int32_t ac, char **av);
int32_t check_for_valid_arg(char *av);
int32_t whitespace(char c);

//      routine.c
void philo_routine(t_philo *philo);

# endif