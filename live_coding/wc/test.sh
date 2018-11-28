#!/bin/bash
set -e 
gcc -o my_wc my_wc.c

[ "`./my_wc < test1`" = "`wc < test1`" ]
[ "`./my_wc < /dev/null`" = "`wc < /dev/null`" ]
[ "`./my_wc test1`" = "`wc test1`" ]
[ "`./my_wc test2`" = "`wc test2`" ]
[ "`./my_wc test1 test2`" = "`wc test1 test2`" ]

echo Done
