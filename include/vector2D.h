#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <ostream>

class Vector2D
{
public:
    Vector2D() {}
    Vector2D(float x, float y): m_x(x), m_y(y) {}
    static Vector2D Polar(float radius, float angle) { return Vector2D(radius*std::cos(angle), radius*std::sin(angle)); }
    Vector2D(const Vector2D &that) { this->m_x = that.m_x; this->m_y = that.m_y; }

    void setX(float x) { m_x = x; }
    void setY(float y) { m_y = y; }

    float getX() { return m_x; }
    float getY() { return m_y; }

    Vector2D operator+(const Vector2D &);
    Vector2D operator+=(const Vector2D &);
    Vector2D operator-(const Vector2D &);
    friend Vector2D operator-(const Vector2D &); // This is used for negation
    Vector2D operator-() { return Vector2D(-m_x, -m_y); }
    Vector2D operator-=(const Vector2D &);
    Vector2D operator*(float);
    Vector2D operator/(float);
    Vector2D operator*=(float);
    Vector2D operator/=(float);
    bool operator==(const Vector2D &);

    float dot(const Vector2D &);

    float abs();
    friend float abs(const Vector2D &);
    
    void normalize();
    
    friend std::ostream &operator<<(std::ostream &, const Vector2D &);

private:
    float m_x;
    float m_y;

};

#endif /* VECTOR2D_H */
