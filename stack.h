#ifndef stack_h
#define  stack_h
#include "node.h"
#include <iostream>
using namespace std;

class Stack{
private:
	 NodePtr top;
	int size;
public:
    Stack(NodePtr = NULL);
    ~Stack();
    int pop();
    void push(int);
    int get_size(){return size;}
};

Stack::Stack(NodePtr t){
  if(t) {
    top=t;
    size=1;
  }
 else{
   top=NULL;
	 size=0;
   }
}
void Stack::push(int x){
   NodePtr new_node=new NODE(x);
  //1
  if(new_node){
	 	new_node->set_next(top); //2
    top=new_node;//3
    ++size;//4
      
   }
 else cout<<"No memory left for new nodes"<<endl;
		 // Left missing for exercises…
}
int Stack::pop(){
 	   NodePtr t=top;
		int value;		
	 if(t)	{
    
     value=t->get_value();
     top=t->get_next();
	// Left missing for exercises
      delete t;
     --size;
     return value;
     }
    
		cout<<"Empty stack"<<endl;
   return 0;
	}
Stack::~Stack(){
   cout<<"Clearing all stacks"<<endl;
  	int i;
  NodePtr t=top;
for(i=0;i<size;i++){
     top=top->get_next();
      delete t;
      t=top;
   	// Left missing for exercises
  }

}



#endif