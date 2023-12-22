#include<iostream>

using namespace std;

    int full = 0;
    int emptyB = 10;
void produce(){
    if(full!=10){
    cout<<"Producer produced no. "<<full+1<<" item\n"<<endl;
    full++;
    emptyB--;
        
    }else cout<<"The buffer is full. can't produce no more\n"<<endl;
}

void consume(){
    if(emptyB!=10){
        cout<<"consumer consumed no. "<<full<<" item\n"<<endl;
        full--;
        emptyB++;
    }else cout<<"The buffer is empty. can't consume no more\n"<<endl;
}
int main(){



    int op;
    do{
        cout<<"1. Produce the item "<<endl;
        cout<<"2. Consume the item "<<endl;
        cout<<"3. Quit the application"<<endl;
    cin>>op;

        switch (op)
        {
        case 1:
            produce();
            break;
        
        case 2:
            consume();
            break;
        case 3:
        cout<<"Application ended"<<endl;
            exit(0);
            break;

        default:
        cout<<"Invalid input"<<endl;
            break;
        }
        

    } while(op!=3);
    
}