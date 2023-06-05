import sdl2, sdl2.ext
import ctypes
from Vector2D import *
from Constant import *

# Metaclass for creating a singleton class
class Singleton(type):
    # This variable is used to store all instances initialized
    instances = {}
    
    # __call__ makes the class itself become a function whenever it is called
    def __call__(self, *args, **kwds):
        # Check whether the instance is in instances
        if self not in self.instances:
            instance = super().__call__(*args, **kwds)
            self.instances[self] = instance
        return self.instances[self]   

# Now InputHandler becomes a singleton class which has only one instance
class InputHandler(metaclass = Singleton):
    # *Note: 
    # - 'cause mouse buttons have only 3 keys so we should create independently the enum.
    # - Declaring variable with a certain data type will make the code easily understand what that variable represents
    keystates: sdl2.Uint8 = [] # Variable stores keyboardstates | ScanCode -> {0,1}
    mouseButtonStates: bool = [] # Variable stores mouseButtonStates | MouseButton -> {False, True}
    mousePos = Vector2D(CENTER) # Default position is center of the window

    def __init__(self, game):
        self.game = game

        for i in range(3):
            self.mouseButtonStates.append(False)

    #%/MOUSE/%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    # Get mouse's position
    def getMousePos(self):
        return self.mousePos

    # Get state of the mouse button
    def getMouseButtonState(self, mouseState):
        return self.mouseButtonStates[mouseState]

    # Moving mouse will trigger this event:
    def onMouseMove(self, event: sdl2.SDL_Event):
        self.mousePos.setX(event.motion.x)
        self.mousePos.setY(event.motion.y)

        self.game.getGameStateMachine().onMouseMove(event)

    # MouseButtonDown and MouseButtonUp will trigger these events:
    # Handle pressed mouse buttons
    def onMouseButtonDown(self, event: sdl2.SDL_Event):
        # Update mouseButtonStates
        match event.button.button:
            case sdl2.SDL_BUTTON_LEFT:
                self.mouseButtonStates[MouseButtons.LEFT.value] = True
            case sdl2.SDL_BUTTON_MIDDLE:
                self.mouseButtonStates[MouseButtons.MIDDLE.value] = True
            case sdl2.SDL_BUTTON_RIGHT:
                self.mouseButtonStates[MouseButtons.RIGHT.value] = True

        self.game.getGameStateMachine().onMouseButtonDown(event)


    # Handle released mouse buttons
    def onMouseButtonUp(self, event: sdl2.SDL_Event):
        # Update mouseButtonStates
        match event.button.button:
            case sdl2.SDL_BUTTON_LEFT:
                self.mouseButtonStates[MouseButtons.LEFT.value] = False
            case sdl2.SDL_BUTTON_MIDDLE:
                self.mouseButtonStates[MouseButtons.MIDDLE.value] = False
            case sdl2.SDL_BUTTON_RIGHT:
                self.mouseButtonStates[MouseButtons.RIGHT.value] = False

        self.game.getGameStateMachine().onMouseButtonUp(event)

    # Reset all mouse button states to false
    def reset(self):
        for i in range(3):
            self.mouseButtonStates[i] = False

    #%/KEYBOARD/%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    # Is the key a release or a press?
    def isKeyDown(self, key: sdl2.SDL_Scancode)->bool:
        # Check whether or not the keystates is empty
        if self.keystates != []:
            # 1 is KeyDown, 0 is KeyUp
            if self.keystates[key] == 1:
                return True

            else: return False

        else: return False

    # KeyDown and KeyUp will trigger these events:
    # Handle pressed keys
    
    def onKeyDown(self, event: sdl2.SDL_Event):
        # Update keyboardstates
        # 0 is the first index of keyboards in case there are many keyboards connected
        self.keystates = sdl2.SDL_GetKeyboardState(ctypes.c_long(0))

        self.game.getGameStateMachine().onKeyDown(event)

    # Handle released keys
    def onKeyUp(self, event: sdl2.SDL_Event):
        # Update keyboardstates
        self.keystates = sdl2.SDL_GetKeyboardState(ctypes.c_long(0))

        self.game.getGameStateMachine().onKeyUp(event)

    def update(self):
        # Is the game running
        self.game.isRunning = True

        # Event Polling
        for event in sdl2.ext.get_events():
            match event.type:
                case sdl2.SDL_QUIT:
                    self.game.isRunning = False
                    self.game.getGameStateMachine().gameStates[-1].onExit()
                case sdl2.SDL_KEYDOWN:
                    self.onKeyDown(event)
                    if event.key.keysym.sym == sdl2.SDLK_ESCAPE:
                        self.game.isRunning = False
                        self.game.getGameStateMachine().gameStates[-1].onExit()
                case sdl2.SDL_KEYUP:
                    self.onKeyUp(event)
                case sdl2.SDL_MOUSEBUTTONDOWN:
                    self.onMouseButtonDown(event)
                case sdl2.SDL_MOUSEBUTTONUP:
                    self.onMouseButtonUp(event)
                case sdl2.SDL_MOUSEMOTION:
                    self.onMouseMove(event)

