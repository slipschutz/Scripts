










#include <string>
#include <iostream>
using namespace std;

void MeldForkedFiles(string fileName ){


  std::size_t found = fileName.find("fork");
  
  if (found == std::string::npos ){
    cout<<"Input must contain 'fork' to be a good filename"<<endl;
    return;
  }


  string left= fileName.substr(0,found);
  string right= fileName.substr(found+4,fileName.size());
  cout<<left<<endl;
  cout<<right<<endl;


}
