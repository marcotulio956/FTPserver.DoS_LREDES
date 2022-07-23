#!/bin/bash
if [ "$1" == "" ] #sem argumentos
then
echo "Exemplo de uso: $0 URL" #solicita argumento ao usuário
else
echo "Subdomínios em $1:"
rm index.html #remove arquivo index.html, se já existir
rm lista #remove arquivo lista, se já existir
wget -q $1 #requisita o arquivo index.html ao servidor alvo
grep href index.html | cut -d "/" -f3 | grep "\." | cut -d "\"" -f1 |
grep "$1" | sort -u > lista #cria uma lista dos domínios encontrados
for url in $(cat lista);do host $url;done | grep "has address" | sort
-u #para cada domínio da lista, busca o IP correspondente
fi
