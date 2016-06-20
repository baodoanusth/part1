#!/bin/bash

TYPES=( mov mp4 avi mkv flv 3gp 3gpp vob wmv )

DIR=$1

# Create a regex of the extensions for the find command
TYPES_RE="\\("${TYPES[1]}
for t in "${TYPES[@]:1:${#TYPES[*]}}"; do
    TYPES_RE="${TYPES_RE}\\|${t}"
done
TYPES_RE="${TYPES_RE}\\)"

regex="[^/]*$"                                       #regex to remove "/" and everything before it
truncate -s 0 result.txt
for f in `find ${DIR} -type f -regex ".*\.${TYPES_RE}"`; do
    
    file_name=`echo ${f} | grep -oP "$regex"`
    SIZE=`stat -c "%s" ${f}`
    DATE=`stat -c "%y" ${f}`
    SIZEK=`echo "scale=2; ${SIZE} / 1024" | bc -l`   
    SIZEM=`echo "scale=2; ${SIZEK} / 1024" | bc -l`
    echo ${DATE} ${SIZEK}Kb ${SIZEM}Mb ":" ${file_name} >> result.txt
done  


