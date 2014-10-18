
#include "Iw2D.h"



int main()

{

	// Initialise the 2D graphics system

	Iw2DInit();

	// Create an image from a PNG file

	CIw2DImage* image = Iw2DCreateImage("textures/foto_klein.png");

	// Loop forever, until the user or the OS performs some action to quit the app

	while (!s3eDeviceCheckQuitRequest())

	{

		// Clear the drawing surface

		Iw2DSurfaceClear(0xff000000);



		// Draw an image

		Iw2DDrawImage(image, CIwFVec2::g_Zero);

		// Show the drawing surface

		Iw2DSurfaceShow();



		// Yield to the OS

		s3eDeviceYield(0);

	}



	// Clean-up
	delete image;
	Iw2DTerminate();



	return 0;

}
