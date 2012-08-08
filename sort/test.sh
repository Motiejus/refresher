#!/bin/bash

DATA=$(seq -10 10 | shuf)

FILE=`mktemp`

./$1 ${DATA} > $FILE
shift
for prog in "$@"; do
    ./$prog ${DATA} | diff -w $FILE -
done

rm $FILE
