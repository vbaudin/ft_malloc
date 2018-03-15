/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbaudin <vbaudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:22:52 by vbaudin           #+#    #+#             */
/*   Updated: 2018/03/15 18:41:34 by vbaudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <stdio.h>
# include <sys/mman.h>

# define n 0x80
# define m 0x200
# define N (getpagesize() * 8)
# define M (getpagesize() * 64)

/*  STRUCTURE PROPRE A CHAQUE PAGE
    type : 1=tiny,2=small,3=large   */
typedef struct      s_info
{
    short           type;
    struct s_info	*next;
    struct s_info	*prev;
    struct s_meta   *freed;
    struct s_meta   *taken;
    void            *memory;
    int             memory_left;
}                   t_info;

/* STRUCTURE PROPRE A CHAQUE MALLOC */
typedef struct      s_head
{
    size_t          size;
}                   t_head;

typedef struct      s_meta
{
    struct s_meta   *prev;
    struct s_meta   *next;
    void            *data;
}                   t_meta;

/* STRUCTURE GLOBALE */
typedef struct      s_mem
{
    t_info          *list;
    void            *root[2];
    size_t          ret[2];
    //meta used
    //meta freed
    //next non allocate zone
}                   t_mem;

t_mem               g_mem;

void                *ft_malloc(size_t size);
void                check_metas(size_t size);
void                create_page(int type_max, short type);

#endif
