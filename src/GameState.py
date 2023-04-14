from abc import ABC, abstractmethod
import sdl2
from GameObject import *

# An abstract class - a class cannot be instantiated
# GameState defines the different states such as menu state, in-game state, pause state. 
# Each state has its own functions like render, update, event handling, so on.
class GameState(ABC): # Declare abtract class
    # This decorator indicates this method has no implementation but can be overridden by any concrete subclass
    # In C/C++ this is a virtual function which should be overridden in subclass of the abstract class

    @abstractmethod
    def update(self):
        pass
    
    @abstractmethod
    def render(self):
        pass

    @abstractmethod
    def onEnter(self)->bool:
        pass

    @abstractmethod
    def onExit(self)->bool:
        pass

    @abstractmethod
    def onKeyDown(self, event: sdl2.SDL_Event):
        pass

    @abstractmethod
    def onKeyUp(self, event: sdl2.SDL_Event):
        pass

    @abstractmethod
    def onMouseButtonDown(self, event: sdl2.SDL_Event):
        pass

    @abstractmethod
    def onMouseButtonUp(self, event: sdl2.SDL_Event):
        pass

    @abstractmethod
    def onMouseMove(self, event: sdl2.SDL_Event):
        pass

    @abstractmethod
    def getStateID(self)->str:
        pass

    def getObjectbyID(self, id:str)->GameObject:
        return self.gObjects[id]


    