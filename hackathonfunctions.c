/*
	Programmers: Jayden Claytor and Gus Ballman
	Date: 2/15/2025
	Event: WSU 2025 Hackathon
	Description: This program prompts the ser to chose a number from 1 to 9 and then displays a corresponding Julia Set fractal. 
	These fractals can be zoomed in and out on using the mouse. This project is to represent how fractals are very beautifully visually and mathmatically.
*/

#include "hackathon.h"

float build_julia_set_x_values(float z_real, float z_imag, _Fcomplex C)
{
	return ((z_real * z_real) - (z_imag * z_imag)) + crealf(C); //Produces real part of new complex number
}

float build_julia_set_y_values(float z_real, float z_imag, _Fcomplex C)
{
	return (2 * z_real * z_imag) + cimagf(C); //Produces imaginary part of complex number
}

_Fcomplex get_choice(void)
{
	int option = 0, mode = 0;
	_Fcomplex C = { 0.0, 0.0 };

	while (mode != 1)
	{
		if (IsKeyPressed(KEY_ONE)) option = 1;
		if (IsKeyPressed(KEY_TWO)) option = 2;
		if (IsKeyPressed(KEY_THREE)) option = 3;
		if (IsKeyPressed(KEY_FOUR)) option = 4;
		if (IsKeyPressed(KEY_FIVE)) option = 5;
		if (IsKeyPressed(KEY_SIX)) option = 6;
		if (IsKeyPressed(KEY_SEVEN)) option = 7;
		if (IsKeyPressed(KEY_EIGHT)) option = 8;
		if (IsKeyPressed(KEY_NINE)) option = 9;

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("\t\t Fractals All Around!", 50, 100, 50, YELLOW);
		DrawText("\n\nPlease press a number 1 through 9 to select a fractal.\n\n\t\t\t\t\t\t\t\t\tThis may take a moment to load.", 50, 100, 25, WHITE);

		if (option < 10 && option > 0)
		{

			char a[50];
			sprintf(a, "You selected option: %d!", option);
			DrawText(a, 50, 300, 50, WHITE);
		}
		EndDrawing();

		switch (option)
		{
		case 1:
			C = (_Fcomplex){ -0.972, -0.136 };
			mode = 1;
			break;
		case 2:
			C = (_Fcomplex){ -1.0, 0.0 }; //The Dendrite
			mode = 1;
			break;
		case 3:
			C = (_Fcomplex){ -0.123, .745 };
			mode = 1;
			break;
		case 4:
			C = (_Fcomplex){ .45, .1428 };
			mode = 1;
			break;
		case 5:
			C = (_Fcomplex){ -.835, -.2321 }; //Gus' favorite fractal
			mode = 1;
			break;
		case 6:
			C = (_Fcomplex){ -.7269, .1889 };
			mode = 1;
			break;
		case 7:
			C = (_Fcomplex){ 0, -1 };
			mode = 1;
			break;
		case 8:
			C = (_Fcomplex){ -0.4, 0.6 };
			mode = 1;
			break;
		case 9:
			C = (_Fcomplex){ .36, 1.0 }; //The Dragon
			mode = 1;
			break;
		}
	}
	ClearBackground(BLACK);
	return C;
}