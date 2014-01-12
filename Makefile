drums = kick snare hihat clap
melody = mel_pat_1 mel_pat_2 A4 Bb3 C5 D5 Eb4 F4
graphics  = risset 
objects = output.avi risset.wav scene.bin out.sco create_scene
TOTAL_FRAMES = 720

default:

#make score and frame breakpoint file
out.sco: pattern.py risset_rhythm.py
	make clean
	python pattern.py > out.sco
	perl parse_melody.pl
risset.wav: pattern.py drums.csd out.sco
	csound drums.csd

create_scene: create_scene.c
	gcc create_scene.c -o create_scene

scene.bin: create_scene
	./create_scene

clean:
	rm -f ${drums}
	rm -f ${melody}
	rm -f ${objects}
	make clean_graphics

risset: rr_graphics/risset.c scene.bin
	cd rr_graphics;\
	gcc risset.c -o risset -lcairo -DFRAMES=${TOTAL_FRAMES}

output.avi: makevideo.sh 
	make scene.bin
	make risset
	cd rr_graphics;\
	./risset
	sh makevideo.sh

clean_graphics:
	cd rr_graphics; rm -rf ${graphics}; rm -f *.png;\

audio_only:
	make risset.wav

all:
	make risset.wav
	make output.avi
