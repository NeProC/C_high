#!/usr/bin/gnuplot

# Настройки отображения
set terminal wxt enhanced
set xrange [-10:10]
set yrange [-10:10]
set grid
set title "Графики трех функций"
set xlabel "x"
set ylabel "y"

# Определение функций
f1(x) = 3/x
f2(x) = (x-2)**3 - 1
f3(x) = 0.6 * x + 3

set xtics 0.5  
set ytics 0.5

# Построение графиков
plot f1(x) with lines lw 2 title "3/x", \
     f2(x) with lines lw 2 title "(x-2)^3 - 1", \
     f3(x) with lines lw 2 title "0.6x + 3"

pause -1 "Нажмите Enter для выхода"
