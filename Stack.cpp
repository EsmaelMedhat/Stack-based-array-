#include <iostream>
using namespace std;
template<class type>
class Stack{
public:
Stack(int array_size){
size=array_size;
length=0;
data=new type[size];
}
~Stack(){
delete []data;
}
void push(type new_data){
if(length<size){
  data[length]=new_data;
length++;
}
else{ cout<<"full array\n";}
}
void pop(){
if(length>0){
length--;
}
else{
cout<<"array is empty\n";
}
}
type peek(){
return data[length-1];
}
void display(){
cout<<"\n*****all element*******\n";
int n=0;
for(int i=length-1;i>=0;i--){
n++;
cout<<"item  "<<n<<":   "<<data[i]<<endl;
}
}
bool isempty(){
return length==0;
}
int isfind(type value){
for(int i=0;i<length;i++){
if(value==data[i])
return i;
}
return -1;
}
void replace(type new_item,type old_item){
if(isfind(old_item)!=-1)
data[isfind(old_item)]=new_item;
else{
 cout<<"not found this item";
}
}
void swap(Stack &other){
Stack swap=other;
other.data=data;
other.length=length;
other.size=size;
data=swap.data;
length=swap.length;
size=swap.size;
}
private:
int size;
int length;
type *data;
};
int main()
{
 return 0;
}
