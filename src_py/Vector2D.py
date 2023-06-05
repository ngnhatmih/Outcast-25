import math
class Vector2D():
    def __init__(self, vector):
        if isinstance(vector, list) or isinstance(vector, tuple):
            self.x = vector[0]
            self.y = vector[1]

        elif isinstance(vector, Vector2D):
            self.x = vector.x
            self.y = vector.y

        self.length = math.sqrt(self.x*self.x + self.y*self.y)
        self.angle = math.atan2(self.y, self.x)
    
    @classmethod
    def polar_to_cartesian(cls, length, angle):
        cls.length = length
        cls.angle = angle

        if length < 0:
            print("The lenght must be greater than or equal 0")
        else: 
            return cls([length*math.cos(angle), length*math.sin(angle)])

    def getLength(self)-> float:
        return self.length
    
    def getAngle(self):
        return self.angle

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def __add__(self, other):
        if isinstance(other, list) or isinstance(other, tuple):
            return Vector2D([self.x + other[0], self.y + other[1]])
        elif isinstance(other, Vector2D):
            return Vector2D([self.x + other.x, self.y + other.y])
        else : return NotImplemented

    def __radd__(self, other):
        if isinstance(other, list) or isinstance(other, tuple):
            return Vector2D([self.x + other[0], self.y + other[1]])
        elif isinstance(other, Vector2D):
            return Vector2D([self.x + other.x, self.y + other.y])
        else: return NotImplemented

    def __iadd__(self, other):
        if isinstance(other, list) or isinstance(other, tuple):
            self.x += other[0]
            self.y += other[1]
            return self

        elif isinstance(other, Vector2D):
            self.x += other.x
            self.y += other.y
            return self

        else: return NotImplemented

    def __sub__(self, other):
        if isinstance(other, list) or isinstance(other, tuple):
            return Vector2D([self.x - other[0], self.y - other[1]])
        elif isinstance(other, Vector2D):
            return Vector2D([self.x - other.x, self.y - other.y])
        else: return NotImplemented

    def __rsub__(self, other):
        if isinstance(other, list) or isinstance(other, tuple):
            return Vector2D([other[0] - self.x, other[1]- self.y])
        elif isinstance(other, Vector2D):
            return Vector2D([other.x - self.x, other.y- self.y])
        else: return NotImplemented

    def __isub__(self, other):
        if isinstance(other, list) or isinstance(other, tuple):
            self.x -= other[0]
            self.y -= other[1]
            return self     

        elif isinstance(other, Vector2D):
            self.x -= other.x
            self.y -= other.y
            return self

        else: return NotImplemented

    def __mul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            return Vector2D([self.x*other, self.y*other])
        else: return NotImplemented

    def __rmul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            return Vector2D([self.x*other, self.y*other])
        else: return NotImplemented

    def __imul__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            self.x *= other
            self.y *= other
            return self
        else: return NotImplemented

    def dot(self, other):
        if isinstance(other, tuple) or isinstance(other, list):
            return self.x * other[0] + self.y * other[1]
        elif isinstance(other, Vector2D):
            return self.x * other.x + self.y * other.y

    def __truediv__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            return Vector2D([self.x / other, self.y / other])
        else: return NotImplemented

    def __itruediv__(self, other):
        if isinstance(other, int) or isinstance(other, float):
            return Vector2D([self.x / other, self.y / other])
        else: return NotImplemented

    def __neg__(self):
        return Vector2D([-self.x, -self.y])

    def normalise(self):
        if self.length() > 0:
            return self / self.length()
    
    def __iter__(self):
        yield self.x
        yield self.y
        
    def __repr__(self):
        return f"[{self.x}, {self.y}]"

if __name__ == "__main__":
    print(Vector2D.polar_to_cartesian(math.sqrt(2), math.pi/4))
    