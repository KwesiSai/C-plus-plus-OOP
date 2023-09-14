#include <iostream>
#include <string>

using namespace std;

class Asset {
private:
    int serialId;
    string assetname;
    string owner;
    string department;
    bool isObsolete;
    Asset* next;

public:
    Asset(int id, const string& name, const string& owner, const string& department, bool obsolete)
        : serialId(id), assetname(name), owner(owner), department(department), isObsolete(obsolete), next(nullptr) {}

    void display() {
        cout << "Asset serial ID is " << serialId << endl;
        cout << "The asset is a " << assetname << endl;
        cout << "Asset belongs to " << owner << endl;
        cout << "Asset is used in the " << department << " department." << endl;
        cout << "Is Asset obsolete ? " << (isObsolete ? " Yes" : " No") << endl;
    }

    int getSerialId() const { return serialId; }
    void setIsObsolete(bool obsolete) { isObsolete = obsolete; }
    Asset* getNext() const { return next; }
    void setNext(Asset* asset) { next = asset; }

};

// Function to create a new asset and return a pointer to it
Asset* createAsset() {
    int id;
    string name, owner, department;
    bool obsolete;

    cout << "Enter asset serial ID: ";
    cin >> id;

    cout << "Enter asset name: ";
    cin.ignore(); // Consume newline character
    getline(cin, name);

    cout << "Enter asset owner: ";
    getline(cin, owner);

    cout << "Enter asset department: ";
    getline(cin, department);

    cout << "Is asset obsolete (0 for No, 1 for Yes): ";
    cin >> obsolete;

    return new Asset(id, name, owner, department, obsolete);
}

int main() {
    // Create a linked list to store assets
    Asset* head = nullptr;

    char addMore;

    do {
        // Create a new asset and add it to the list
        Asset* newAsset = createAsset();
        newAsset->setNext(head);
        head = newAsset;

        cout << "Do you want to add more assets? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');
       system("cls");
    // Display assets
    Asset* current = head;
    while (current != nullptr) {
        current->display();
        cout << endl;
        current = current->getNext();
    }

    // Clean up memory
    current = head;
    while (current != nullptr) {
        Asset* temp = current;
        current = current->getNext();
        delete temp;
    }

    return 0;
};
