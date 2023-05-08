set terminal pngcairo font "Arial,12" fontscale 1.8 size 1400, 700
set output 'Performances for different flags of optimisation (normal version).jpg'

set boxwidth 1.0
set style fill  solid 
set key fixed top right
set key box 
set style histogram clustered gap 2  title textcolor lt -1 
set style data histograms
set grid 



set xrange [ 0 : * ] 
set xlabel "Optimisation options"
set yrange [ * : * ] 
set ylabel " Miliseconds (Ms)"




set title 'performances for different options of optimisation (normal version of the code)'

#tracer les histogrammes en utilisant les données de la deuxième colonne des fichiers.dat

plot 'normal_sans_flag.dat' using 2:xtic(2) ti "Sans flag" lc rgb '#FFA07A ','normal_-Ofast.dat' using 2:xtic(2) ti "-Ofast" lc rgb '#FDBEB9', 'normal_-O0.dat' using 2:xtic(2) ti "-O0" lc rgb '#FF1493', 'normal_-O1.dat' using 2:xtic(2) ti "-O1" lc rgb '#FF69B4 ', 'normal_-O2.dat' using 2:xtic(2) ti "-O2" lc rgb '#C71585', 'normal_-O3.dat' using 2:xtic(2) ti "-O3" lc rgb '#B22222'

replot
