#!/bin/shell

cd bmap_tx_do
ls -1 > ../bmap_tx_do.txt
cd ..

sed -i 's/\([0-9]\{4\}\)_\(.*\)/\2/g' bmap_tx_do.txt

I=0
while ((I<100))
do
    sed -i 's/\([0-9]\{2\}.*\)\([0-9]\{2\}$\)/\2\n\1/g' bmap_tx_do.txt
    ((I+=1))
done

