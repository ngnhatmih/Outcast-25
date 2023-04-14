import sys
from Game import *

def main():
    
    # Game Loop
    while(Game().isRunning):
        # The time when the frame starts
        frameStart = sdl2.SDL_GetTicks()
        Game().eventHandle()
        Game().update()
        Game().render()
        # Calculate the time taken to load the frame
        frameTime = sdl2.SDL_GetTicks() - frameStart

        # Calculate the delays 
        delayTime = DELAY - frameTime

        # Set delay time
        if delayTime > 0:
            sdl2.SDL_Delay(delayTime)
        else:
            sdl2.SDL_Delay(frameTime)

    Game().clean()

# This is the entry point
if __name__ == "__main__":
    sys.exit(main())