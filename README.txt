SOUND _ FALL

-------------------------------
Created by Chris Thompson
http://www.stipes.org/

Weekly Challenge #1: NON_VISUAL
V1.0 - 8 March 2010
-------------------------------

## WHAT YOU'LL NEED:

 - Python (http://www.python.org/, tested in Version 2.6)
 - Pygame (http://www.pygame.org/)
 - Headphones

## HOW TO PLAY:

Navigate to where you unpacked the game files with your terminal of choice.
To run the game from the folder, type:

  python soundfall.py

This will open a window with instructions. Some output may be printed to the
terminal as well.

The arrow keys move the sound block around the grid. The space bar places the
sound block and starts a new sound. ESCAPE exits the game.

(to cheat, or to make sure you're on the right course, press ENTER to 
print the grid to the terminal.)

Note: Pygame is not included in this distribution. Due to the use of the 
terminal, I am not able to convert this to a .EXE for Windows users.

## LICENSE:

Sound _ Fall
Copyright (C) 2010  Chris Thompson

This game and its included resources are available under the 
GNU PUblic License V3. See LICENSE.txt for more information.

Basically, you may use this however you want, as long as you make your
addittions open. I particularly hope that if you use it, you do something cool.
If you do, tell me about it! I'd also be cool with a small attribution line.

If you want to use this in a different way (non-GPL), get in touch.

## ACKNOWLEDGEMENTS:

Making this game work was harder than I thought. I jumped between OpenAL, CLAM,
cSound, and many other systems. Most were ridiculously hard to get working
with Python in Linux (CLAM, SuperCollider, PyOpenAL, etc.) or not quite the
right tool for the job (cSound, which I still love). I ended up building a 
custom panning system that sits on top of Pygame.Mixer. You can find out more
about PyGame at pygame.org.

Sound samples were created in Audacity, and images were created in GIMP.
