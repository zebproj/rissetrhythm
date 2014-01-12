mencoder mf://rr_graphics/*.png -mf w=400:h=300:fps=24:type=png \
-audiofile risset.wav -ovc copy -oac copy -o output.avi

#mencoder mf://*.png -mf w=400:h=300:fps=24:type=png  -ovc copy -oac copy -o output.avi
