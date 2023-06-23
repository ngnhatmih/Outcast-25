#ifndef COMMAND_H
#define COMMAND_H

#include "file_explorer.h"

class Command
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class OpenFileCommand: public Command
{
public:
    virtual void execute();
};

class OpenFolderCommand: public Command
{
public:
    virtual void execute();
};

class SaveCommand: public Command
{
public:
    virtual void execute();
};

#endif /* COMMAND_H */