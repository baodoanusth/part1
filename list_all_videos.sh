#!/bin/bash

TYPES=( mov mp4 avi mkv flv )

echo "enter a directory: "
read DIR

TYPES_RE="\\("${TYPES[1]}
for t in "${TYPES[@]:1:${#TYPES[*]}}"; do
    TYPES_RE="${TYPES_RE}\\|${t}"
done
TYPES_RE="${TYPES_RE}\\)"

SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

regex="[^/]*$"
truncate -s 0 result.txt
for f in `find ${DIR} -type f -regex ".*\.${TYPES_RE}"`; do
    
    file_name=`echo ${f} | grep -oP "$regex"`
    SIZE=`stat -c "%s" ${f}`
    DATE=`stat -c "%y" ${f}`
    SIZEK=`echo "scale=2; ${SIZE} / 1024" | bc -l`
    SIZEM=`echo "scale=2; ${SIZEK} / 1024" | bc -l`
    echo ${DATE} ${SIZEK}Kb ${SIZEM}Mb ${file_name} >> result.txt
done  

IFS=$SAVEIFS
