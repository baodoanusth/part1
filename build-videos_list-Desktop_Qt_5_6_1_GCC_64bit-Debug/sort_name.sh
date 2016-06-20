#!/bin/bash




truncate -s 0 sort_result.txt

sort -k 6 result.txt >> sort_result.txt

