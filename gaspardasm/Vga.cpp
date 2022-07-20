#include "Vga.h"
/*
Initialiser fenetre 
*/
void Vga::init()
{
}
/*

TODO rajouter dans le cjhamp de pixel le pixel ainsi que sa couleur faire l'api windowss
*/
bool Vga::update_pixel(void* data)
{
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
