#!/bin/bash
regex="[^:]*$"
truncate -s 0 check.txt

while read -u 1 p; do
  name1=`echo $p | grep -oP "$regex"`
  name_1="${name1%.*}"
  count=0

  while read -u 2 q; do
  name2=`echo $q | grep -oP "$regex"`
  name_2="${name2%.*}"
  if [ "$name_1" == "$name_2" ] && [ "$p" != "$q" ]
  then
  count=1
  fi
  done 2<result.txt

  if [ $count == 1 ]
  then
      echo "------$name1" >> check.txt
  else
      echo "$name1" >> check.txt
  fi


done 1<result.txt
