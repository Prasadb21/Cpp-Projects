#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// TextBuffer is a vector of strings representing lines of text
using TextBuffer = std::vector<std::string>;

class TextEditor
{
    public:
        void run(); // method to start the main loop
    
    private:
        void display() const; // method to display current text
        void openFile(const std::string& fileName);  // method to open and read file
        void saveFile(const std::string& fileName) const; // method to save current content of file
        void edit();  // method to edit content 
        void insertLine(const std::string& line , int position);  // method to insert a line at specific position
        void deleteLine(int position);  // method to delete line from specific position
        
        // added functionality 

        void undo();                    // method to undo the last operation 
        void redo();                    // method to redo the last undone operation
        void search(const std::string& keyword) const;  // method to search for a keyword
        void replace(const std::string& oldWord , const std::string& newWord);  // Method for replacing the old word woth new one


        TextBuffer lines;      // Vector to store the lines of text
        std::vector<TextBuffer> history; // Vector to store history for undo and redo
        size_t historyIndex = 0; // Index to track current state in history


        std::string getInput(const std::string& prompt) const;  // method to get string input from user
        int getIntegerInput(const std::string& prompt) const;   // method to get integer input from user


};

// main loop of text editor

void TextEditor::run()
{
    while(true)
    {
        std::string command = getInput("Give choice (open, save, edit, insert, delete, undo , redo , search , replace, quit): \n");  // get choice from user
        
        if(command == "open")
        {
            std::string fileName = getInput("Enter The Filename: \n");  // get he file name from user to create it
            openFile(fileName);
        }
        else if(command == "save")
        {
            std::string fileName = getInput("Enter Filename to save : \n");
            saveFile(fileName);
        }
        else if (command == "edit") 
        {
            edit();  // Call the edit method
        }
        else if(command == "insert")
        {
            std::string line = getInput("Enter line to insert: \n");  // Get the line to insert
            int position = getIntegerInput("Enter position to insert at: \n");

            insertLine(line , position);
        }
        else if (command == "delete")
        {
            int position = getIntegerInput("Enter line number to delete: ");  // Get the position to delete
            deleteLine(position);  // Call deleteLine method with the position
        }
        else if (command == "undo")
        {
            undo();
        }
        else if (command == "redo") 
        {
            redo();
        } 
        else if (command == "search") 
        {
            std::string keyword = getInput("Enter keyword to search: ");
            search(keyword);
        } 
        else if (command == "replace") 
        {
            std::string oldWord = getInput("Enter word to replace: ");
            std::string newWord = getInput("Enter new word: ");
            replace(oldWord, newWord);
        } 
        else if (command == "quit") 
        {
            break;
        } 
        else 
        {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }
}


// Method to display the current content
void TextEditor::display() const {
    for (size_t i = 0; i < lines.size(); ++i) {
        std::cout << i + 1 << ": " << lines[i] << std::endl; // Display each line with line number
    }
}

// Method to open and read a file
void TextEditor::openFile(const std::string& filename) {
    std::ifstream file(filename); // Open file stream
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl; // Display error if file cannot be opened
        return;
    }
    lines.clear(); // Clear existing content
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line); // Read each line and add to lines vector
    }
    file.close(); // Close file stream
    display(); // Display updated content
}

// Method to save the current content to a file
void TextEditor::saveFile(const std::string& filename) const {
    std::ofstream file(filename); // Open file stream
    if (!file) {
        std::cerr << "Error saving file: " << filename << std::endl; // Display error if file cannot be saved
        return;
    }
    for (const std::string& line : lines) {
        file << line << std::endl; // Write each line to file
    }
    file.close(); // Close file stream
}

