import risset_rhythm as rr

def notenumber(pitch):
	
	if len(pitch) != 3:
		print "ERROR: note must be 3 characters long!\n"
		return 0
	
	note = pitch[0]
	acc = pitch[1]
	otv = pitch[2]
	
	if note == 'C':
		val = 0
	elif note == 'D':
		val = 2
	elif note == 'E':
		val = 4
	elif note == 'F':
		val = 5
	elif note == 'G':
		val = 7
	elif note == 'A':
		val = 9
	elif note == 'B':
		val = 11

	if acc == '#':
		val += 1
	elif acc == 'b':
		val -= 1

	val += 12*(int(otv) + 1)

	return  val


kick_pattern = [2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0]
snare_pattern = [0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0]
hihat_pattern = [	1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0,
				1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1 ]
clap_pattern = [4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0]

mel_pat = [
		"Bb3", 0, "Eb4", 0, "F-4", 0, "Bb4", 0, 0, 0, 0, 0, 0, 0, 0, 0,
		"Bb3", "Eb4", "F-4", "D-5", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		]
mel_pat_2 = [
		"C-5", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "A-4", 0, 0, 0
		]

for i in range(len(mel_pat)):
	if(type(mel_pat[i]) is str):
		mel_pat[i] = notenumber(mel_pat[i])

for i in range(len(mel_pat_2)):
	if(type(mel_pat_2[i]) is str):
		mel_pat_2[i] = notenumber(mel_pat_2[i])

tempo_1 = 120
tempo_2 = 60
step = 0.25
total_steps = 31
start_time = 0
dur = 0.8
its = 4 #how many times to repeat the process

rr.wp(tempo_1, tempo_2, step, total_steps, start_time, dur, kick_pattern, 2, its)
rr.wp(tempo_1, tempo_2, step, total_steps, start_time, dur, snare_pattern, 2,its)
rr.wp(tempo_1, tempo_2, step, total_steps, start_time, dur, hihat_pattern, 1, its)
rr.wp(tempo_1, tempo_2, step, total_steps, start_time, dur, clap_pattern, 2, its)
rr.wp_mel(tempo_1, tempo_2, step, total_steps, start_time, 3, mel_pat, 1, its, 5)
rr.wp_mel(tempo_1, tempo_2, step, total_steps, start_time, 3, mel_pat_2, 2, its, 5)



#print type(mel_pat[0])

