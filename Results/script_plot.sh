#!/bin/bash
set title "{/:Bold Comparaison avec le flag -O3 }"
set title font "arial,14"
set border 3 front lt black linewidth 1.000 dashtype solid
set style data histogram 
set style histogram clustered gap 1
set style fill solid noborder
set datafile separator " "
plot newhistogram "o2", "result1.txt" u 2:xtic(" ") t "Normal" lc rgbcolor "blue" lt 1, "result2.txt" u 2:xtic(" ") t "avec parallélisme" lc rgbcolor "green" lt 1

