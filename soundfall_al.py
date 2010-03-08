#! /bin/python

# yay

import os, os.path, sys, time
#import pprint
import pyopenal
import pygame
from pygame.locals import *

#pp = pprint.PrettyPrinter(indent=2)

pyopenal.init(None)
l = pyopenal.Listener(44100)
#             x    y    z
l.position = (0.0, 0.0, 0.0) # at origin
l.at       = (0.0, 0.0, -1.0) # facing z = -1 (into screen)
l.up       = (0.0, 1.0, 0.0) # y=1 is our "up"

# we build an array of buffers to house the vertical "positions"
buf = [
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "0.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "1.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "2.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "3.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "4.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "5.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "6.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "7.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "8.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "9.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "10.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "11.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "12.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "13.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "14.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "15.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "16.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "17.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "18.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "19.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "20.wav")),
pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "21.wav"))  ]

colbuf = pyopenal.WaveBuffer(os.path.join(os.path.dirname(sys.argv[0]), "sounds", "collission.wav"))

class Piece:
    "Maintains a piece."
    global buf, colbuf
    def __init__(self, xstart=6, ystart=21, dist=2):
        # position on grid
        self.xpos = xstart
        self.ypos = ystart
        self.zpos = dist
        self.source = pyopenal.Source()
        # position in space
        self.source.position = ((xstart - 6) * 0.2 , ystart * 0.1, dist)
        self.source.velocity = (0.0, 0.0, 0.0)
        self.source.buffer = buf[ystart]
        self.source.looping = 0
        self.source.play()
        
        # collission source
        self.col = pyopenal.Source()
        self.col.position = self.source.position
        self.col.buffer = colbuf
        self.source.looping = 0
    
    def move(self, dir, board):
        # Check the move, update on grid
        # Need to add collission checking with prior pieces
        if dir == 'l':
            print self.xpos
            print self.ypos
            if self.xpos <= 0: self.col.play()
            elif board.grid[self.xpos - 1][self.ypos]:
                self.col.play()
                return
            elif self.xpos > 0: self.xpos -= 1
        
        if dir == 'r':
            print self.xpos
            print self.ypos
            if self.xpos >= 11: self.col.play()
            elif board.grid[self.xpos + 1][self.ypos]: self.col.play()
            elif self.xpos < 11: self.xpos += 1

        
        if dir == 'u':
            print self.xpos
            print self.ypos
            if self.ypos >= 21: self.col.play()
            elif board.grid[self.xpos][self.ypos + 1]: self.col.play()
            elif self.ypos < 21: self.ypos += 1
        
        if dir == 'd':
            print self.xpos
            print self.ypos
            if self.ypos <= 0: self.col.play()
            elif board.grid[self.xpos][self.ypos - 1]: self.col.play()
            elif self.ypos > 0: self.ypos -= 1
        
        # Change buffer to change the "height" of the sound
        self.source.buffer = buf[self.ypos]
        # Update the 3d position
        self.source.position = ((self.xpos - 6) * 0.2, self.ypos * 0.1, self.zpos)
        
        self.source.play()
        
        self.col.position = self.source.position
        
        time.sleep(2)
    
    def place(self):
        self.source.stop()

class Board:
    "Maintain state of top-down grid."
    def __init__(self, width=12, height=22):
        # grid[x][y]
        self.grid = [[0] * height for i in xrange(width)]
    
    def toggleSquare(self, x, y):
        self.grid[x][21 - y] = not self.grid[x][21 - y]
        
    def display(self, piece):
#        gridCopy = deepcopy(self.grid)
#        gridCopy[piece.xpos, piece.ypos] = True
#        for row, i in enumerate(gridCopy):
#            for square, j in enumerate(row):
#                if square: gridCopy[i][j] = 'X'
#                else: gridCopy[i][j] = ' '
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
    # Set up for game
    
    pygame.init()
    
    # Do I need a screen to catch input? Fine.
    
    screen = pygame.display.set_mode((480,300))
    pygame.display.set_caption('SOUND_FALL')
    pygame.mouse.set_visible(0)
    # write some instructions to this screen?
    
    
    # Play an intro bit? Verbal tutorial with training for
    # TOP and BOTTOM, left/right, etc?
    
    board = Board()
    piece = Piece()
    
    # make sure that the piece CAN enter?
    #board.enterPiece(piece)
    
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
        
        
    
    # End of game procedure
    
if __name__ == '__main__': main()
