set terminal pngcairo font "Arial,12" fontscale 1.8 size 1400, 700
set output 'Performances pour différentes drapeaux d"optimisation (normal version).jpg'

set boxwidth 1.0
set style fill  solid 1.0 
set key fixed top right
set key box 
set style histogram clustered gap 3  title textcolor lt -1 
set style data histograms
set grid 
#set offset -1,0,0,0


set xrange [ 0 : * ] 
set xlabel " Optimisation Oflags"
set yrange [ * : * ] 
set ylabel " Miliseconds (MS)"




set title 'performances for different Oflags  of optimisation (normal version)'

#tracer les histogrammes en utilisant les données de la deuxième colonne des fichiers.dat

plot 'normal_native.dat' using 2:xtic(2) ti "-march=native" lc rgb '#FFFF00','normal_unroll.dat' using 2:xtic(2) ti "LoopUnrolling" lc rgb  '#F7DC6F', 'normal_align.dat' using 2:xtic(2) ti "align" lc rgb '#F4D03F', 'normal_vectorize.dat' using 2:xtic(2) ti "Vectorization" lc rgb '#D4AC0D ', 'normal_corei3-avx.dat' using 2:xtic(2) ti "-march=corei3-avx" lc rgb '#9A7D0A' , 'normal_sans_flag.dat' using 2:xtic(2) ti "Without Oflags" lc rgb '#FFA500 '

replot
