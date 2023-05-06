#ifndef TodoList_h
#define TodoList_h

#include "TodoItem.h"

struct TodoList
{
    std::string ListTitle;
    std::vector<TodoItem*> List;
    
    TodoList(std::string ListTitle)
    {
        this->ListTitle = ListTitle;
    }

    void DisplayList()
    {
        if (List.size())
        {
            std::cout << "* [" << ListTitle << "] *\n\n";
            std::cout << "[DisplayList] -->\n\n";

            for (std::vector<TodoItem*>::iterator iterator = List.begin(); iterator != List.end(); ++iterator) {
                TodoItem* item = *iterator;
                std::cout << "#" << item->Id << ": " << item->Title << "\n";
                std::cout << "\tStatus: " << (item->Complete ? "Completed" : "In Progress") << "\n";
                std::cout << "\t" << item->Description << "\n\n";
            }
            std::cout << "[DisplayList] <--\n\n";
        }
        else
        {
            DisplayOut("DisplayList", "\t- Your list is empty :(\n\n");
        }
    }
    
    void AddToList(std::string Title, std::string Description)
    {
        LastId += 1;
        int NewId = LastId;
        TodoItem* item = new TodoItem(NewId, Title, Description);
        List.push_back(item);
    }
    
    void UpdateItem(int Id, std::string Title, std::string Description, bool Complete)
    {
        TodoItem* item = NULL;
        for (std::vector<TodoItem*>::iterator iterator = List.begin(); iterator != List.end(); ++iterator)
            if ((*iterator)->Id == Id)
                item = (*iterator);

        if (item)
            item->UpdateItem(Title, Description, Complete);
        else
            DisplayOut("UpdateItem", "\t- Item with [id = " + std::to_string(Id) + "] not found!\n\n");
    }
    
    void DeleteFromList(int Id)
    {
        std::vector<TodoItem*>::iterator item;
        for (std::vector<TodoItem*>::iterator iterator = List.begin(); iterator != List.end(); ++iterator)
            if ((*iterator)->Id == Id)
                item = iterator;

        if (*item)
            List.erase(item);
        else
            DisplayOut("UpdateItem", "\t- Item with [id = " + std::to_string(Id) + "] not found!\n\n");
    }
    
private:
    int LastId = 0;
    
    void DisplayOut(std::string method, std::string message)
    {
        std::cout << "* [" << ListTitle << "] *\n\n";
        std::cout << "[" << method << "] -->\n\n";
        std::cout << message;
        std::cout << "[" << method << "] <--\n\n";
    }
};

#endif /* TodoList_h */
