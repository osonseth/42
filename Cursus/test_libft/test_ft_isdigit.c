/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmauchre <mmauchre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:15:27 by mmauchre          #+#    #+#             */
/*   Updated: 2023/11/12 15:25:25 by mmauchre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_libft.h"

int	test_ft_isdigit(void)
{
	FILE *file1;
	FILE *file2;
	const char *fichier1;
	const char *fichier2;
	char commande[256];
	FILE *fp;
	char resultat[1024];
	size_t tailleLue;

	file1 = fopen("output_ft_isdigit.txt", "w");
	if (file1 == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier output_ft_isdigit.txt");
		return (EXIT_FAILURE);
	}
	for (int i = -128; i < 256; i++)
	{
		if (ft_isdigit(i))
			fprintf(file1, "%d: %d\n", i, 1);
		else
			fprintf(file1, "%d: %d\n", i, 0);
	}
	fclose(file1);
	file2 = fopen("output_isdigit.txt", "w");
	if (file2 == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier output_isdigit.txt");
		return (EXIT_FAILURE);
	}
	for (int i = -128; i < 256; i++)
	{
		if (isdigit(i))
			fprintf(file1, "%d: %d\n", i, 1);
		else
			fprintf(file1, "%d: %d\n", i, 0);
	}
	fclose(file2);
	fichier1 = "output_ft_isdigit.txt";
	fichier2 = "output_isdigit.txt";
	sprintf(commande, "diff %s %s", fichier1, fichier2);
	fp = popen(commande, "r");
	if (fp == NULL)
	{
		perror("Erreur lors de l'exécution de diff");
		return (EXIT_FAILURE);
	}
	tailleLue = fread(resultat, 1, sizeof(resultat) - 1, fp);
	resultat[tailleLue] = '\0';
	pclose(fp);
	printf(BLEU "ft_isdigit  : ");
	if (tailleLue == 0)
	{
		printf(VERT "OK\n");
	}
	else
	{
		printf(ROUGE "NOK\n" RESET);
	}
	return (EXIT_SUCCESS);
}