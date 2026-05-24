//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Window 
//{
//    string title;
//    string color;
//    int width;
//    int height;
//    Window* prev;
//    Window* next;
//
//    Window(string t, string c, int w, int h)
//    {
//        title = t;
//        color = c;
//        width = w;
//        height = h;
//        prev = NULL;
//        next = NULL;
//    }
//};
//
//class WindowManager
//{
//private:
//    Window* head;
//
//public:
//    WindowManager() 
//    {
//        head = NULL;
//    }
//
//    void createWindow(string title, string color)
//    {
//        Window* temp = head;
//
//        while (temp != NULL)
//        {
//            if (temp->title == title)
//            {
//                cout << "Window with this title already exists." << endl;
//                return;
//            }
//
//            temp = temp->next;
//        }
//
//        Window* newWin = new Window(title, color, 800, 600);
//        if (head == NULL) 
//        {
//            head = newWin;
//        }
//        else {
//            Window* temp = head;
//            while (temp->next != NULL)
//                temp = temp->next;
//            temp->next = newWin;
//            newWin->prev = temp;
//        }
//        cout << "Window " << title << " created." << endl;
//    }
//
//    void activateWindow(string title) 
//    {
//        if (head == NULL) 
//        {
//            cout << "No windows exist." << endl;
//            return;
//        }
//        if (head->title == title) 
//        {
//            cout << "Window " << title << " is already active." << endl;
//            return;
//        }
//
//        Window* temp = head->next;
//        while (temp != NULL)
//        {
//            if (temp->title == title) 
//            {
//                if (temp->prev != NULL)
//                    temp->prev->next = temp->next;
//                if (temp->next != NULL)
//                {
//                    temp->next->prev = temp->prev;
//                }
//                temp->prev = NULL;
//                temp->next = head;
//                head->prev = temp;
//                head = temp;
//
//                cout << "Window " << title << " is now active." << endl;
//                return;
//            }
//            temp = temp->next;
//        }
//        cout << "Window " << title << " not found." << endl;
//    }
//
//    void resizeWindow(string title, int newWidth, int newHeight)
//    {
//        if (newWidth <= 0 || newHeight <= 0)
//        {
//            cout << "Invalid window size." << endl;
//            return;
//        }
//
//        Window* temp = head;
//        while (temp != NULL)
//        {
//            if (temp->title == title) 
//            {
//                temp->width = newWidth;
//                temp->height = newHeight;
//                cout << "Window " << title << " resized to "
//                    << newWidth << "x" << newHeight << "." << endl;
//                return;
//            }
//            temp = temp->next;
//        }
//        cout << "Window " << title << " not found." << endl;
//    }
//
//    void deleteWindow(string title) 
//    {
//        if (head == NULL) 
//        {
//            cout << "No windows exist." << endl;
//            return;
//        }
//
//        Window* temp = head;
//        while (temp != NULL) 
//        {
//            if (temp->title == title) 
//            {
//                if (temp->prev != NULL)
//                    temp->prev->next = temp->next;
//                else
//                    head = temp->next;
//
//                if (temp->next != NULL)
//                    temp->next->prev = temp->prev;
//
//                delete temp;
//                cout << "Window " << title << " deleted." << endl;
//                return;
//            }
//            temp = temp->next;
//        }
//        cout << "Window " << title << " not found." << endl;
//    }
//
//    void displayWindows()
//    {
//        if (head == NULL)
//        {
//            cout << "No windows open." << endl;
//            return;
//        }
//        cout << "\n--- Window List ---" << endl;
//        Window* temp = head;
//        int i = 1;
//        while (temp != NULL) 
//        {
//            cout << i << ". Title: " << temp->title
//                << " | Color: " << temp->color
//                << " | Size: " << temp->width << "x" << temp->height;
//            if (i == 1) cout << "  [ACTIVE]";
//            cout << endl;
//            temp = temp->next;
//            i++;
//        }
//        cout << "------------------------------------" << endl;
//    }
//
//    ~WindowManager()
//    {
//        Window* temp = head;
//
//        while (temp != NULL)
//        {
//            Window* nextNode = temp->next;
//            delete temp;
//            temp = nextNode;
//        }
//    }
//};
//
//int main() 
//{
//    WindowManager wm;
//    int choice;
//    string title, color;
//    int w, h;
//
//    cout << "=== Window Manager ===" << endl;
//
//    do
//    {
//        cout << "\n1. Create Window" << endl;
//        cout << "2. Activate Window" << endl;
//        cout << "3. Resize Window" << endl;
//        cout << "4. Delete Window" << endl;
//        cout << "5. Display All Windows" << endl;
//        cout << "0. Exit" << endl;
//        cout << "Enter choice: ";
//        cin >> choice;
//        cin.ignore();
//
//        if (choice == 1) 
//        {
//            cout << "Enter title: ";
//            getline(cin, title);
//            cout << "Enter color: ";
//            getline(cin, color);
//            wm.createWindow(title, color);
//
//        }
//        else if (choice == 2) 
//        {
//            cout << "Enter title to activate: ";
//            getline(cin, title);
//            wm.activateWindow(title);
//
//        }
//        else if (choice == 3) 
//        {
//            cout << "Enter title to resize: ";
//            getline(cin, title);
//            cout << "Enter new width: ";
//            cin >> w;
//            cout << "Enter new height: ";
//            cin >> h;
//            cin.ignore();
//            wm.resizeWindow(title, w, h);
//
//        }
//        else if (choice == 4) 
//        {
//            cout << "Enter title to delete: ";
//            getline(cin, title);
//            wm.deleteWindow(title);
//
//        }
//        else if (choice == 5) 
//        {
//            wm.displayWindows();
//        }
//
//    } while (choice != 0);
//
//    cout << "Exiting Window Manager." << endl;
//    return 0;
//}