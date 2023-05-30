#include "vector2D.h"

Vector2D Vector2D::operator+(const Vector2D &that)
{
    return Vector2D(this->m_x + that.m_x, this->m_y + that.m_y);
}

Vector2D Vector2D::operator+=(const Vector2D &that)
{
    this->m_x += that.m_x;
    this->m_y += that.m_y;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D &that)
{
    return Vector2D(this->m_x - that.m_x, this->m_y - that.m_y);
}

Vector2D operator-(const Vector2D &that)
{
    return Vector2D(-that.m_x, -that.m_y);
}

Vector2D Vector2D::operator-=(const Vector2D &that)
{
    this->m_x -= that.m_x;
    this->m_y -= that.m_y;
    return *this;
}

Vector2D Vector2D::operator*(float n)
{
    return Vector2D(this->m_x * n, this->m_y * n);
}

Vector2D Vector2D::operator*=(float n)
{
    this->m_x *= n;
    this->m_y *= n;
    return *this;
}

Vector2D Vector2D::operator/(float n)
{
    return Vector2D(this->m_x / n, this->m_y / n);
}

Vector2D Vector2D::operator/=(float n)
{
    this->m_x /= n;
    this->m_y /= n;
    return *this;
}

bool Vector2D::operator==(const Vector2D &that)
{
    return this->m_x == that.m_x && this->m_y == that.m_y;
}

float Vector2D::dot(const Vector2D &that)
{
    return this->m_x * that.m_x + this->m_y * that.m_y;
}

float Vector2D::abs()
{
    return std::sqrt(m_x * m_x + m_y * m_y);
}

float abs(const Vector2D &that)
{
    return std::sqrt(that.m_x * that.m_x + that.m_y * that.m_y);
}

std::ostream &operator<<(std::ostream &stream, const Vector2D &that)
{
    return stream << "[" << that.m_x << "," << that.m_y << "]";
}
