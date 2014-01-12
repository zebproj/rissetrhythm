#include <stdio.h>
#define OPACITY_THRESHOLD 0.05
typedef struct{
	FILE *fp;
	long time;
	long duration;
	float fade_speed;
	float opacity;
}CIRCLE;	

int main(int argc, char *argv[])
{
	float seconds = 30;
	int fps = 24;
	int frames = seconds * fps;
	int i = 0;
	/* Drums */
	CIRCLE kick, snare, clap, hihat;
	/* Notes */
	CIRCLE A4, Bb3, C5, D5, Eb4, F4;


	kick.fp = fopen("kick", "r");
	snare.fp = fopen("snare", "r");
	clap.fp = fopen("clap", "r");
	hihat.fp = fopen("hihat", "r");
	A4.fp = fopen("A4", "r");
	Bb3.fp = fopen("Bb3", "r");
	C5.fp = fopen("C5", "r");
	D5.fp = fopen("D5", "r");
	Eb4.fp = fopen("Eb4", "r");
	F4.fp = fopen("F4", "r");

	fscanf(kick.fp, "%ld, %ld\n", &kick.time, &kick.duration);
	fscanf(snare.fp, "%ld, %ld\n", &snare.time, &snare.duration);
	fscanf(clap.fp, "%ld, %ld\n", &clap.time, &clap.duration);
	fscanf(hihat.fp, "%ld, %ld\n", &hihat.time, &hihat.duration);
	fscanf(A4.fp, "%ld, %ld\n", &A4.time, &A4.duration);
	fscanf(Bb3.fp, "%ld, %ld\n", &Bb3.time, &Bb3.duration);
	fscanf(C5.fp, "%ld, %ld\n", &C5.time, &C5.duration);
	fscanf(D5.fp, "%ld, %ld\n", &D5.time, &D5.duration);
	fscanf(Eb4.fp, "%ld, %ld\n", &Eb4.time, &Eb4.duration);
	fscanf(F4.fp, "%ld, %ld\n", &F4.time, &F4.duration);

	kick.opacity = 0.0;
	snare.opacity = 0.0;
	clap.opacity = 0.0;
	hihat.opacity = 0.0;
	A4.opacity = 0.0;
	Bb3.opacity = 0.0;
	C5.opacity = 0.0;
	D5.opacity = 0.0;
	Eb4.opacity = 0.0;
	F4.opacity = 0.0;

	FILE *scene;
   	scene = fopen("scene.bin", "wb");


	for(i = 0; i < frames; i++){
		/* kick circle */
		if(i == kick.time){
			kick.opacity = 1.0;
			fscanf(kick.fp, "%ld, %ld\n", &kick.time, &kick.duration);
			kick.fade_speed = 1.0/kick.duration;
		}
		fwrite(&kick.opacity, sizeof(float), 1, scene);
		if((kick.opacity - kick.fade_speed) > 0.0){
			kick.opacity -= kick.fade_speed;
		}
		if(kick.opacity < OPACITY_THRESHOLD) kick.opacity = 0.0;
		/* snare circle */
		if(i == snare.time){
			snare.opacity = 1.0;
			fscanf(snare.fp, "%ld, %ld\n", &snare.time, &snare.duration);
			snare.fade_speed = 1.0/snare.duration;
		}	
		fwrite(&snare.opacity, sizeof(float), 1, scene);
		if((snare.opacity - snare.fade_speed) > 0.0){
			snare.opacity -= snare.fade_speed;
		}
		if(snare.opacity < OPACITY_THRESHOLD) snare.opacity = 0.0;
		/* clap circle */
		if(i == clap.time){
			clap.opacity = 1.0;
			fscanf(clap.fp, "%ld, %ld\n", &clap.time, &clap.duration);
			clap.fade_speed = 1.0/clap.duration;
		}	
		fwrite(&clap.opacity, sizeof(float), 1, scene);
		if((clap.opacity - clap.fade_speed) > 0.0){
			clap.opacity -= clap.fade_speed;
		}
		if(clap.opacity < OPACITY_THRESHOLD) clap.opacity = 0.0;
		/* hihat circle */
		if(i == hihat.time){
			hihat.opacity = 1.0;
			fscanf(hihat.fp, "%ld, %ld\n", &hihat.time, &hihat.duration);
			hihat.fade_speed = 1.0/hihat.duration;
		}	
		fwrite(&hihat.opacity, sizeof(float), 1, scene);
		if((hihat.opacity - hihat.fade_speed) > 0.0){
			hihat.opacity -= hihat.fade_speed;
		}
		if(hihat.opacity < OPACITY_THRESHOLD) hihat.opacity = 0.0;

		/* Bb3 circle */
		if(i == Bb3.time){
			Bb3.opacity = 1.0;
			fscanf(Bb3.fp, "%ld, %ld\n", &Bb3.time, &Bb3.duration);
			Bb3.fade_speed = 1.0/Bb3.duration;
		}	
		fwrite(&Bb3.opacity, sizeof(float), 1, scene);
		if((Bb3.opacity - Bb3.fade_speed) > 0.0){
			Bb3.opacity -= Bb3.fade_speed;
		}
		if(Bb3.opacity < OPACITY_THRESHOLD) Bb3.opacity = 0.0;
		/* Eb4 circle */
		if(i == Eb4.time){
			Eb4.opacity = 1.0;
			fscanf(Eb4.fp, "%ld, %ld\n", &Eb4.time, &Eb4.duration);
			Eb4.fade_speed = 1.0/Eb4.duration;
		}	
		fwrite(&Eb4.opacity, sizeof(float), 1, scene);
		if((Eb4.opacity - Eb4.fade_speed) > 0.0){
			Eb4.opacity -= Eb4.fade_speed;
		}
		if(Eb4.opacity < OPACITY_THRESHOLD) Eb4.opacity = 0.0;
		/* F4 circle */
		if(i == F4.time){
			F4.opacity = 1.0;
			fscanf(F4.fp, "%ld, %ld\n", &F4.time, &F4.duration);
			F4.fade_speed = 1.0/F4.duration;
		}	
		fwrite(&F4.opacity, sizeof(float), 1, scene);
		if((F4.opacity - F4.fade_speed) > 0.0){
			F4.opacity -= F4.fade_speed;
		}
		if(F4.opacity < OPACITY_THRESHOLD) F4.opacity = 0.0;
		/* A4 circle */
		if(i == A4.time){
			A4.opacity = 1.0;
			fscanf(A4.fp, "%ld, %ld\n", &A4.time, &A4.duration);
			A4.fade_speed = 1.0/A4.duration;
		}	
		fwrite(&A4.opacity, sizeof(float), 1, scene);
		if((A4.opacity - A4.fade_speed) > 0.0){
			A4.opacity -= A4.fade_speed;
		}
		if(A4.opacity < OPACITY_THRESHOLD) A4.opacity = 0.0;

		/* C5 circle */
		if(i == C5.time){
			C5.opacity = 1.0;
			fscanf(C5.fp, "%ld, %ld\n", &C5.time, &C5.duration);
			C5.fade_speed = 1.0/C5.duration;
		}	
		fwrite(&C5.opacity, sizeof(float), 1, scene);
		if((C5.opacity - C5.fade_speed) > 0.0){
			C5.opacity -= C5.fade_speed;
		}
		if(C5.opacity < OPACITY_THRESHOLD) C5.opacity = 0.0;
		/* D5 circle */
		if(i == D5.time){
			D5.opacity = 1.0;
			fscanf(D5.fp, "%ld, %ld\n", &D5.time, &D5.duration);
			D5.fade_speed = 1.0/D5.duration;
		}	
		fwrite(&D5.opacity, sizeof(float), 1, scene);
		if((D5.opacity - D5.fade_speed) > 0.0){
			D5.opacity -= D5.fade_speed;
		}
		if(D5.opacity < OPACITY_THRESHOLD) D5.opacity = 0.0;
	}
	fclose(kick.fp);
	fclose(snare.fp);
	fclose(clap.fp);
	fclose(hihat.fp);
	fclose(scene);
	fclose(A4.fp);
	fclose(Bb3.fp);
	fclose(C5.fp);
	fclose(D5.fp);
	fclose(Eb4.fp);
	fclose(F4.fp);
	return 0;
}
