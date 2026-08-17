#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class DocumentElement{
    public:
    virtual string render()=0;
};

class TextElement:public DocumentElement{
    private:
    string text;
    public:
    TextElement(string text){
        this->text=text;
    }
    string render() override{
        return "[Text: "+text+" ]"+"\n";
    }
};

class ImageElement:public DocumentElement{
    private:
    string image;
    public:
    ImageElement(string image){
        this->image=image;
    }
    string render() override{
        return "[Image: "+image+" ]"+"\n";
    }
};

class NewLineElement: public DocumentElement{
    public:
    string render() override{
        return "\n";
    }
};
class TabSpaceElement: public DocumentElement{
    public:
    string render() override{
        return "\t";
    }
};

class Document{
    private:
    vector<DocumentElement*> elements;
    public:
    void addElement(DocumentElement* element){
        elements.push_back(element);
    }

    string render(){
        string result;
        for(auto el:elements){
            result+=el->render();
        }
        return result;
    }

};

class Persistence{
    public:
    virtual void save(string data)=0;
};
class FileStorage: public Persistence{
    public:
    void save(string data) override{
        ofstream file("Document.txt");
        if(file.is_open()){
            file<<data;
            file.close();
            cout<<"saved to file"<<endl;
        }else{
            cout<<"error saving to file"<<endl;
        }
    }
};

class DBStorage: public Persistence{
    public:
    void save(string data) override{
        cout<<"saved to db"<<endl;
    }
};

class DocumentEditor{
    private:
    Document *document;
    Persistence* storage;
    string renderedDocument;

    public:
    DocumentEditor(Document* document,Persistence* storage){
        this->document=document;
        this->storage=storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }
    void addImage(string image){
        document->addElement(new TextElement(image));
    }
    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    void addTab(){
        document->addElement(new TabSpaceElement());
    }

    void saveDocument(){
        storage->save(renderDoc());
    }
    string renderDoc(){
        if(renderedDocument.empty()){
              renderedDocument=document->render();
        }
        return renderedDocument;
    }
};

int main()
{
    Document* document=new Document();
    Persistence* storage=new FileStorage();
    DocumentEditor* editor=new DocumentEditor(document,storage);

    editor->addText("hello world!");
    editor->addNewLine();
    editor->addTab();
    editor->addImage("image.png");
    editor->saveDocument();
    cout<<editor->renderDoc()<<endl;
    return 0;
}