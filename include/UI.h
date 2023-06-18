#ifndef UI_H
#define UI_H

class UI
{
public:
    static UI* getInstance()
    {
        if (instancePtr == 0)
        {
            instancePtr = new UI();
        }
        return instancePtr;
    }
    bool showPopItems = false;

private:
    UI() {}
    static UI *instancePtr;

};

#endif /* UI_H */