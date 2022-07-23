/*
manage screen with opengl
Copyright (C) 2022 Gaspard COURCHINOUX

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.


*/

#pragma once
#include <GLFW/glfw3.h>

/*

Faire le vga 
et le rendu dans une fenetre windows 


0x300 est l'adresse de dépot des instructions 
0x
300 contient un pointeur vers la stryctyre pixel par exmeple

*/
struct pixel {

	unsigned char mode : 4; // toute les structures commence par cela afin qu'on puisse les reconnaitre 

	unsigned long x; 
	unsigned long y; 

	unsigned char pix[2]; // valeur du pixel en rgv posible 3*8=24 bits

};
class Vga
{
public:
	void thread_video();
	// init de la fenetre  
	void init();
	void end();
	// quand il y a mise à jour des pixels 
	bool update_pixel(void *data); 

	void update(void *data);
	GLFWwindow* window;
	int actual_x; 
	int actual_y;
	unsigned char actual_pix[2];

private: 
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouse_callback(GLFWwindow* window, double xpos, double ypos);

	/*
	Pointeur contenant les informations des pixels et des couleurs
	https://registry.khronos.org/OpenGL-Refpages/gl2.1/xhtml/glDrawPixels.xml
	*/
	unsigned char* screen;
};

