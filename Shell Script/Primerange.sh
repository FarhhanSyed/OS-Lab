#!/bin/bash
echo "Enter lower bound:"
read n1
echo "Enter upper bound:"
read n2
for ((i=n1; i<=n2; i++)); do
    flag=0
    for ((j=2; j<=i/2; j++)); do
        if ((i%j == 0));then
            flag=1 
            break
        fi
    done
    if ((flag == 0));then
        echo -n "$i "
    fi
done
