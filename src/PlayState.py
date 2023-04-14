from GameState import *
from TextureManager import *
from InputHandler import *
from Player import *

class PlayState(GameState):
    # State ID
    playID = "PLAY"

    # Pass game instance to avoid circular import
    def __init__(self, game) -> None:
        self.game = game
        self.g_Objects:GameObject = {}

    # Update all objects in play states
    def update(self):
        for value in self.g_Objects.values():
            value.update()
            
        self.game.renderer.present()
        self.game.window.show()

    # Draw objects
    def render(self):
        self.game.renderer.clear()
        self.game.getRenderer().color = sdl2.ext.Color(*Colors.GRAY.value)

        for value in self.g_Objects.values():
            value.draw()

    # Trigger this event when joinin this play state
    def onEnter(self) -> bool:
        self.g_Objects["Player"] = Player("Player", 50, 37, 2.0, 3, self.game)
        print("Entering play state...")
        return True

    # Trigger this event when leavin this play state
    def onExit(self) -> bool:
        for value in self.g_Objects.values():
            value.clean()

        print("Exiting play state...")
        return True
    
    def onKeyDown(self, event: sdl2.SDL_Event):
        if InputHandler().isKeyDown(sdl2.SDL_SCANCODE_D) and InputHandler().isKeyDown(sdl2.SDL_SCANCODE_A):
            self.g_Objects["Player"].vel = Vector2D([0,0])
            self.g_Objects["Player"].curFrame = 0
            self.g_Objects["Player"].curRow = 0
        elif InputHandler().isKeyDown(sdl2.SDL_SCANCODE_D):
            self.g_Objects["Player"].vel += self.g_Objects["Player"].accel
            if self.g_Objects["Player"].accel != Vector2D([0,0]):
                self.g_Objects["Player"].accel -= Vector2D([0.1, 0])
        elif InputHandler().isKeyDown(sdl2.SDL_SCANCODE_A):
            if self.g_Objects["Player"].vel.getX() > 0:
                self.g_Objects["Player"].vel = -self.g_Objects["Player"].vel
            self.g_Objects["Player"].vel -= self.g_Objects["Player"].accel
            if self.g_Objects["Player"].accel != Vector2D([0,0]):
                self.g_Objects["Player"].accel -= Vector2D([0.1, 0])
        

    def onKeyUp(self, event: sdl2.SDL_Event):
        self.g_Objects["Player"].vel = Vector2D([0,0])
        self.g_Objects["Player"].accel = Vector2D([2,0])
        self.g_Objects["Player"].curFrame = 0
        self.g_Objects["Player"].curRow = 0

    def onMouseButtonDown(self, event: sdl2.SDL_Event):
        pass

    def onMouseButtonUp(self, event: sdl2.SDL_Event):
        pass

    def onMouseMove(self, event: sdl2.SDL_Event):
        pass

    def getStateID(self) -> str:
        return self.playID