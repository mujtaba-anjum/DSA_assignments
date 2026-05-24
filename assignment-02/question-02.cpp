//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//struct Paragraph
//{
//    string text;
//    Paragraph* prev;
//    Paragraph* next;
//
//    Paragraph()
//    {
//        text = "";
//        prev = NULL;
//        next = NULL;
//    }
//};
//
//class TextEditor
//{
//private:
//    Paragraph* head;
//    Paragraph* cursor;
//    string currentFile;
//    bool isModified;
//
//public:
//    TextEditor()
//    {
//        head = NULL;
//        cursor = NULL;
//        currentFile = "";
//        isModified = false;
//    }
//
//    ~TextEditor()
//    {
//        Paragraph* p = head;
//
//        while (p != NULL)
//        {
//            Paragraph* temp = p->next;
//            delete p;
//            p = temp;
//        }
//    }
//
//    void newFile()
//    {
//        Paragraph* p = head;
//
//        while (p != NULL)
//        {
//            Paragraph* temp = p->next;
//            delete p;
//            p = temp;
//        }
//
//        head = new Paragraph();
//        cursor = head;
//
//        currentFile = "";
//        isModified = false;
//
//        cout << "New file created." << endl;
//    }
//
//    void saveFile()
//    {
//        if (currentFile == "")
//        {
//            cout << "Enter filename: ";
//            getline(cin, currentFile);
//        }
//
//        ofstream file(currentFile.c_str());
//
//        if (!file)
//        {
//            cout << "Error saving file." << endl;
//            return;
//        }
//
//        Paragraph* p = head;
//
//        while (p != NULL)
//        {
//            file << p->text << endl;
//            p = p->next;
//        }
//
//        file.close();
//
//        isModified = false;
//
//        cout << "File saved successfully." << endl;
//    }
//
//    void saveFileAs()
//    {
//        cout << "Enter new filename: ";
//
//        getline(cin, currentFile);
//
//        saveFile();
//    }
//
//    void openFile()
//    {
//        cout << "Enter filename to open: ";
//
//        string fname;
//        getline(cin, fname);
//
//        ifstream file(fname.c_str());
//
//        if (!file)
//        {
//            cout << "File not found." << endl;
//            return;
//        }
//
//        Paragraph* p = head;
//
//        while (p != NULL)
//        {
//            Paragraph* temp = p->next;
//            delete p;
//            p = temp;
//        }
//
//        head = NULL;
//        cursor = NULL;
//
//        string line;
//        Paragraph* last = NULL;
//
//        while (getline(file, line))
//        {
//            Paragraph* newPara = new Paragraph();
//
//            newPara->text = line;
//
//            if (head == NULL)
//            {
//                head = newPara;
//                last = newPara;
//            }
//            else
//            {
//                last->next = newPara;
//                newPara->prev = last;
//                last = newPara;
//            }
//        }
//
//        file.close();
//
//        if (head == NULL)
//        {
//            head = new Paragraph();
//        }
//
//        cursor = head;
//
//        currentFile = fname;
//        isModified = false;
//
//        cout << "File opened successfully." << endl;
//    }
//
//    void closeFile()
//    {
//        if (isModified)
//        {
//            cout << "Unsaved changes exist. Save file? (y/n): ";
//
//            char ch;
//            cin >> ch;
//            cin.ignore();
//
//            if (ch == 'y' || ch == 'Y')
//            {
//                saveFile();
//            }
//        }
//
//        Paragraph* p = head;
//
//        while (p != NULL)
//        {
//            Paragraph* temp = p->next;
//            delete p;
//            p = temp;
//        }
//
//        head = NULL;
//        cursor = NULL;
//
//        currentFile = "";
//        isModified = false;
//
//        cout << "File closed." << endl;
//    }
//
//    void typeText()
//    {
//        if (cursor == NULL)
//        {
//            cout << "No file open." << endl;
//            return;
//        }
//
//        cout << "Type text." << endl;
//        cout << "Type NEWPARA for new paragraph." << endl;
//        cout << "Type DONE to stop." << endl;
//
//        string input;
//
//        while (true)
//        {
//            getline(cin, input);
//
//            if (input == "DONE")
//            {
//                break;
//            }
//
//            if (input == "NEWPARA")
//            {
//                Paragraph* newPara = new Paragraph();
//
//                newPara->prev = cursor;
//                newPara->next = cursor->next;
//
//                if (cursor->next != NULL)
//                {
//                    cursor->next->prev = newPara;
//                }
//
//                cursor->next = newPara;
//                cursor = newPara;
//
//                cout << "New paragraph created." << endl;
//            }
//            else
//            {
//                cursor->text += input;
//                isModified = true;
//            }
//        }
//    }
//
//    void backspace()
//    {
//        if (cursor == NULL || cursor->text.empty())
//        {
//            cout << "Nothing to delete." << endl;
//            return;
//        }
//
//        cursor->text =
//            cursor->text.substr(0, cursor->text.length() - 1);
//
//        isModified = true;
//
//        cout << "Last character deleted." << endl;
//    }
//
//    void deleteWord()
//    {
//        if (cursor == NULL || cursor->text.empty())
//        {
//            cout << "Nothing to delete." << endl;
//            return;
//        }
//
//        int pos = cursor->text.find_last_of(' ');
//
//        if (pos == (int)string::npos)
//        {
//            cursor->text = "";
//        }
//        else
//        {
//            cursor->text =
//                cursor->text.substr(0, pos);
//        }
//
//        isModified = true;
//
//        cout << "Last word deleted." << endl;
//    }
//
//    void displayText()
//    {
//        if (head == NULL)
//        {
//            cout << "No content available." << endl;
//            return;
//        }
//
//        cout << "\n--- File Content ---" << endl;
//
//        Paragraph* p = head;
//
//        int i = 1;
//
//        while (p != NULL)
//        {
//            cout << "Paragraph " << i << ":" << endl;
//            cout << p->text << endl;
//
//            p = p->next;
//            i++;
//        }
//
//        cout << "--------------------" << endl;
//    }
//};
//
//int main()
//{
//    TextEditor editor;
//
//    editor.newFile();
//
//    int choice;
//
//    cout << "=== Simple Text Editor ===" << endl;
//
//    do
//    {
//        cout << "\n1. New File" << endl;
//        cout << "2. Open File" << endl;
//        cout << "3. Save File" << endl;
//        cout << "4. Save File As" << endl;
//        cout << "5. Close File" << endl;
//        cout << "6. Type Text" << endl;
//        cout << "7. Backspace" << endl;
//        cout << "8. Delete Word" << endl;
//        cout << "9. Display Text" << endl;
//        cout << "0. Exit" << endl;
//
//        cout << "Enter choice: ";
//
//        cin >> choice;
//        cin.ignore();
//
//        switch (choice)
//        {
//        case 1:
//            editor.newFile();
//            break;
//
//        case 2:
//            editor.openFile();
//            break;
//
//        case 3:
//            editor.saveFile();
//            break;
//
//        case 4:
//            editor.saveFileAs();
//            break;
//
//        case 5:
//            editor.closeFile();
//            break;
//
//        case 6:
//            editor.typeText();
//            break;
//
//        case 7:
//            editor.backspace();
//            break;
//
//        case 8:
//            editor.deleteWord();
//            break;
//
//        case 9:
//            editor.displayText();
//            break;
//
//        case 0:
//            cout << "Exiting editor." << endl;
//            break;
//
//        default:
//            cout << "Invalid choice." << endl;
//        }
//
//    } while (choice != 0);
//
//    return 0;
//}