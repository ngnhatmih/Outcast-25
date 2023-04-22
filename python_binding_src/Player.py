from GameObject import *
from Constant import *
from InputHandler import InputHandler

class Singleton(type):
    instances = {}
    def __call__(self, *args, **kwds):
        if self not in self.instances:
            instance = super().__call__(*args, **kwds)
            self.instances[self] = instance
        return self.instances[self]

class Player(GameObject, metaclass = Singleton):

    def __init__(self, textureID, w, h, scale, numFrames, game):
        self.pos = Vector2D(CENTER)
        self.vel = Vector2D([0,0])
        self.accel = Vector2D([2,0])
        self.curFrame = 0
        self.curRow = 0
        super().__init__(textureID, self.pos.getX(), self.pos.getY(), w, h, scale, numFrames, game)
        TextureManager().load("assets/textures/adventurer-v1.5-Sheet.png", "Player", game.getRenderer())

    def update(self):
        self.pos += self.vel
        self.rect = (self.pos.getX(), self.pos.getY(), self.getW(), self.getH())

    def draw(self):
        return super().draw()

    def clean(self):
        return super().clean()
        