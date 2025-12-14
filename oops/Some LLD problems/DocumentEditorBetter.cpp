#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Abstraction for document elements
class DocumentElement
{
public:
    virtual string render() = 0;
};

// classes extending document elements in future there can be 100 more

class TextElement : public DocumentElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }

    string render() override
    {
        return text;
    }
};

class ImageElement : public DocumentElement
{
private:
    string imagePath;

public:
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }

    string render() override
    {
        return "[Image] : " + imagePath;
    }
};

// Document Class

class Document
{
private:
    vector<DocumentElement *> documentElements;

public:
    void addElement(DocumentElement *element)
    {
        documentElements.push_back(element);
    }

    // render
    string render()
    {
        string result;
        for (auto element : documentElements)
        {
            result = result + element->render();
        }
        return result;
    }
};

// Persistence Interface
class Persistence
{
public:
    virtual void save(string data) = 0;
};

// FileStorage implementation of Persistence
class FileStorage : public Persistence
{
public:
    void save(string data) override
    {
        ofstream outFile("document.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }
        else
        {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

class DBStorage : public Persistence
{
public:
    void save(string str) override
    {
        // save to db
    }
};

// DocumentEditor class managing client interactions
class DocumentEditor
{
private:
    Document *document;
    Persistence *storage;
    string renderedDocument;

public:
    DocumentEditor(Document *document, Persistence *storage)
    {
        this->document = document;
        this->storage = storage;
    }

    void addText(string text)
    {
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath)
    {
        document->addElement(new ImageElement(imagePath));
    }

    string renderDocument()
    {
        return document->render();
    }

    void saveDocument()
    {
        storage->save(renderDocument());
    }
};

// Client usage example
int main()
{
    Document *document = new Document();
    Persistence *persistence = new FileStorage();

    DocumentEditor *editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addText("This is a real-world document editor example.");
    editor->addText("Indented text after a tab space.");
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveDocument();

    return 0;
}