Risset Rhythm
By Paul Batchelor

The Risset Rhythm is a fantastic audio illusion invented by Jean Claude Risset. It is a rhythm which gives the impression of a infinitely slowing down tempo.

This implementation for the Risset rhythm has the source code for the audio, as well as code to generate corresponding visuals.

In order to compile just the audio, you will need:

Your own drum samples, named kick.wav, rim.wav, hat.wav, and clap.wav
Csound 5
Python 2.7
Make

To compile the video, you will additionally need:
gcc
libcairo
mencoder
perl


To build everything, run the command:

"make all"

To build the audio portion only, run the command:

"make audio_only" 

To clean the project, run the command:

"make clean"




