#include<iostream>
using namespace std;
template<class T>
class SeqList
{
private:
    T * elements;
    int maxLength;
    int n;
public:
    SeqList(int nSize)
    {
        maxLength=nSize;
        elements=new T[maxLength];
        n=0;
    }
    void Insert(T x)
    {
        if(n>=maxLength)
            cout<<"out of bounds"<<endl;
        elements[n]=x;
        n++;
    }
    void Delete(T x)
    {
        for(int i=0;i<n;i++)
        {
            if(elements[i]==x)
            {
                for(int j=i;j<n;j++)
                    elements[j]=elements[j+1];
                n--;
                i--;
            }
        }
    }
    void outPut()
    {
        for(int i=n-1;i>=0;i--)
        {
            cout<<elements[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    cin>>n;
    SeqList<int> list(n);
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        list.Insert(x);
    }
    cin>>x;

    int size;
    cin>>size;
    SeqList<char> clist(size);
    char ch;
    for(int k=0;k<size;k++)
    {

        cin>>ch;
        clist.Insert(ch);
    }
    cin>>ch;

    int size2;
    cin>>size2;
    SeqList<float> flist(size2);
    float value;
    for(int m=0;m<size2;m++)
    {
        cin>>value;
        flist.Insert(value);
    }
    cin>>value;

    list.outPut();
    list.Delete(x);
    list.outPut();
    clist.outPut();
    clist.Delete(ch);
    clist.outPut();
    flist.outPut();
    flist.Delete(value);
    flist.outPut();
    return 0;
}
