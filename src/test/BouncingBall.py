import sdl2, sdl2.ext
import math
import Constant

sdl2.ext.init()
size = 700, 600
w = sdl2.ext.Window("MATH", size=size)
r = sdl2.ext.renderer.Renderer(w)
w.show()

def updateMotion(renderer, pos):
    points.append((size[0]/2 - pos[0], size[1]/2 - pos[1]))
    renderer.draw_line(points, sdl2.ext.Color(*Constant.Colors.RED.value))

def drawCircle(renderer, pos, radius):
    points: sdl2.SDL_Point = []
    for m in range(radius):
        for i in range(360):
            points.append((int(m*math.cos(math.radians(i))+size[0]/2 - pos[0]), int(m*math.sin(math.radians(i))+size[1]/2 - pos[1])))
    renderer.draw_line(points, sdl2.ext.Color(*Constant.Colors.BLACK.value))

points = [(size[0]/2-200,size[1]/2)]
v_0 = 100
x_0 = 0
t, t_0 = 0, 0
isRun = True
while isRun:
    for event in sdl2.ext.get_events():
        if event.type == sdl2.SDL_KEYDOWN:
            if event.key.keysym.sym == sdl2.SDLK_ESCAPE:
                isRun = False

    r.clear()
    r.color = sdl2.ext.Color(*Constant.Colors.WHITE.value)

    theta = math.radians(101)
    g = 9.807
    e = 0.63
    x = v_0*math.cos(theta)*(t-t_0) + x_0
    y = v_0*math.sin(theta)*(t-t_0)-g*(t-t_0)**2/2

    drawCircle(r, (x+200,y), 20)
    updateMotion(r, (x+200,y))

    if int(y) <= 0:
        v_y = v_0*math.cos(theta) - g*t
        v_x = -v_0*math.sin(theta)
        t_0 = t
        x_0 = x
        if v_0 > 0:
            v_0 = v_0*e
            slope = v_y/v_x
            theta = math.atan(slope)
            print(theta)
        else: v_0 = 0

    r.present()
    w.refresh()
    sdl2.SDL_Delay(Constant.DELAY)
    t += .1

w.close()
r.destroy()
sdl2.ext.quit()