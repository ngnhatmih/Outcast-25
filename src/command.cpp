#include "command.h"
#include "file_explorer.h"

void OpenFileCommand::execute()
{
    FileExplorer::getInstance()->openFile();
}

void OpenFolderCommand::execute()
{
    FileExplorer::getInstance()->pickFolder();
}

