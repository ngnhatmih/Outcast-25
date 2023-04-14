import sdl2, sdl2.ext
from Vector2D import *
from TextureManager import *

class GameObject:

    # Create object
    def __init__(self, textureID, x, y, w, h, scale, numFrames, game):
        self.textureID, self.rect, self.scale, self.numFrames = textureID, (x, y, w, h), scale, numFrames
        self.game = game
        # Position and velocity of the object
        self.pos = Vector2D([x,y])
        self.vel = Vector2D([0,0]) 
        # Current row and frame of the object's animation
        self.curRow = 0
        self.curFrame = 0 

    # Draw animation of the object
    def draw(self):
        TextureManager().drawFrame(self.game.getRenderer(), self.textureID, *self.rect, self.scale, self.curFrame, self.curRow)

    # Update its position and rectangle
    def update(self): 
        self.pos += self.vel
        self.rect = (self.pos.getX(), self.pos.getY(), self.rect[2], self.rect[3])

    def clean(self):
        pass

    # Get rectangle's width
    def getW(self): return self.rect[2]

    # Get rectangle's height
    def getH(self): return self.rect[3]

    # Get object's position
    def getPos(self)->Vector2D: return self.pos

    # Get texture ID
    def getTextureID(self)->str: return self.textureID

    # Check if the position of vec is in rectangle
    def checkCollision(self, vec: Vector2D)->bool:
        # (x_0 y_0) < (x y) < (x_0+width y_0+height)
        if (vec.getX() > self.pos.getX()
            and vec.getX() < self.pos.getX() + self.getW()*self.scale 
            and vec.getY() > self.pos.getY()
            and vec.getY() < self.pos.getY() + self.getH()*self.scale):
            return True
            
        else: return False

