/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamizan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:35:28 by alamizan          #+#    #+#             */
/*   Updated: 2023/03/17 13:21:20 by alamizan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// LIB open:
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// GESTION DES REDIRECTIONS.
/* -----------------------------------------------------------------
 * 3 descripteurs de flux:
 * 	- 0: entree standard --> Clavier.
 * 	- 1: sortie standard --> Ecran.
 * 	- 2: srotie d erreur --> Ecran.
 *
 *  - >: redirige le fux de la cmd pour la placer dans un fichier.
 *  Par default le flux redirigee est la sortie standard.
 *
 *  - <: redirige le flux d entree de la cmd pour la prendre
 *  dans un fichier.
 *
 *  - >>: redirige le flux de la sortie pour l ajouter a la 
 *  fin d un fichier existant.
 *
 *  EXEMPLE:
 *  	- cat > mon journal: cree un fichier et ecrit dedans.
 *  	le refaire reecrit par dessus.
 *		- cree un fichier dynamiquement:
 *			-> cat << FIN > fichier. (arrete cat avec FIN).
 *			-> cat >> fichier. (rajoute du contenu a la fin du fichier).
 *
 * OUVRIR UN FICHIER.
 * 	- man 2 open.
 *		.int open(char *path, int flags, mode_t perm)
 * 		.path = fichier.
 * 		.flags = mode d ouverture.
 * 		.perm = permissions.
 * 	- valeur de retour.
 * 		file descriptor (int) ou -1 en cas d erreur.
 * 	- flags.
 * 		.O_RDONLY: lecture seul.
 * 		.O_WRONLY: ecriture seul.
 * 		.O_RDWR: lecture et ecriture.
 *
 * 		.O_CREAT: si le fichier n existe pas, le creer.
 * 			- utiliser S_IRUSR.. pour definir les droits.
 * 		.O_TRUNC: si le fichier existe, ecrire sur le 1er octet.
 * 		.O_APPEND: si le fichier existe, ecrire depuis le dernier octet.
 * 	les flags peuvent etre additionnes.
 *
 * FERMER UN FICHIER.
 * 	- man 2 close.
 * 		.int close(int fd).
 * 		.fd = file descriptor a fernmer.
 * 	- valeur de retour:
 * 		0 ou -1 en cas d erreur.
 *
 * 	ECRIRE DANS UN FICHIER.
 * 	- man 2 write.
 * 		.int write(int fd, char *buf, int count).
 * 		.fd = file descriptor.
 * 		.buf = buffer source.
 * 		.count = nombres d octets a ecrire.
 * 	- valeur de retour.
 * 		nombre d octets ecris ou -1 en cas d erreur.
 *
 *
 * ----------------------------------------------------------------*/
int	main(int arg, char *argv[])
{
	int	fd;
	int	fd2;

 	// ouvre un fichier en lecture.
	fd = open("AL", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (1);
	}
	printf("fd=%d\n", fd);
	if (close(fd) == -1)
	{
		printf("close() failed\n");
		return (1);
	}

 	// ouvre un fichier en ecriture et le cree si il n existe pas.
	// droit en lecture et ecriture seulement.
	fd2 = open("sonic", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
//	rajoute a la fin du fichier.
//	fd2 = open("sonic", O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd2 == -1)
		printf("open() failed\n");
	printf("fd2=%d\n", fd2);
	write(fd2, argv[1], strlen(argv[1])); // ecrit dans le fichier.
	if (close(fd2) == -1)
	{
		printf("close() failed\n");
		return (1);
	}
	return (0);
}
