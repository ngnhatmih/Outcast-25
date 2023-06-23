#include "file_explorer.h"
#include "nfd.h"

#include <algorithm>
#include <vector>
#include <stack>

FileExplorer *FileExplorer::instancePtr = 0;

void FileExplorer::openFile()
{
    SDL_Log("Opening file...");
    nfdchar_t *filepath = nullptr;
    nfdresult_t result = NFD_OpenDialog(nullptr, nullptr, &filepath);
    if (result == NFD_OKAY)
    {
        m_filepath = filepath;
        SDL_Log("Opened file %s successfully", m_filepath.string().c_str());
        free(filepath);
    }
    else if (result == NFD_CANCEL)
    {
        SDL_Log("File opening cancelled");
    }
    else
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not open file. Error: %s", NFD_GetError());
    }
}

void FileExplorer::pickFolder()
{
    SDL_Log("Opening folder...");
    nfdchar_t *folderpath = nullptr;
    nfdresult_t result = NFD_PickFolder(nullptr, &folderpath);
    if (result == NFD_OKAY)
    {
        m_folderpath = folderpath;
        SDL_Log("Opened folder %s successfully", m_folderpath.string().c_str());
        free(folderpath);
    }
    else if (result == NFD_CANCEL)
    {
        SDL_Log("Folder opening cancelled");
    }
    else
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not open folder. Error: %s", NFD_GetError());
    }
}

void FileExplorer::displayTree(const fs::path &path)
{
    if (path.empty())
    {
        return;
    }

    // Using vector to sort
    std::vector<fs::directory_entry> entries;

    for (const auto &entry : fs::directory_iterator(path))
    {
        entries.push_back(entry);
    }

    // Sort with lambda function
    std::sort(entries.begin(), entries.end(), [](const fs::directory_entry &entry1, const fs::directory_entry &entry2)
              {
        if (fs::is_directory(entry1) && !fs::is_directory(entry2)) {
            return true;
        } else if (!fs::is_directory(entry1) && fs::is_directory(entry2)) {
            return false;
        } else {
            return entry1.path().filename().string() < entry2.path().filename().string();
        } });

    for (const auto &entry : entries)
    {
        const auto &entryPath = entry.path();
        const std::string entryName = entryPath.filename().string();

        std::string nodeLabel = std::string(ICON_CI_FOLDER) + " " + entryName;
        if (fs::is_directory(entryPath))
        {
            bool nodeOpen = ImGui::TreeNodeEx(nodeLabel.c_str(), ImGuiTreeNodeFlags_SpanFullWidth);
            if (nodeOpen)
            {
                displayTree(entryPath);
                ImGui::TreePop();
            }
        }
        else if (fs::is_regular_file(entryPath))
        {
            ImGui::Indent(ImGui::GetTreeNodeToLabelSpacing());
            ImGui::Text("%s", entryName.c_str());
            ImGui::Unindent(ImGui::GetTreeNodeToLabelSpacing());
        }
    }
}
