#include<iostream>
using namespace std;
int x;
int main()
{
  struct students
  {
    int x;
    char name[30];
    int age;
    int marks;
  };
  cin>>x;
  struct students s1 = {x,"kartik",19,95};
  
  cout << s1.x<< " \n"<< s1.name << " \n" << s1.age << " \n" << s1.marks << endl;
  return 0;
}
 
