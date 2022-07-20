#pragma once

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
	// init de la fenetre  
	void init();
	// quand il y a mise à jour des pixels 
	bool update_pixel(void *data); 


};

