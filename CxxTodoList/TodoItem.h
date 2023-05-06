#ifndef TodoItem_h
#define TodoItem_h

struct TodoItem
{
    int Id;
    std::string Title;
    std::string Description;
    bool Complete = false;
    
    TodoItem(int Id, std::string Title, std::string Description)
    {
        this->Id = Id;
        this->Title = Title;
        this->Description = Description;
    }

    void UpdateItem(std::string Title, std::string Description, bool Complete)
    {
        this->Title = Title;
        this->Description = Description;
        this->Complete = Complete;
    }
};

#endif /* TodoItem_h */
