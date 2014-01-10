<CsoundSynthesizer>
<CsOptions>
;-d -odac:system:playback_ -+rtaudio="jack" 
;-B 4096
-orisset.wav -W -d
</CsOptions>
<CsInstruments>

sr	=	96000
ksmps	=	1
nchnls	=	2
0dbfs	=	1

#define AMP #0.3#

gisine ftgen 0, 0, 4096, 10, 1

instr 1	;hat.wav
iamp = $AMP

ichan filenchnls "hat.wav"
print ichan

if ichan == 2 goto stereo
a1 diskin2 "hat.wav", 1
a2 = a1
goto output

stereo:
a1, a2 diskin2 "hat.wav", 1

output:
outs a1 * iamp, a2 * iamp
endin
	
instr 2	;kick.wav
iamp = $AMP

ichan filenchnls "kick.wav"
print ichan

if ichan == 2 goto stereo
a1 diskin2 "kick.wav", 1
a2 = a1
goto output

stereo:
a1, a2 diskin2 "kick.wav", 1

output:
outs a1 * iamp, a2 * iamp
endin
	
instr 3	;rim.wav
iamp = $AMP

ichan filenchnls "rim.wav"
print ichan

if ichan == 2 goto stereo
a1 diskin2 "rim.wav", 1
a2 = a1
goto output

stereo:
a1, a2 diskin2 "rim.wav", 1

output:
outs a1 * iamp, a2 * iamp
endin

instr 4	;TR-909Clap.wav
iamp = $AMP

ichan filenchnls "TR-909Clap.wav"
print ichan

if ichan == 2 goto stereo
a1 diskin2 "TR-909Clap.wav", 1
a2 = a1
goto output

stereo:
a1, a2 diskin2 "TR-909Clap.wav", 1

output:
outs a1 * iamp, a2 * iamp
endin
	

instr 5
iamp = ampdb(-12) * 0.5
print iamp
icps = cpsmidinn(p4)
aenv linseg 1, p3, 0
a1 foscil  iamp, icps, 1, 1, 1, gisine
a1 = a1 * aenv
outs a1, a1
endin

</CsInstruments>
<CsScore>

#include "out.sco"

</CsScore>
</CsoundSynthesizer>

