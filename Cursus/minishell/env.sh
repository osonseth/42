#!/bin/bash


SUPPRESSIONS_FILE="valgrind.supp"

PROGRAM="minishell"


if [ ! -f "$SUPPRESSIONS_FILE" ]; then
    echo "Le fichier de suppressions $SUPPRESSIONS_FILE n'existe pas."
    exit 1
fi


if [ ! -x "$PROGRAM" ]; then
    echo "Le programme $PROGRAM n'existe pas ou n'est pas exécutable."
    exit 1
fi


env -i PATH=/usr/bin:/bin valgrind --leak-check=full --show-leak-kinds=all --suppressions="$SUPPRESSIONS_FILE" ./"$PROGRAM"


