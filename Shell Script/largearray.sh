#!/bin/bash
echo "enter array size:"
read n 
declare -a arr
echo "Enter elements :"
for ((i=0;i<$n;i++)) do
    read arr["$i"]
done

max=${arr[0]}
for ((i=1;i<$n;i++)) do
    if [ ${arr[$i]} -gt $max ];then
        max=${arr[i]}
    fi
done
echo "large:$max"
