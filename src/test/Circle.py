import sdl2, sdl2.ext
import math
import Constant

sdl2.ext.init()
size = 700, 600
w = sdl2.ext.Window("MATH", size=size)
r = sdl2.ext.renderer.Renderer(w)
w.show()

def drawCircle(renderer, pos, radius):
    points: sdl2.SDL_Point = []
    for m in range(radius):
        for i in range(360):
            points.append((int(m*math.cos(math.radians(i))+size[0]/2 - pos[0]), int(m*math.sin(math.radians(i))+size[1]/2 - pos[1])))
    renderer.draw_line(points, sdl2.ext.Color(*Constant.Colors.BLACK.value))
    
points = [(size[0]/2, size[0]/2)]
def updateMotion(renderer, pos):
    points.append((size[0]/2 - pos[0], size[0]/2 - pos[1]))
    renderer.draw_line(points, sdl2.ext.Color(*Constant.Colors.RED.value))

i = 0
isRun = True
while isRun:
    for event in sdl2.ext.get_events():
        if event.type == sdl2.SDL_KEYDOWN:
            if event.key.keysym.sym == sdl2.SDLK_ESCAPE:
                isRun = False

    r.clear()
    i += .1
    r.color = sdl2.ext.Color(*Constant.Colors.WHITE.value)
    drawCircle(r, (100*math.cos(i),100*math.sin(i)), 10)
    drawCircle(r, (0,0), 10)
    r.present()
    w.refresh()
    sdl2.SDL_Delay(Constant.DELAY)

w.close()
r.destroy()
sdl2.ext.quit()