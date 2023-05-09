set terminal pngcairo font "Arial,12" fontscale 1.8 size 1400, 700
set output 'Histogramms for Oflags optimisation (parallel).jpg'

set boxwidth 1.00
set style fill  solid 1.00 border -1 
set key fixed top right
set key box 
set style histogram clustered gap 2  title textcolor lt -1 
set style data histograms
set grid 



set xrange [ 0 : * ] 
set xlabel "Oflags optimisation levels"
set yrange [ * : * ] 
set ylabel " Miliseconds (Ms)"




set title 'performances histogramms for parallel version using different Oflags optimisation levels'

#tracer les histogrammes en utilisant les données de la deuxième colonne des fichiers.dat

plot 'sans_flag.dat' using 2:xtic(2) ti "Sans flag" lc rgb '#000000','native.dat' using 2:xtic(2) ti "-march=native" lc rgb '#2F4F4F', 'corei3-avx.dat' using 2:xtic(2) ti "-march=corei3-avx" lc rgb '#777777', 'unroll.dat' using 2:xtic(2) ti "Loop unrolling" lc rgb '#BBBBBB', 'align.dat' using 2:xtic(2) ti "Alignement" lc rgb '#333333', 'vectorization.dat' using 2:xtic(2) ti "Vectorization" lc rgb '#f5f5f5#777777#000000'


replot
