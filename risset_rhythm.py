def wp(tempo_1, tempo_2, step, total_steps, time, dur, pattern, reps, its):
	slope = 1.0 * (tempo_2 - tempo_1)/total_steps
	tempo = tempo_1
	for j in range(reps):
		for i in pattern:
			time_scale = 60.0/tempo 
			if(i != 0):
				print ("i%i %g %g" % (i, time, dur))
			time += step * time_scale
			tempo += slope
	if(its != 0):
		its -= 1
		wp(tempo_1, tempo_2, step, total_steps, time, dur, pattern,reps, its)

def wp_mel(tempo_1, tempo_2, step, total_steps, 
		time, dur, pattern, reps, its, instr = 1):
	slope = 1.0 * (tempo_2 - tempo_1)/total_steps
	tempo = tempo_1
	for j in range(reps):
		for i in pattern:
			time_scale = 60.0/tempo 
			if(i != 0):
				print ("i%i %g %g %i" % (instr, time, dur, i))
			time += step * time_scale
			tempo += slope
	if(its != 0):
		its -= 1
		wp_mel(tempo_1, tempo_2, step, total_steps, time, dur, pattern,reps, its, instr)
