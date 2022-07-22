/*
manage screen with opengl
Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/
#include "Vga.h"
#include <iostream>
#include <thread>
#define WIDTH 640
#define HEIGHT 480
void Vga::thread_video() {

	if (!glfwInit())
	{

	}

	window = glfwCreateWindow(WIDTH, HEIGHT, "gaspardasm (OpenGl)", nullptr, nullptr);
	if (!window)
	{
	}
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	glfwSetKeyCallback(window, Vga::key_callback);
	glfwSetCursorPosCallback(window, Vga::mouse_callback);

	while (!glfwWindowShouldClose(window))
	{


		//glClearColor(1.0, 1.0, 1.0, 1.0);  
		glClear(GL_COLOR_BUFFER_BIT);
		glRasterPos2f(-1, -1);  
		glDrawPixels(WIDTH, HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, pixels); //draw pixel


		glfwSwapBuffers(window);
		glfwPollEvents();

	}


}
 void Vga::mouse_callback(GLFWwindow* window, double xpos, double ypos)
{

// faire une interruption 

}
/*
Initialiser fenetre avec libsdl 
*/
void Vga::init()
{


	
	std::thread th_video(&Vga::thread_video,this);
	th_video.detach();
}
void Vga::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	std::cout << " touche " << std::endl;
	// fair eune interruption
}

void Vga::end() {

	glfwTerminate();


}

/*

TODO rajouter dans le cjhamp de pixel le pixel ainsi que sa couleur faire l'api windowss
*/
bool Vga::update_pixel(void* data)
{

	struct pixel* pix = (struct pixel*)data; 


	return false;
}

void Vga::update(void* data)
{
	struct pixel* tmp_pixel = (struct pixel*)data; 



	switch (tmp_pixel->mode)
	{
	case 0b1: update_pixel(tmp_pixel);  break;
		/*
		TODO faireles autres modes de communication
		*/

	default:
		break;
	}


}
