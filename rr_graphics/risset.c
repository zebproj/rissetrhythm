#include <cairo/cairo.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

#define HEIGHT 300
#define WIDTH 400
//#define FRAMES 1

void drawCircle(cairo_t *cr, float x, float y, float size, float color[3], float a);
void frame(cairo_surface_t *surface, cairo_t *cr, 
		int colorState[10], float alphaState[10]);
void hex2float(int color, float *colorSpace);
int 
main(int argc, char *argv[])
{
	cairo_surface_t *surface;
	cairo_t *cr;
	int colorState[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1};
	float alphaState[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	float state_1;	
	FILE *scene = fopen("../scene.bin", "rb");
	int i = 0;
	int circles = 10;
	for(i = 0; i < FRAMES; i++){
		fread(alphaState, sizeof(float), circles, scene);
		surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, WIDTH, HEIGHT);
		cr = cairo_create(surface);
		char png_filename[50];
		sprintf(png_filename, "risset_%05d.png", i);
		printf("printing frame %i...\n", i);
		frame(surface, cr, colorState, alphaState);
		cairo_surface_write_to_png (surface, png_filename);
		cairo_destroy (cr);
		cairo_surface_destroy (surface);
	}



	return 0;
}

void drawCircle(cairo_t *cr, float x, float y, float size, float color[3], float a)
{
	cairo_arc(cr, x, y, size, 0, 2 * M_PI);
	cairo_set_source_rgba (cr, color[0], color[1], color[2], a);
	cairo_fill(cr);
}

void hex2float(int color, float *colorSpace)
{
	int r = color >> 0x10;
	int g = color - (r << 0x10) >> 0x8;
	int b = color - ((r << 0x10) + (g << 0x8));

	*(colorSpace) = r/255.0;
	*(colorSpace + 1) = g/255.0;
	*(colorSpace + 2) = b/255.0;
}
void frame(cairo_surface_t *surface, cairo_t *cr, 
		int colorState[10], float alphaState[10])
{
	float scale = WIDTH/5.0;
	float offset = scale * 0.5;
	float h_offset = (HEIGHT * 0.5) - offset;
	float bg[3], c1[3], c2[3];

	hex2float(0x1a1110, bg); /*Licorice for background*/
	hex2float(0x4cbb17, c1); /*Kelly Green for Circle 1*/
	hex2float(0xe49b0f, c2); /*Gamboge for Circle 2*/
	cairo_set_source_rgb (cr, bg[0],bg[1],bg[2]);
	cairo_paint(cr);
	int i, j;	
	for(j = 0; j < 2; j++){
		for(i = 0; i < 5; i++){
			if(colorState[j * 5 + i] == 0){
				drawCircle(cr, 
						offset + i * scale, 
						h_offset + j * scale, 
						HEIGHT/8, c2, alphaState[j * 5 + i]);
			}else{
				drawCircle(cr, 
						offset + i * scale, 
						h_offset + j * scale, 
						HEIGHT/8, c1, alphaState[j * 5 + i]);
			}
		}
	}


}
