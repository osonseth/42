#!/bin/bash

# Chemin vers le fichier de suppressions
SUPPRESSIONS_FILE="valgrind.supp"

# Nom du programme à exécuter
PROGRAM="minishell"

# Vérifiez si le fichier de suppressions existe
if [ ! -f "$SUPPRESSIONS_FILE" ]; then
    echo "Le fichier de suppressions $SUPPRESSIONS_FILE n'existe pas."
    exit 1
fi

# Vérifiez si le programme existe et est exécutable
if [ ! -x "$PROGRAM" ]; then
    echo "Le programme $PROGRAM n'existe pas ou n'est pas exécutable."
    exit 1
fi

# Exécutez Valgrind avec les options spécifiées
valgrind --leak-check=full --show-leak-kinds=all --suppressions="$SUPPRESSIONS_FILE" ./"$PROGRAM"



