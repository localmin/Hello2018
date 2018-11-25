#!/bin/bash
set -e 
gcc -o my_wc my_wc.c

[ "`./my_wc test1`" = '5 test1' ]

[ "`./my_wc test2`" = '1 test2' ]

[ "`./my_wc test1 test2`" = '5 test1
1 test2
6 total' ]

echo Done
