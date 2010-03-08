#! /bin/python

# SOUND _ FALL
# A game where you place sound. Written in Python with Pygame.
#    Copyright (C) 2010  Chris Thompson (http://www.stipes.org)

#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.

#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.

#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.

import os, os.path, sys, time, math
import pygame
from pygame.locals import *

if not pygame.mixer: print "No sound system detected."
pygame.mixer.init(44100)

# initialize sound objects
collissionSound = pygame.mixer.Sound(os.path.join("sounds","collission.wav"))
sounds = [
pygame.mixer.Sound(os.path.join("sounds","0.wav")),
pygame.mixer.Sound(os.path.join("sounds","1.wav")),
pygame.mixer.Sound(os.path.join("sounds","2.wav")),
pygame.mixer.Sound(os.path.join("sounds","3.wav")),
pygame.mixer.Sound(os.path.join("sounds","4.wav")),
pygame.mixer.Sound(os.path.join("sounds","5.wav")),
pygame.mixer.Sound(os.path.join("sounds","6.wav")),
pygame.mixer.Sound(os.path.join("sounds","7.wav")),
pygame.mixer.Sound(os.path.join("sounds","8.wav")),
pygame.mixer.Sound(os.path.join("sounds","9.wav")),
pygame.mixer.Sound(os.path.join("sounds","10.wav")),
pygame.mixer.Sound(os.path.join("sounds","11.wav")),
pygame.mixer.Sound(os.path.join("sounds","12.wav")),
pygame.mixer.Sound(os.path.join("sounds","13.wav")),
pygame.mixer.Sound(os.path.join("sounds","14.wav")),
pygame.mixer.Sound(os.path.join("sounds","15.wav")),
pygame.mixer.Sound(os.path.join("sounds","16.wav")),
pygame.mixer.Sound(os.path.join("sounds","17.wav")),
pygame.mixer.Sound(os.path.join("sounds","18.wav")),
pygame.mixer.Sound(os.path.join("sounds","19.wav")),
pygame.mixer.Sound(os.path.join("sounds","20.wav")),
pygame.mixer.Sound(os.path.join("sounds","21.wav")) ]

def pan(x=0, y=0, d=2):
    "Basic 2D panning with 3D attenuation."
    
    # we use a constant power of 1 for the pan, so strong L/R differentiation
    left = .5
    right = .5
    
    # basic conversion of grid to space for the pan using lower part of cosine
    # means that at x=12 -> right=1 left = 0
    # and at x=0 -> right=0 left=1
    diff = 0
    # direction to pan
    if (x - 6) < 0:
        diff = math.cos( (x-6)*math.pi/12 - math.pi/2) * 0.5
        left -= diff
        right += diff
    elif (x - 6) > 0:
        diff = math.cos( (x-6)*math.pi/12 + math.pi/2) * 0.5
        left += diff
        right -= diff
    
    return left, right

class Piece:
    "Maintains a piece."
    global sounds, collissionSound
    def __init__(self, xstart=6, ystart=21, dist=2):
        # position on grid
        self.xpos = xstart
        self.ypos = ystart
        self.zpos = dist
        self.source = pygame.mixer.Channel(0)
        self.collission = pygame.mixer.Channel(1)
        # position in space
        #((xstart - 6) * 0.2 , ystart * 0.1, dist)
        left, right = pan(xstart, dist)
        self.source.set_volume(left, right)
        self.collission.set_volume(left,right)
        self.source.play(sounds[ystart], 0) # start, don't loop
    
    def move(self, dir, board):
        # Check the move, update on grid
        # Collission detecting only works on move,
        # so a new piece can start inside an old piece
        
        self.source.stop()
        
        if dir == 'l':
            if self.xpos <= 0:
                self.collission.play(collissionSound)
            elif board.grid[self.xpos - 1][21 - self.ypos]:
                self.collission.play(collissionSound)
            elif self.xpos > 0:
                self.xpos -= 1
        
        if dir == 'r':
            if self.xpos >= 12:
                self.collission.play(collissionSound)
            elif board.grid[self.xpos + 1][21 - self.ypos]:
                self.collission.play(collissionSound)
            elif self.xpos < 12:
                self.xpos += 1
        
        if dir == 'u':
            if self.ypos >= 21:
                self.collission.play(collissionSound)
            elif board.grid[self.xpos][21 - (self.ypos + 1)]:
                self.collission.play(collissionSound)
            elif self.ypos < 21:
                self.ypos += 1
        
        if dir == 'd':
            if self.ypos <= 0:
                self.collission.play(collissionSound)
            elif board.grid[self.xpos][21 - (self.ypos - 1)]:
                self.collission.play(collissionSound)
            elif self.ypos > 0:
                self.ypos -= 1
        
        self.source.stop()
        
        # Play the new "height" of the sound
        self.source.play(sounds[self.ypos], 0)
        
        # Update the panning
        left, right = pan(self.xpos, self.ypos, self.zpos)
        self.source.set_volume(left, right)
        self.collission.set_volume(left, right)
        
        time.sleep(0.1)
    
    def place(self):
        self.source.stop()

class Board:
    "Maintain state of top-down grid."
    def __init__(self, width=13, height=22):
        # grid[x][y]
        self.grid = [[0] * height for i in xrange(width)]
    
    def toggleSquare(self, x, y):
        self.grid[x][21 - y] = not self.grid[x][21 - y]
        
    def display(self, piece):
        print ''
        for i,row in enumerate(zip(*self.grid)):
            print '| ',
            for j,square in enumerate(row):
                if square: print ' X ',
                elif (21-i == piece.ypos and j == piece.xpos): print ' X ',
                else: print '   ',
            print ' |'
        print ''

def main():
    pygame.init()
    
    # Set up screen with instructions
    screen = pygame.display.set_mode((480,300))
    pygame.display.set_caption('SOUND_FALL')
    pygame.mouse.set_visible(0)
    title = pygame.image.load("title.png")
    title = title.convert()
    screen.blit(title, (0,0))
    pygame.display.flip()
    
    board = Board()
    piece = Piece()
    
    while 1:
        # GAME LOOP
        
        # get input -- NOTE: we only listen to keydowns currently
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                return
            if event.type == KEYDOWN:
                if event.key == K_ESCAPE:
                    pygame.quit()
                    return
                elif event.key == K_UP:
                    piece.move('u',board)
                    
                elif event.key == K_DOWN:
                    piece.move('d',board)
                    
                elif event.key == K_LEFT:
                    piece.move('l',board)
                    
                elif event.key == K_RIGHT:
                    piece.move('r',board)
                    
                elif event.key == K_SPACE:
                    piece.place()
                    board.toggleSquare(piece.xpos, piece.ypos)
                    piece = Piece()
                    
                elif event.key == K_RETURN:
                    board.display(piece)
    pygame.quit()
    
if __name__ == '__main__': main()
