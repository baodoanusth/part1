#!/bin/bash

# fill with more extensions or have it as a cmd line arg
TYPES=( mov mp4 avi mkv flv 3gp 3gpp vob wmv )

echo "enter a directory: "
read DIR

# Create a regex of the extensions for the find command
TYPES_RE="\\("${TYPES[1]}
for t in "${TYPES[@]:1:${#TYPES[*]}}"; do
    TYPES_RE="${TYPES_RE}\\|${t}"
done
TYPES_RE="${TYPES_RE}\\)"

# Set the field seperator to newline instead of space
SAVEIFS=$IFS
IFS=$(echo -en "\n\b")

# Generate output from path and size using: `stat -c "%s" filepath`
regex="[^/]*$"
truncate -s 0 result.txt
for f in `find ${DIR} -type f -regex ".*\.${TYPES_RE}"`; do
    
    file_name=`echo ${f} | grep -oP "$regex"`
    SIZE=`stat -c "%s" ${f}`
    DATE=`stat -c "%y" ${f}`
    SIZEK=`echo "scale=2; ${SIZE} / 1024" | bc -l`
    SIZEM=`echo "scale=2; ${SIZEK} / 1024" | bc -l`
    echo ${DATE} ${SIZEK}Kb ${SIZEM}Mb ${file_name}
    echo ${DATE} ${SIZEK}Kb ${SIZEM}Mb ":" ${file_name} >> result.txt
done  

# Reset IFS
IFS=$SAVEIFS

#sort
option=0
while [[ $option!=1 && $option!=2 && $option!=3 ]]
do
    echo "Sorting Option: <1> By Created Date <2> By Size <3> By Name"
    read option
    if [ $option -eq 1 ]
    then
        echo "List sorted by time: "
        sort -k 1,2n -k 2 result.txt
        echo -en "\n"
        break
    elif [ $option -eq 2 ]
    then
        echo "List sorted by size: "
        sort -n -k 4 result.txt
        echo -en "\n"
        break
    elif [ $option -eq 3 ]
    then
        echo "List sorted by name: "
        sort -k 6 result.txt
        echo -en "\n"
        break
    else
        echo "Wrong keyword! Plz enter again."
    fi
done

#highlight all videos having same name:
echo "Check if duplicated name:"
for f in `find ${DIR} -type f -regex ".*\.${TYPES_RE}"`; do
    file_name=`echo ${f} | grep -oP "$regex"`
    filename="${file_name%.*}"
    extension="${file_name##*.}"
    compare=0
    for i in `find ${DIR} -type f -regex ".*\.${TYPES_RE}"`; do
            file_name1=`echo ${i} | grep -oP "$regex"`
            filename1="${file_name1%.*}"
            extension1="${file_name1##*.}"
        if [ "$filename" == "$filename1" ] && [ "$extension1" != "$extension" ]
        then
            compare=1
        fi
    done
    if [ $compare == 1 ]
    then
        echo "------$file_name"
    else
        echo "$file_name"
    fi
done  

#find files by kwyword
    echo -en "\n"
    echo "Searching video files"
    echo "Enter a keyword: "
    read keyword
    echo `find "$DIR" -name "*$keyword*" -print -type f -regex ".*\.${TYPES_RE}"`
    
    


