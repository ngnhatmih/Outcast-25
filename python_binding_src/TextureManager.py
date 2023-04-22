import sdl2, sdl2.ext
import ctypes
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

class TextureManager(metaclass = Singleton):

    def __init__(self):
        self.textures: sdl2.SDL_Texture = {} # Variable stores all textures | id -> Texture

    # Texture loading
    def load(self, filename: str, id: str, renderer: sdl2.ext.renderer.Renderer)-> bool:
        # Use SDL_Surface to load an image (This uses CPU)
        try:
            surface: sdl2.SDL_Surface = sdl2.ext.load_image(filename)
        except:
            # If load_image can't load the image, raise an error and return false
            print("Error loading image")
            return False
        else:
            # Create a SDL_Texture from the surface and store it to the dict with an id
            self.textures[id] = sdl2.ext.Texture(renderer, surface)

            # Now surface is useless, we can free it
            sdl2.SDL_FreeSurface(surface)

            # Texture loading successful 
            return True
    
    # This is normally used for drawing entire texture
    def draw(self, renderer: sdl2.ext.renderer.Renderer, id: str, x: int, y: int, width: int, height: int, scale: float, flip = sdl2.SDL_FLIP_NONE):
        # srcRect is short for source rectangle, which is a rectangle region of the image that will be drawn
        srcRect = (0, 0, width, height)
        # Dest is short for destination refering to the place where the result is goin' on
        # destRect is destination rectangle, which is where the image will be drawn
        destRect = (x, y, width*scale, height*scale)
        # We can say srcRect is a part of the image will be drawn and destRect is the location it will be drawn
        # We can use srcRect to crop the image, and destRect to move or resize the image

        # This can copy the contents of the texture with id to the renderer
        renderer.copy(self.textures[id], srcRect, destRect, flip=flip)

    # This is normally used for drawing a part of the texture (a frame)
    def drawFrame(self, renderer: sdl2.ext.renderer.Renderer, id: str, x: int, y: int, width: int, height: int, scale: float, currentFrame:int, currentRow: int, flip = sdl2.SDL_FLIP_NONE):
        srcRect = (width*currentFrame, height*currentRow, width, height)
        destRect = (x, y, width*scale, height*scale)

        renderer.copy(self.textures[id], srcRect, destRect, flip=flip)
        
    # In case we need to delete the texture to free space
    def clearFromTextureMap(self, id: str):
        self.textures.pop(self.textures[id])