set terminal pngcairo font "Arial,12" fontscale 1.8 size 1400, 700
set output 'Performances for parallel version.jpg'

set boxwidth 1.00
set style fill  solid 1.00
set key fixed top right
set key box 
set style histogram clustered gap 2  title textcolor lt -1 
set style data histograms
set grid 



set xrange [ 0 : * ] 
set xlabel "Cflags optimisations"
set yrange [ * : * ] 
set ylabel " Miliseconds (Ms)"




set title 'performances for different Cflags of optimisation (parallel version)'

#tracer les histogrammes en utilisant les données de la deuxième colonne des fichiers.dat

#tracer les histogrammes en utilisant les données de la deuxième colonne des fichiers.dat

plot 'sans_flag.dat' using 2:xtic(2) ti "Without Cflags" lc rgb '#808000','Ofast.dat' using 2:xtic(2) ti "-Ofast" lc rgb '#90EE90', 'O0.dat' using 2:xtic(2) ti "-O0" lc rgb '#2E8B57 ', 'O1.dat' using 2:xtic(2) ti "-O1" lc rgb '#9ACD32 ', 'O2.dat' using 2:xtic(2) ti "-O2" lc rgb '#006400 ', 'O3.dat' using 2:xtic(2) ti "-O3" lc rgb '#00FF00'
replot
