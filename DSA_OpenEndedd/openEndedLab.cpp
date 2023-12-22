#include<iostream>
using namespace std;

int main()
{
    //cout current time
    time_t t = time(0);
    struct tm * now = localtime( & t );
    cout << "Current time: " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;

    int count =0;
    for (int i = 0; i < 10000000000; i++) {
    count++;
  }
  cout<<"\n\ncounter = "<<count<<endl;
    cout << "Current time: " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << endl;
    return 0;
}

