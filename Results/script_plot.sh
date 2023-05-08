#!/bin/bash
set title "{/:Bold Comparaison avec les flags d'optimisation }"
set title font "arial,14"
set border 3 front lt black linewidth 1.000  solid
set style data histograms
set style histogram clustered gap 1
set style fill solid border -1
set datafile separator " "
set boxwidth 0.9 relative
plot  "result.txt" using 2:xtic(1) title "No Flags",\
"result-O2.txt" using 2:xtic(1) title "O2",\
"result-O3.txt" using 2:xtic(1) title "O3",\
"result-Ofast.txt" using 2:xtic(1) title "Ofast"