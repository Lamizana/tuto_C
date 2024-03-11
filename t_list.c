/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:52:22 by alamizan          #+#    #+#             */
/*   Updated: 2022/10/12 08:23:12 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Definition d une liste:
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Prototype:
t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);  

// Fonction qui retourne une liste:
t_list *ft_lstnew(void *content)
{
	t_list *ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return(0);
	(*ptr).content = content;
	ptr->next = NULL;
	return(ptr);
}

// Compte le nb delements de la liste:
int ft_lstsize(t_list *lst)
{                                                                                                    
    int i;

    i = 0;
    if (!lst)
        return (0);
    while(lst)
    {
        i++;
        lst = lst->next;	// Passe a l autre element de la liste:
    }
    return (i);
}

// Rajoute l element new au debut de la liste:
void ft_lstadd_front(t_list **lst, t_list *new)                                                      
{
    new->next= *lst;	// Ajoute adresse de lst a next de new.
    *lst = new;
}

// Renvoie l element de la fin  de la liste:
t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)	//Tant qu il y a un next:
		lst = lst->next;
	return(lst);
}

int main()
{
	t_list	*ptr;
	t_list	*tab;
	
	ptr = NULL;
	ptr = ft_lstnew("hello");
	// Affiche l element content de ptr:
	printf("- element de ptr: %s\n", (char *)ptr->content);
	printf("- nb element de ptr: %d\n\n", ft_lstsize(ptr));

	// Rajoute un element au debut dans la liste ptr:
	tab = ft_lstnew("Au revoir");
	ft_lstadd_front(&ptr, tab);	
	
	// Affiche les nouveaux elements de ptr:
	printf("- element de ptr: %p\n", (char *)tab->next->content);
	printf("- element de tab: %s\n", (char *)tab->content);
	// Compte le nombre d element de ptr:
	printf("- nb element de ptr: %d\n\n", ft_lstsize(ptr));

	// Renvoie le dernier element de la liste ptr:
	printf("- Adresse du dernier element de ptr: %p\n", (char *)ft_lstlast(ptr));
	

	return (0);
}


