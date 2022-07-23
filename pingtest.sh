#!/bin/bash
if [ "$1" == "" ] #sem argumentos
then
echo "Uso: $0 10.0.0"
else
for host in {1..254};do #loop para pingar cada edereço de host na rede
ping -c1 $1.$host | grep "64 bytes" | cut -d ":" -f1 | cut -d " " -f4
#imprime somente os IPs que retornaram o ping
done 
fi
