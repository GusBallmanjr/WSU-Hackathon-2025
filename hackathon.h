/*
	Programmers: Jayden Claytor and Gus Ballman
	Date: 2/15/2025
	Event: WSU 2025 Hackathon
	Description: This program prompts the ser to chose a number from 1 to 9 and then displays a corresponding Julia Set fractal.
	These fractals can be zoomed in and out on using the mouse. This project is to represent how fractals are very beautifully visually and mathmatically.
*/

#ifndef HACKATHON_H
#define HACKATHON_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define Screenwidth 800
#define Screenheight 600
#define SCALE 0.004
#define max_iteration 40

float build_julia_set_x_values(float z_real, float z_imag, _Fcomplex C);
float build_julia_set_y_values(float z_real, float z_imag, _Fcomplex C);
_Fcomplex get_choice(void);

#endif

