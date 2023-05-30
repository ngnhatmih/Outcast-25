#ifndef PLAYER_H
#define PLAYER_H

#include "game_object.h"

class Player: public GameObject
{
public:
    Player() {}
    void draw();
    void update();
    void clean();
    void load(LoaderParams *pLoader);

private:
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    std::string m_TextureID;
    int m_numFrames;
    int m_currentRow;
    int m_currentFrame;
};

#endif /* PLAYER_H */