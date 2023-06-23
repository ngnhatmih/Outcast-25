#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

#include <filesystem>
#include "imgui.h"
#include "IconsCodicons.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_image.h>
#include <string>

namespace fs = std::filesystem;

class FileExplorer
{
public:
    FileExplorer(const &FileDialogs) = delete;
    static FileExplorer *getInstance()
    {
        if (instancePtr == 0)
        {
            instancePtr = new FileExplorer();
        }

        return instancePtr;
    }

    void openFile();
    void saveFile();
    void pickFolder();
    void displayTree(const fs::path &path);

    fs::path getFilePath() { return m_filepath; }
    fs::path getFolderPath() { return m_folderpath; }

private:
    FileExplorer() {}
    static FileExplorer *instancePtr;

    fs::path m_filepath;
    fs::path m_folderpath;

};

#endif /* FILE_EXPLORER_H */