/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 08:48:20 by alamizan          #+#    #+#             */
/*   Updated: 2022/06/29 10:36:52 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Copie une chaine dans une autre.
char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return(dest);
}

/* ---------------------------------------------------*/

/* STRUCTURE DE DONNEES */

struct player
{
	char username[256];
	int nb_vie;
	int nb_mp;
};	// finir avec un ;

// Remplacer "struct player" par "joueur"
typedef struct player joueur;

/* ---------------------------------------------------*/

/*
	(*monPointeur).un_champ = X;
	monPointeur->un_champ = X;
*/

// Affectation des donnees par pointeur:
void create_joueur(joueur *p)
{
	ft_strcpy((*p).username, "Arkaie"); 
	(*p).nb_vie = 700;
	p->nb_mp = 20;
}

/* ---------------------------------------------------*/

int	main(void)
{
	int	index;
	int	nb_joueur;

	index = 0;
	nb_joueur = 5;

	// Initialisation de la structure:
	joueur p1 = {"Alex", 100, 50};
	joueur p2 = {"", 0, 0};

	// structure par pointeur:
	create_joueur(&p2);

	printf("-Nom du p1: %s\n-nb_vie: %d\n-nb_magie: %d\n\n", p1.username, p1.nb_vie, p1.nb_mp);

	// Modifier les valeurs:
	ft_strcpy(p1.username,"Orgal");	// copie le nv nom dans la variable username.
	p1.nb_vie = 50;
	
	// Affichage joueur 1:
	printf("Nom du joueur 1: %s\n", p1.username);
	printf("nb_vie: %d || nb_mp: %d\n\n", p1.nb_vie, p1.nb_mp);

	// Affichage joueur 2:
	printf("Nom du joueur 2: %s\n", p2.username);
	printf("nb_vie: %d || nb_mp: %d\n\n\n", p2.nb_vie, p2.nb_mp);

	// creation d un tableau de joueurs:
	joueur tableau_joueur[5];

/* ------------------------------------------------------------------ */
/*	ft_strcpy(tableau_joueur[0].username, "Lola");
	tableau_joueur[0].nb_vie = 65;
	tableau_joueur[0].nb_mp = 125;

	// Affichage joueur tableau 0:
	printf("Nom du joueur : %s\n", tableau_joueur[0].username);
	printf("nb_vie: %d || nb_mp: %d\n", tableau_joueur[0].nb_vie, tableau_joueur[0].nb_mp);*/
/* ------------------------------------------------------------------ */

	// remplissage du tableau de joueur:
	while (index < 5)
	{
		ft_strcpy(tableau_joueur[index].username, "Ragnarok");
		tableau_joueur[index].nb_vie = 50 *index+1;
		tableau_joueur[index].nb_mp = 25 *index+1;
		index++;
	}		
	
	// Affichage des donnees des joueurs du tableau:
	index = 0;
	while (index++ < 5)
	{
		printf("Nom du joueur : %s\n", tableau_joueur[index].username);
		printf("nb_vie: %d | nb_mp: %d\n\n", tableau_joueur[index].nb_vie, tableau_joueur[index].nb_mp);
	}
	return(0);
}
