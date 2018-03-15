/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <vbaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:09:35 by vbaudin           #+#    #+#             */
/*   Updated: 2018/03/15 19:23:33 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int     main(void) {
    ft_malloc(10);
    // void *p = mmap(NULL, 0, PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);
    //
    // strcpy(p, "Romain");
    // printf("%p\n", p);
    return 0x0;
}
