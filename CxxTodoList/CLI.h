#ifndef CLI_h
#define CLI_h

#include "TodoList.h"

struct CLI
{
    void DisplayLists()
    {
        for (std::vector<TodoList*>::iterator item = List.begin(); item != List.end(); ++item)
        {
            
        }
    }
  
private:
    std::vector<TodoList*> List;
};

#endif /* CLI_h */
