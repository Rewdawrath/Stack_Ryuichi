#include <iostream>
using namespace std;
#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  int match;
  int kuay,hum;
  char c;
  for(int j=1;j<argc;j++){
    Stack s;
    match=1;
    kuay=0;
    hum=0;
    for(int i=0;i<strlen(argv[j]);i++){
    switch(argv[j][i])
    {
      case '[':
        s.push(argv[j][i]);
        kuay--;
        break;

      case '{':
        s.push(argv[j][i]);
        hum--;
        break;

      case '}':
        c=s.pop();
        kuay++;
        if(c!='{'){
          match=0;
        }
        break;
      case ']':
        c=s.pop();
        hum++;
        if(c!='['){
          match=0;
        }
        break;
      
      default: break;
      }
    }
    if(match==1){
    cout<<"match"<<endl;
    }else if(match==0 && kuay>0 && hum<0){
    cout<<"too much open parenthesis"<<endl;
    }else if(match==0 && hum>0 && kuay<0){
    cout<<"too much close parenthesis"<<endl;
    }else if(match==0 && kuay==0 && hum==0){
    cout<<"not match"<<endl;
    }
    
  }

  }

