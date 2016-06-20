#!/bin/bash



truncate -s 0 sort_result.txt

sort -n -k 4 result.txt >> sort_result.txt

