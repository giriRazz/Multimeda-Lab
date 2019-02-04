#include <bits/stdc++.h>
using namespace std;

void encoding(){

   /* ifstream textfile("textfileself.txt");
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
       else{
           if(content[i+1] == content[i]){
             counter++;
            }
          else{
             counter++;
             compressed<<"s"<< " "<<counter<<" ";
             counter = 0;
           }
       }

    }
    cout<<endl<<endl;   */

    ifstream textfile;
    textfile.open("textfileself.txt");

    ofstream compressed;
    compressed.open("compressedself.txt");

        char ch1, ch2;
		textfile >> ch1 >> noskipws;
		int i = 1;
		while(textfile >> ch2 >> noskipws){
			if(ch2==ch1)
				i++;
			else{
				compressed << int(ch1) << " " << i << " " ;
				i = 1;
			}
			ch1 = ch2;
		}
		compressed << int(ch2) << " " << i ;

		textfile.close();
		compressed.close();


}

void decoding(){

    ifstream compressed;
    compressed.open("compressedself.txt");

    ofstream decompressed;
    decompressed.open("decompressedself.txt");


    int i,j,k;

    while(compressed >> i >> k){
        char ch = i;
        for(int j=0; j<k; j++){
            decompressed << ch;
        }
    }
}

int main(int argc, char const *argv[]){

    encoding();
    decoding();

return 0;

}
