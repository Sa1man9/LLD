#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

class DocumentEditor{
    vector<string>elements;
    string renderedDocument;
    public:
    void addText(string text){
        elements.push_back(text);
    }
    void addImages(string image){
        elements.push_back(image);
    }
    string renderDocument(){
        if(renderedDocument.empty()){
            string result;
            for(auto el:elements){
                string curr;
                if(el.length()>4 && (el.substr(el.length()-4)==".jpg" || el.substr(el.length()-4)==".png")){
                    curr="[Image: "+el+" ]"+"\n";
                }else{
                    curr="[Text: "+el+" ]"+"\n";
                }
                result+=curr+"\n";
            }
        }
        return renderedDocument;
    }
    void save(){
        ofstream file("Document.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"file saved"<<endl;
        }else{
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};

int main()
{
    DocumentEditor editor;
    editor.addText("hey there");
    editor.addImages("image.png");

    cout<<editor.renderDocument()<<endl;
    editor.save();
    return 0;
}