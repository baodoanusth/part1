#!/bin/bash
TYPES_RE="\\("${TYPES[1]}
for t in "${TYPES[@]:1:${#TYPES[*]}}"; do
    TYPES_RE="${TYPES_RE}\\|${t}"
done
TYPES_RE="${TYPES_RE}\\)"


  truncate -s 0 search_result.txt
  find "$1" -name "*$2*" -print -type f -regex ".*\.${TYPES_RE}" >> search_result.txt