// edit the content by adding new lines
void TextEditor::edit()
{
    std::cout << "Enter lines of text (type 'END' to finish):" << std::endl;  // Prompt the user
    std::cin.ignore(); // Ignore the newline character left in the input buffer

    std::string line;
    TextBuffer newLines = lines; // Save current state for history
    while(true)
    {
        std::getline(std::cin , line);  // get a line from the user
        if(line == "END") break; // check if user has typed END

        newLines.push_back(line);  // add the line to the vector

    }

    history.resize(historyIndex + 1); // Clear redo history
    history.push_back(newLines); // Store edited state in history
    ++historyIndex; // Move history index forward
    lines = newLines; // Update current lines
    display(); // Display updated content

}

// insert a line at a specific position

void TextEditor::insertLine(const std::string& line, int position)
{
    if(position < 1 || position > static_cast<int>(lines.size() + 1))
    {
        std::cerr << "Invalid position!" << std::endl;  // Print an error message
        return;
    }

    TextBuffer newLines = lines; // Save current state for history
    newLines.insert(newLines.begin() + position - 1, line); // Insert line at specified position
    history.resize(historyIndex + 1); // Clear redo history
    history.push_back(newLines); // Store edited state in history
    ++historyIndex; // Move history index forward
    lines = newLines; // Update current lines
    display(); // Display updated content

}

// delete a line at specified position

void TextEditor::deleteLine(int position)
{
    if (position < 1 || position > static_cast<int>(lines.size()))   // Check if the position is invalid
    {
        std::cerr << "Invalid position!" << std::endl;  // Print an error message
        return;
    }

    TextBuffer newLines = lines; // Save current state for history
    newLines.erase(newLines.begin() + position - 1); // Erase line at specified position
    history.resize(historyIndex + 1); // Clear redo history
    history.push_back(newLines); // Store edited state in history
    ++historyIndex; // Move history index forward
    lines = newLines; // Update current lines
    display(); // Display updated content

}

// Method to search for a keyword in the content
void TextEditor::search(const std::string& keyword) const
{
    bool found = false;
    for(size_t i = 0; i < lines.size(); i++)
    {
        if(lines[i].find(keyword) != std::string::npos)
        {
            std::cout << "Found at line " << i + 1 << ": " << lines[i] << std::endl; // Display line containing keyword
            found = true;
        }
    }
    if (!found) 
    {
        std::cout << "Keyword not found." << std::endl; // Display message if keyword is not found
    }
}

// Method to replace occurrences of a word in the content
void TextEditor::replace(const std::string& oldWord, const std::string& newWord) {
    TextBuffer newLines = lines; // Save current state for history
    for (std::string& line : newLines) {
        size_t pos = 0;
        while ((pos = line.find(oldWord, pos)) != std::string::npos) {
            line.replace(pos, oldWord.length(), newWord); // Replace oldWord with newWord
            pos += newWord.length(); // Move position past replaced word
        }
    }
    history.resize(historyIndex + 1); // Clear redo history
    history.push_back(newLines); // Store edited state in history
    ++historyIndex; // Move history index forward
    lines = newLines; // Update current lines
    display(); // Display updated content
}

// get the string input from user

std::string TextEditor::getInput(const std::string& prompt) const
{   
    std::cout << prompt; // print the prompt
    std::string input;
    std::cin >> input; // get the input from user

    return input;
}

// Get integer input from the user
int TextEditor::getIntegerInput(const std::string& prompt) const {
    std::cout << prompt;  // Print the prompt
    int input;
    std::cin >> input;  // Get the input from the user
    return input;
}

// Method to undo the last operation
void TextEditor::undo() {
    if (historyIndex > 0) {
        --historyIndex; // Move to previous state
        lines = history[historyIndex]; // Restore previous state
        display(); // Display updated content
    } else {
        std::cerr << "No operations to undo!" << std::endl; // Display error if no operations to undo
    }
}

// Method to redo the last undone operation
void TextEditor::redo() {
    if (historyIndex < history.size() - 1) {
        ++historyIndex; // Move to next state
        lines = history[historyIndex]; // Restore next state
        display(); // Display updated content
    } else {
        std::cerr << "No operations to redo!" << std::endl; // Display error if no operations to redo
    }
}

int main()
{
    TextEditor editor; // create a texteditor object

    editor.run(); // start the editor
    return 0;
}








