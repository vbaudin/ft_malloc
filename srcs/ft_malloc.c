/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <vbaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:09:31 by vbaudin           #+#    #+#             */
/*   Updated: 2018/03/15 20:13:25 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_malloc.h"


void    *ft_malloc(size_t size)
{
    //Appel a la globale : g_mem
    (void)size;
    check_metas(size);
    return (NULL);
}

/* CHECKER SI IL Y A ASSEZ DE PLACE SINON RECREER UNE PAGE */
void    check_metas(size_t size)
{
    if (size <= n && !g_mem.root[0])
    {
        printf("Create TINY\n");
        create_page(N, 0);
    }
    else if (n <= size && size <= m && !g_mem.root[1])
    {
        printf("Create SMALL\n");
        create_page(M, 1);
    }
    else if (m < size)
    {
        printf("Create LARGE\n");
    }
}

/* STOCKER LA NOUVELLE PAGE DANS LA LISTE DE PAGES */
void    create_page(int type_max, short type)
{
    void *pointor = mmap(0, type_max, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    
    g_mem.root[type] = pointor;
    if (!g_mem.list)
    {
        printf("PAS DE LIST !");
    }
    // SI PAS DE T_INFO METTRE CETTE PAGE SANS NEXT NI PREV
    // SI T_INFO LA METTRE A LA FIN
}

/*
COMMUN
Comment faire une structure globale ?

- Structure Info sur toute la zone memoire

- Structure Header sur chaque malloc

TINY
? < n < ?

SMALL
? < n < ?

LARGE
? < n < ?

*/
