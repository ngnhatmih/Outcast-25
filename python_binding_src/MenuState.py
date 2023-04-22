from GameState import *
from TextureManager import *
from InputHandler import *
from Button import *
from PlayState import PlayState

class MenuState(GameState):
    # State ID
    menuID = "MENU"

    # Pass game instance to avoid circular import
    def __init__(self, game) -> None:
        self.game = game
        self.gameObjects:GameObject = {}

    # Update all objects in menu states
    def update(self):
        for value in self.gameObjects.values():
            value.update()
            
        self.game.renderer.present()
        self.game.window.show()

    # Draw objects
    def render(self):
        self.game.renderer.clear()
        self.game.getRenderer().color = sdl2.ext.Color(*Colors.GREEN.value)

        for value in self.gameObjects.values():
            value.draw()

    # Trigger this event when joinin this menu state
    def onEnter(self) -> bool:
        print("Entering menu state...")
        self.gameObjects["PlayButton"] = Button("PlayButton", 100, 100, 100, 50, 1.0, self.game)
        self.gameObjects["ExitButton"] = Button("ExitButton", 100, 190, 100, 50, 1.0, self.game)
        return True

    # Trigger this event when leavin this menu state
    def onExit(self) -> bool:
        for value in self.gameObjects.values():
            value.clean()

        print("Exiting menu state...")
        return True
    
    def onKeyDown(self, event: sdl2.SDL_Event):
        pass

    def onKeyUp(self, event: sdl2.SDL_Event):
        pass

    def onMouseButtonDown(self, event: sdl2.SDL_Event):
        pass

    def onMouseButtonUp(self, event: sdl2.SDL_Event):
        # If the play button is clicked
        if self.gameObjects["PlayButton"].released == False:
            self.game.getGameStateMachine().changeState(PlayState(self.game))

        # If the exit button is clicked
        elif self.gameObjects["ExitButton"].released == False:
            self.onExit()
            self.game.isRunning = False

        # If the exit button is clicked
        elif self.gameObjects["ExitButton"].released == False:
            self.onExit()
            self.game.isRunning = False

    def onMouseMove(self, event: sdl2.SDL_Event):
        pass

    def getStateID(self) -> str:
        return self.menuID
