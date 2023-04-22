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
            points.append((int(m*math.cos(math.radians(i)) +size[0]/2 - pos[0]), int(m*math.sin(math.radians(i))+size[1]/2 - pos[1])))
    renderer.draw_line(points, sdl2.ext.Color(*Constant.Colors.BLACK.value))

points = [(size[0]/2, size[1]/2)]
def updateMotion(renderer, pos):
    points.append((size[0]/2 - pos[0], size[1]/2 - pos[1]))
    renderer.draw_line(points, sdl2.ext.Color(*Constant.Colors.RED.value))

def drawArrow(renderer, oPos, pos):
    oPos = (size[0]/2-oPos[0], size[1]/2-oPos[1])
    dy = pos[1]-oPos[1]
    dx = pos[0]-oPos[0]

    if dx == 0:
        return
    elif (dy > 0 and dx > 0) or (dy < 0 and dx > 0):
        theta = math.pi+math.atan(dy/dx)
    else:
        theta = math.atan(dy/dx)

    dPos = (size[0]/2-50*math.cos(theta), size[1]/2-50*math.sin(theta))

    renderer.draw_line([oPos, dPos], sdl2.ext.Color(*Constant.Colors.BLACK.value))

i = 0
isRun = True
while isRun:
    for event in sdl2.ext.get_events():
        if event.type == sdl2.SDL_KEYDOWN:
            if event.key.keysym.sym == sdl2.SDLK_ESCAPE:
                isRun = False
        elif event.type == sdl2.SDL_MOUSEMOTION:
            x = event.motion.x
            y = event.motion.y

    r.clear()
    i += .01
    r.color = sdl2.ext.Color(*Constant.Colors.WHITE.value)
    drawArrow(r, (0,0), (x,y))
    r.present()
    w.refresh()
    sdl2.SDL_Delay(Constant.DELAY)

w.close()
r.destroy()
sdl2.ext.quit()