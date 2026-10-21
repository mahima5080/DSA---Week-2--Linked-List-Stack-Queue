#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
private:
    string currentText;
    stack<string> undoStack;
    stack<string> redoStack;

public:
    TextEditor() { currentText = ""; }

    void write(const string& newText) {
        undoStack.push(currentText); // Save state before change
        while (!redoStack.empty()) redoStack.pop(); // Clear redo stack on new action
        currentText += newText;
        cout << "📝 Appended text: \"" << newText << "\"" << endl;
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "⚠️ Nothing to undo!" << endl;
            return;
        }
        redoStack.push(currentText); // Save state to redo stack
        currentText = undoStack.top();
        undoStack.pop();
        cout << "🔄 Undo performed!" << endl;
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "⚠️ Nothing to redo!" << endl;
            return;
        }
        undoStack.push(currentText); // Save current state to undo stack
        currentText = redoStack.top();
        redoStack.pop();
        cout << "🔁 Redo performed!" << endl;
    }

    void showText() {
        cout << "------------------------------------------" << endl;
        cout << "Current Document Text: \"" << currentText << "\"" << endl;
        cout << "------------------------------------------" << endl;
    }
};

int main() {
    TextEditor editor;

    cout << "==========================================" << endl;
    cout << "   UNDO-REDO TEXT EDITOR SIMULATION       " << endl;
    cout << "==========================================" << endl;

    editor.write("Hello ");
    editor.write("World!");
    editor.showText();

    editor.undo();
    editor.showText();

    editor.redo();
    editor.showText();

    editor.write(" Welcome to DSA.");
    editor.showText();

    editor.undo();
    editor.showText();

    return 0;
}
