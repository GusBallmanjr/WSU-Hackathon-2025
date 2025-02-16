/*
	Programmers: Jayden Claytor and Gus Ballman
	Date: 2/15/2025
	Event: WSU 2025 Hackathon
	Description: This program prompts the ser to chose a number from 1 to 9 and then displays a corresponding Julia Set fractal.
	These fractals can be zoomed in and out on using the mouse. This project is to represent how fractals are very beautifully visually and mathmatically.
*/

#include "hackathon.h"

int main(void)
{
	InitWindow(Screenwidth, Screenheight, "Julia Set");
	SetTargetFPS(60);

	int iteration = 0;
	float z_real = 0.0, z_imag = 0.0;
	_Fcomplex C = { 0.0, 0.0 }; //Determines which Julia Set Fractile is used
	Vector2 origin = { Screenwidth / 2, Screenheight / 2 };

	C = get_choice();

    float C_real = crealf(C);
    float C_imag = cimagf(C);

	Camera2D camera = { 0 };
	camera.target = (Vector2){ Screenheight / 2.0f, Screenheight / 2.0f }; // Center camera
	camera.offset = (Vector2){ Screenwidth / 2.0f, Screenheight / 2.0f }; // Offset screen centering
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		DrawText(TextFormat("Zoom: %.5f", camera.zoom), 10, 10, 30, RAYWHITE);
        DrawText(TextFormat("Hold left click to zoom in\nHold right click to zoom out\nMay lag a bit, Sorry for the Inconvenience", camera.zoom), 15, Screenheight-70, 20, RAYWHITE);

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) // zoom in left-click
        {
			Vector2 mousePos = GetMousePosition();

			Vector2 worldPos = GetScreenToWorld2D(mousePos, camera);

            camera.target = worldPos; // Zoom into clicked point

			camera.zoom *= 2.5; // Zoom in

        }

        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) // zoom out right-click 
        {
			Vector2 mousePos = GetMousePosition();

			Vector2 worldPos = GetScreenToWorld2D(mousePos, camera);
			
			camera.target = worldPos;

			camera.zoom /= 2.5; // Zoom out

        }

        BeginMode2D(camera); // Begin 2D drawing with camera

		for (int x = 0; x < Screenwidth; x++)
		{
			for (int y = 0; y < Screenheight; y++)
			{
				Vector2 worldPos = GetScreenToWorld2D((Vector2) { x, y }, camera);

				int iteration = 0;
				z_real = (x - origin.x) * SCALE; //Sets up x-axis (real axis) in complex plane
				z_imag = (y - origin.y) * SCALE; //Sets up y-axis (imaginary) in complex plane
				while (z_real * z_real + z_imag * z_imag <= 4.0 && iteration < max_iteration) //Prevents redundant calculations and stops the program when fractal is designed
				{
					float real = build_julia_set_x_values(z_real, z_imag, C);
					float imag = build_julia_set_y_values(z_real, z_imag, C);
					z_real = real;
					z_imag = imag;
					iteration++;
				}
				if (iteration < max_iteration) //The changing of the color allows the fractal to be seen.
				{
					Color color = (Color){ (iteration * 10) % 200, (iteration * 5) % 255, (iteration * 2) % 255, 200 };
					DrawPixel(x, y, color);
				}
			}
		}
		EndMode2D();
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
