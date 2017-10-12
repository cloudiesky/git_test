#!/bin/shell

tree conrot_tx_do > conrot_tx_do.txt

#cut head and tail
sed -i '1d' conrot_tx_do.txt
sed -i '$,+2d' conrot_tx_do.txt


sed -i '/^├─/d' conrot_tx_do.txt
sed -i '/^└──/d' conrot_tx_do.txt

#line head
sed -i 's/\(│   .*_\)\(.*\)/\2/g' conrot_tx_do.txt
sed -i 's/\(.*──.*_\)\(.*\)/\2/g' conrot_tx_do.txt

I=0
while ((I<50))
do
    sed -i 's/\([a-z0-9]\{4\}.*\)\([a-z0-9]\{4\}$\)/\2\n\1/g' conrot_tx_do.txt
    ((I+=1))
done


