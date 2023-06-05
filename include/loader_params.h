#ifndef LOADER_PARAMS_H
#define LOADER_PARAMS_H

#include "texture_manager.h"

class LoaderParams
{
public:
    LoaderParams(float x, float y, float width, float height, float scale, std::string textureID, int numFrames):
        m_x(x),
        m_y(y),
        m_width(width),
        m_height(height),
        m_scale(scale),
        m_textureID(textureID),
        m_numFrames(numFrames)
        {}
    
    LoaderParams(float x, float y, float width, float height, float scale, float scrollSpeed, bool scrollFlow, std::string textureID, int numFrames):
        m_x(x),
        m_y(y),
        m_width(width),
        m_height(height),
        m_scale(scale),
        m_scrollSpeed(scrollSpeed),
        m_scrollFlow(scrollFlow),
        m_textureID(textureID),
        m_numFrames(numFrames)
        {}

    float getX() { return m_x; }
    float getY() { return m_y; }
    float getWidth() { return m_width; }
    float getHeight() { return m_height; }
    float getScale() { return m_scale; }
    float getScrollSpeed() { return m_scrollSpeed; }
    bool getScrollFlow() { return m_scrollFlow; }
    std::string getTextureID() { return m_textureID; }
    int getNumFrames() { return m_numFrames; }

private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    float m_scale;
    float m_scrollSpeed;
    bool m_scrollFlow;
    std::string m_textureID;
    int m_numFrames;
};

#endif /* LOADER_PARAMS_H */