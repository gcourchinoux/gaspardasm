# What is gaspardasm ? 



I have designed gaspardasm to have a great and powerful emulator for gaspard architecture. 


Now, It can emule gaspard architecture on the future gaspardasm will be able to assemble gaspard instructions. 



It's wrote in c++. 

The design is very simple. Everybody can understand it. We have a very low number of c++ classes. 

# building. 


## if you are using microsoft windows. 


Be sure to have microsoft visual c++ and visual studio 2022 installed. 

double click on gaspardasm.sln, it will open visual studio. 

You can compile it just from visual studio. 


## if you are using Linux ,BSD,Macos 

Be sure to have cmake install and clang and/or g++

Code : 

```
mkdir build 
cd build 
cmake ..
make -j4
```

# running 

as say before gaspardasm is only available to run asm code generate by gcc or you !  

It takes only one argument at the moment : the filename of the assembly file. 

In the future I will write the code to compile instruction to elf file. 

# internals


We have the main.cpp file. This file is parsing the invocation  arguments list and init the Assembleur class. 

Assembleur is the class that build the token list and the ast. 

First at all, the code build the token list. 

After that , the program creates a list of token that  will be analyze by the toke scanner (scan_tok()). 

After analyze (the analyzer uses the tree struture see Assembleur.h for more info) the code is execute using the scan_ast() function. 

The scan_ast() function uses execute() to execute code. 

Now, see the Memory class. 

THe memory class emule a processor's MMU . 
It is pretty simple to understand. 

When this class is called, only set_memory() method need to be call to allocate 'physical' memory. 

The code of memory need to be tested tested and tested because I don't know his behaviour in all situations. 




# TODO and what is not working list. 


## todo: 


* Test and test memory. 
* make test about jmp instructions 
* GNU assmbly instruction , I have writted the code to handle it but nothing is taked. 
* create a test directory with all the test assembly code from gcc. 
* pci , screen , ethernet,hardrive , cdrom ,keyboard , mouse
## not working 


*perhaps the memory when pagination is enabled because the child child[] (in struct page_table)  is pretty awfull. Need to be tested ! 

# Copyright 

Copyright (C) 2022 Gaspard COURCHINOUX all right reserved. 

See COPYING for license. 