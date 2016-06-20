
#!/bin/bash




truncate -s 0 sort_result.txt

sort -k 1,2n -k 2 result.txt >> sort_result.txt

