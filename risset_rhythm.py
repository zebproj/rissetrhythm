def wp(tempo_1, tempo_2, step, total_steps, time, dur, pattern, reps, its,
		fname = ''):
	slope = 1.0 * (tempo_2 - tempo_1)/total_steps
	tempo = tempo_1
	fps = 24
	if(fname != ''): fout = open(fname, "a")
	for j in range(reps):
		for i in pattern:
			time_scale = 60.0/tempo 
			if(i != 0):
				print ("i%i %g %g" % (i, time, dur))
				if(fname != ''):
					fout.write("%i, %i\n" % 
							(int(time * fps),
							int(dur * fps)))
			time += step * time_scale
			tempo += slope
	if(fname != ''): fout.close()
	if(its != 0):
		its -= 1
		wp(tempo_1, tempo_2, step, total_steps, time, dur, pattern,reps, its, fname)

def wp_mel(tempo_1, tempo_2, step, total_steps, 
		time, dur, pattern, reps, its, instr = 1, fname = ''):
	slope = 1.0 * (tempo_2 - tempo_1)/total_steps
	tempo = tempo_1
	fps = 24
	if(fname != ''): fout = open(fname, "a")
	for j in range(reps):
		for i in pattern:
			time_scale = 60.0/tempo 
			if(i != 0):
				print ("i%i %g %g %i" % (instr, time, dur, i))
				if(fname != ''):
					fout.write("%i, %i, %i\n" % 
							(i,
							int(time * fps),
							int(dur * fps)))
			time += step * time_scale
			tempo += slope
	if(fname != ''): fout.close()
	if(its != 0):
		its -= 1
		wp_mel(tempo_1, tempo_2, step, total_steps, time, dur, pattern,reps, its, instr, fname)
