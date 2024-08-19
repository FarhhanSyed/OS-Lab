#!/bin/bash
echo "Enter a number:"
read n
x=$n
rev=0
while [ $n -gt 0 ]
    do
        r=$(($n%10))
        rev=$(($rev*10+$r))
        n=$(($n/10))
    done
if [ $x -eq $rev ];then
    echo "$x is palindrome"
    else
        echo "$x is not palindrome"
fi
        
