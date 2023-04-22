import sdl2, sdl2.ext
import InputHandler
from TextureManager import *
from Constant import *
from GameStateMachine import *
from MenuState import MenuState


class Singleton(type):
    # __call__ makes the class itself become a function whenever it is called
    instances = {} # This variable is used to store all instances initialized

    def __call__(self, *args, **kwds):
        # Check whether the instance is in instances
        if self not in self.instances:
            instance = super().__call__(*args, **kwds)
            self.instances[self] = instance
        return self.instances[self]  

class Game(metaclass = Singleton):
    version = 0.0
    gameStateMachine= GameStateMachine() # Game state manager

    def __init__(self):
        # Initialize SDL and its subsystems
        # Subsystems (default): video=True, audio=False, timer=False, joystick=False,
        # controller=False, haptic=False, sensor=False, events=True
        sdl2.ext.init()

        # Window Creation
        self.window = sdl2.ext.Window(f"Fantasy-World {self.version}", SIZE)

        # Renderer Creation
        self.renderer = sdl2.ext.renderer.Renderer(self.window, flags = sdl2.SDL_RENDERER_ACCELERATED)

        # Push menu state
        self.gameStateMachine.pushState(MenuState(self))

        # Show the windows
        self.window.show() 

        # Is the game running?
        self.isRunning = True

        # Load the textures
        TextureManager().load("assets/textures/rikka.jpg", "rikka", self.renderer)
        self.currentFrame = 0
    
    # Get remderer
    def getRenderer(self)->sdl2.ext.renderer.Renderer:
        return self.renderer

    # Get the machine through Game()
    def getGameStateMachine(self)-> GameStateMachine:
        return self.gameStateMachine

    # Event Handling
    def eventHandle(self):
        InputHandler.InputHandler(self).update()

    # Render the frame
    def render(self):
        self.gameStateMachine.render()

    # Update to the screen
    def update(self):
        self.gameStateMachine.update()
    
    # Clean up
    def clean(self):
        self.window.close()
        self.renderer.destroy()
        sdl2.ext.quit()
