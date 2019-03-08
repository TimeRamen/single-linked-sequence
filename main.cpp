#include <iostream>

using namespace std;
const int LINELEN = 20;
template <typename Key,typename Info>
class Sequence{
private:
    struct element{
        Key key;
        Info info;
        element *next;
    };
    element *head;
    int number;
    void removeAllElements(){
    element *etr = head;
    while(etr){
        etr = etr->next;
        delete head;
        head = etr;
    }
    number = 0;
    };
    void copyAllElements(const Sequence<Key,Info>& x){
    element* xtr = x.head;
    element* etr = head;
    while(etr){
        if(!etr->next)
            break;
        etr = etr->next;
    }
    while(xtr){
        element* ntr = new element;
        if(!ntr){
            cerr<<"allocation memory failure"<<endl;
            break;
        }
        ntr->key = xtr->key;
        ntr->info = xtr->info;
        ntr->next = NULL;
        if(!head)
            head = ntr;
        else
            etr->next = ntr;
        etr = ntr;
        xtr = xtr->next;
    number += x.number;
    }};
public:
    Sequence(){
    head = NULL;
    number = 0;
    };
    ~Sequence(){
    removeAllElements();
    };
    Sequence(const Sequence<Key,Info>& x){
    head = NULL;
    number = 0;
    copyAllElements(x);
    };
    Sequence<Key,Info>& operator=(const Sequence<Key,Info>& x){
    if(this==&x)
        return *this;
    removeAllElements();
    copyAllElements(x);
    return *this;
    };

    Sequence<Key,Info> Shuffle(const Sequence<Key,Info>&S1,int start1,int len1,const Sequence<Key,Info>&S2,int start2, int len2, int num){
        //checking if anything is wrong parameter wise
        try{
            bool n = 0;
        if(len1<0||len2<0||start1>S1.number||start2>S2.number||num<0){
            throw n;
        }
        }catch(bool){
        cerr<<"Parameters are wrong";
        }
        //start
    Sequence<Key,Info> *result;
    result = new Sequence;
    int C = start1;//checks the current position for 1st sequence
    int D = start2;//checks the current position for 2nd sequence
    int cont = 0;//counter for both sequences
    element* xtr = S1.head;//element of first list
    element* ytr = S2.head;//element of second list
    while(cont!=start1){//checks when counter reaches the starting position
        xtr = xtr->next;//element increments
        cont++;//counter increments
    }//end of while loop
    cont = 0;
    while(cont!=start2){//checks when counter reaches the starting position
        ytr = ytr->next;//element increments
        cont++;//counter increments
    }//end of while loop
    for (int j=0;j<num;j++){//start of for loop for the third sequence
        for (int k=0;k<len1;k++){//nested for loop for the first sequence
           if (C<S1.number){//current element number less than entire list length
                //cout<<xtr->key<<"   ";
                result->insertElement(xtr->key,xtr->info);
                C++;
                xtr = xtr->next;
           }
        }
        //cout<<endl;
        for (int l=0;l<len2;l++){//nested for loop for the second sequence
            if (D<S2.number){//current element number less than entire list length
                //cout<<ytr->key<<"   ";
                result->insertElement(ytr->key,ytr->info);
                D++;
                ytr = ytr->next;
            }
        }
        //cout<<endl;
    }
    return *result;
    };
    void insertElement(const Key& x, const Info& y){
    element *ptr = NULL;
    element *ntr = new element;
    ntr->key = x;
    ntr->info = y;
    ntr->next = NULL;
    if (head==NULL)
        head = ntr;
    else{
        ptr = head;
            while(ptr->next)
                ptr = ptr->next;
            ntr->next = ptr->next;
            ptr->next = ntr;
        }
    number++;
    };
    element getHead(){
    return head;
    }
    void setHead(element* e){
    head = e;
    }
    bool isEmpty() const{
    return number==0;
    };
    int numberOfElements()const{
    return number;
    };
    Sequence<Key,Info> operator+(const Sequence<Key,Info>& x)const{
    Sequence<Key,Info> result;
    result.copyAllElements(*this);
    result.copyAllElements(x);
    return result;
    };
    void reverse(){//(SET<T>& x){
    element *curr = head;
    element *next;
    head = NULL;
    while(curr){
        next = curr->next;
        curr->next = head;
        head = curr;
        curr = next;
    }
    }
    void print(ostream& os) const{
    element *etr = head;
    int count = 0;
    while(etr){
        os << etr->key;
        if(etr->next)
            os << ", ";
        count++;
        if(count==LINELEN){
            count = 0;
            os << endl;
        }
        etr = etr->next;
    }
    cout<<endl;
    element *ytr = head;
    count = 0;
    while(ytr){
        os << ytr->info;
        if(ytr->next)
            os << ", ";
        count++;
        if(count==LINELEN){
            count = 0;
            os << endl;
        }
        ytr = ytr->next;
    }
    return;
    };
};

    template <typename Key,typename Info>
    ostream& operator<< (ostream& os, const Sequence<Key,Info>& x){
    x.print(os);
    return os;
    }

//template<typename key,typename info>
//Sequence<key,info> shuffle(const Sequence<key,info>&S1,int start1,int len1,const Sequence<key,info>&S2,int stat2, int len2, int sum);

//S1 = 1,2,3,4,5,6...

//S2 = 10,20,30...

//S3 = shuffle(S1.2.3.S2.3.2.2)
//S3 = 3,4,5,   40,50,   6,7,8,   60,70

//should take two sequences to create a third one
int main()
{
    Sequence<int,int> S1;
    S1.insertElement(1,1);
    S1.insertElement(2,1);
    S1.insertElement(3,1);
    S1.insertElement(4,1);
    S1.insertElement(5,1);
    S1.insertElement(6,1);
    S1.insertElement(7,1);
    S1.insertElement(8,1);
    cout<<"Sequence 1: \n";
    cout<<S1<<endl;
    Sequence<int,int> S2;
    S2.insertElement(10,1);
    S2.insertElement(20,1);
    S2.insertElement(30,1);
    S2.insertElement(40,1);
    S2.insertElement(50,1);
    S2.insertElement(60,1);
    S2.insertElement(70,1);
    S2.insertElement(80,1);
    cout<<"Sequence 2: \n";
    cout<<S2<<endl;
    //cout<<ABC;
    Sequence<int,int> S3;
    //S3.insertElement(1,1);
    //S3.Shuffle(S1,2,3,S2,3,2,2);
    cout<<"Sequence 3: Shuffle(S1,2,3,S2,3,2,2) \n";
   //cout<<S3.Shuffle(S1,2,3,S2,3,2,2);
   S3 = S3.Shuffle(S1,2,3,S2,-1,2,2);
   cout<<S3<<endl;

    return 0;
}
