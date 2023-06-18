#ifndef FILE_DIALOGS_H
#define FILE_DIALOGS_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>

class FileDialogs
{
public:
    FileDialogs(const &FileDialogs) = delete;
    static FileDialogs *getInstance()
    {
        if (instancePtr == 0)
        {
            instancePtr = new FileDialogs();
        }

        return instancePtr;
    }

    void openFile();
    void saveFile();

private:
    FileDialogs() {}
    static FileDialogs *instancePtr;
};

#endif /* FILE_DIALOGS_H */