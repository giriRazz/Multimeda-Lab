#include <bits/stdc++.h>
using namespace std;

void encoding(){

    ifstream textfile("textfileself.txt");
    string content;
    content.assign( (istreambuf_iterator<char>(textfile) ),
                       (istreambuf_iterator<char>() ) );

    ofstream compressed;
    compressed.open("compressedself.txt");

    cout<<"string file is: "<<content<<endl;
    int counter =0;
    for(int i=0; i<content.length()-1; i++){

       if(content[i]!=' ' && content[i]!='\n'){
       if(content[i+1]==content[i]){
          counter++;
       }else{
          counter++;
          compressed<<content[i]<< " "<<counter<<" ";
          counter = 0;
       }
       }
    }
    cout<<endl<<endl;

}

void decoding(){

    ifstream textfile("compressedself.txt");
    string content;
    content.assign( (istreambuf_iterator<char>(textfile) ),
                       (istreambuf_iterator<char>() ) );
    ofstream decompressed;
    decompressed.open("decompressedself.txt");

    cout<<" compressed file : "<<content<<endl;
    int j=2,k;
    string s = content;
    cout<<" s: "<<s[j]<<endl;

    for(int i=0; i<content.length(); i= i+4){

            char value = (char)(s[j]);
            int real = (int)(value);
            cout<<"s[j]: "<<real<<endl;

            j=j+4;

        }


}

int main(int argc, char const *argv[]){


    encoding();
    decoding();


return 0;

}
