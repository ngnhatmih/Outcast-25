import sdl2, sdl2.ext
import math

sdl2.ext.init()

size = 600, 600
points = [(size[0]/2-50*math.cos(t*0.01),size[1]/2-50*math.sin(t*0.01)) for t in range(math.ceil(math.pi*2*100))]

w = sdl2.ext.Window("Circle", size=size)
r = sdl2.ext.renderer.Renderer(w)

w.show()

isRun = True
while isRun:
    for event in sdl2.ext.get_events():
        match event.type:
            case sdl2.SDL_KEYDOWN:
                if event.key.keysym.sym == sdl2.SDLK_ESCAPE:
                    isRun = False
            case sdl2.SDL_QUIT:
                isRun = False
    
    r.clear()
    r.color = sdl2.ext.Color(255, 255, 255, 1)
    r.draw_point(points, sdl2.ext.Color(0, 0, 0, 1))
    r.present()
    w.refresh()

r.destroy()
w.close()
sdl2.ext.quit()