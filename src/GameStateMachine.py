from GameState import *
import sdl2, sdl2.ext

# GameStateMachine can be also called game state manager, is used to manage those different game states.
# And determining which one should be showed on screen.
class GameStateMachine:
    gameStates: GameState = [] # Variable stores game states of the game

    def update(self):
        if not self.gameStates == []:
            self.gameStates[-1].update()
    
    def render(self):
        if not self.gameStates == []:
            self.gameStates[-1].render()

    def onEnter(self)->bool:
        pass

    def onExit(self)->bool:
        pass

    def onKeyDown(self, event: sdl2.SDL_Event):            
        if not self.gameStates == []:
            self.gameStates[-1].onKeyDown(event)

    def onKeyUp(self, event: sdl2.SDL_Event):
        if not self.gameStates == []:
            self.gameStates[-1].onKeyUp(event)

    def onMouseButtonDown(self, event: sdl2.SDL_Event):
        if not self.gameStates == []:
            self.gameStates[-1].onMouseButtonDown(event)

    def onMouseButtonUp(self, event: sdl2.SDL_Event):
        if not self.gameStates == []:
            self.gameStates[-1].onMouseButtonUp(event)

    def onMouseMove(self, event: sdl2.SDL_Event):
        if not self.gameStates == []:
            self.gameStates[-1].onMouseMove(event)

    def getStateID(self)->str:
        if not self.gameStates == []:
            self.gameStates[-1].getStateID()

    def pushState(self, state: GameState):
        # Add state to gameStates
        self.gameStates.append(state)
        # Trigger enter event
        state.onEnter()

    def popState(self, state: gameStates):
        # Remove state to gameStates
        self.gameStates.remove(state)
        # Trigger exit event
        state.onExit()

    def changeState(self, state: gameStates):
        # Check if gameStates is empty
        if not self.gameStates == []:
            # If the state is in array, return nothing
            if self.gameStates[-1].getStateID() == state.getStateID():
                return

            # Otherwise, remove the current state
            else:
                self.popState(self.gameStates[-1])
        
        # Push state
        self.pushState(state)