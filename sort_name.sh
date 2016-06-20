#!/bin/bash
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

echo `sort -k 6 result.txt` > result.txt

IFS=$SAVEIFS
