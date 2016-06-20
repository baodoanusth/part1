#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

echo `sort -k 1,2n -k 2 result.txt` >> result.txt

IFS=$SAVEIFS
