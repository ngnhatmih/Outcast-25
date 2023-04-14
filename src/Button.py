from GameObject import *
from Constant import *
from InputHandler import InputHandler

class Button(GameObject):
    
    def __init__(self, textureID, x, y, w, h, scale, game):
        # Is the button released?
        self.released = True
        # Current state of the button
        self.curFrame = ButtonStates.BUTTON_OUT.value
        super().__init__(textureID, x, y, w, h, scale, 3, game)

        # Load button textures
        TextureManager().load("assets/textures/PlayButton.png", "PlayButton", game.getRenderer())
        TextureManager().load("assets/textures/ExitButton.png", "ExitButton", game.getRenderer())

    def update(self):
        if self.checkCollision(InputHandler().getMousePos()):
            # Change current frame of the button if the mouse is hoverin on it
            self.curFrame = ButtonStates.BUTTON_OVER.value
            
            # If the left mouse button is pressed
            if InputHandler().getMouseButtonState(MouseButtons.LEFT.value):
                self.released = False
                # Change current frame of the button if the mouse click to it
                self.curFrame = ButtonStates.BUTTON_DOWN.value

            else: self.released = True
            
        else:
            # Otherwise
            self.curFrame = ButtonStates.BUTTON_OUT.value

    def draw(self):
        super().draw()    

    def clean(self):
        super().clean()            