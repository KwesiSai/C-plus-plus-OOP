#include <iostream>

using namespace std;
 class Asset{
 private:
    int serialId;
    string assetname;
    string owner;
    string department;
    bool isObsolete;
    Asset* next;

 public:
     Asset(int id,const string& name, const string& owner, const string& department,bool obsolete)
         : serialId(id),assetname(name), owner(owner), department(department), isObsolete(obsolete), next(nullptr){}
     void display(){
       cout<<"Asset serial ID is "<<serialId<<endl;
       cout<<"The asset is a "<<assetname<<endl;
       cout<<"Asset belongs to "<<owner<<endl;
       cout<<"Asset is used in the "<<department<<" department."<<endl;
       cout<<"Is Asset obsolete ? "<<(isObsolete ? " Yes":" No")<<endl;
     }
     int getSerialId() const { return serialId; }
    void setIsObsolete(bool obsolete) { isObsolete = obsolete; }
     Asset* getNext() const { return next; }
    void setNext(Asset* asset) { next = asset; }

 };

int main()
{
        // Create a linked list to store assets
    Asset* head = nullptr;

    // Add assets to the list
    head = new Asset(1, "Keyboard", "John Doe", "IT", false);
    head->setNext(new Asset(2,"Printer", "Jane Smith", "Finance", true));
    head->getNext()->setNext(new Asset(3, "Router", "Bob Johnson", "HR", true));

    // Display assets
    Asset* current = head;
    while (current != nullptr) {
        current->display();
        std::cout << std::endl;
        current = current->getNext();
    }

}
