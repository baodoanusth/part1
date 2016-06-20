#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

echo `sort -n -k 4 result.txt` > result.txt

IFS=$SAVEIFS
