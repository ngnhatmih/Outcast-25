#include "file_dialogs.h"
#include "nfd.h"

FileDialogs *FileDialogs::instancePtr = 0;

void FileDialogs::openFile()
{
    SDL_Log("Opening file...");
    nfdchar_t *filepath = nullptr;
    nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &filepath);
    if (result == NFD_OKAY)
    {
        SDL_Log("Opened file %s successfully", filepath);
    }
    else if (result == NFD_CANCEL)
    {
        SDL_Log("Canceled");
    }
    else
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not open file. Error: %s", NFD_GetError());
    }
}