#include "Main.h"

int main()
{
    TodoList* List = new TodoList("Test List #1");
    for (int i = 0; i < 5; ++i)
        List->AddToList("New Todo #" + std::to_string(i), "Make some noise!");

    List->DisplayList();
    List->UpdateItem(3, "Updated Todo #3", "Updated Description!", true);
    List->DeleteFromList(4);
    List->DisplayList();
}
