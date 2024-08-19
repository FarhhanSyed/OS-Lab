#!/bin/bash
echo "Enter three numbers:"
read n1
read n2
read n3
if [ $n1 -gt $n2 ]; then
    if [ $n1 -gt $n3 ]; then
        echo "$n1 is largest"
        else
            echo "$n3 is largest"
        fi
    elif [ $n2 -gt $n3 ]; then
        echo "$n2 is largest"
        else
            echo "$n3 is largest"
    fi
