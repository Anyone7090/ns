#include<iostream>
#include<string.h>
using namespace std;
string encrypt(string plain_text,int key)
{
string cipher_text="";
for(int i=0;i<plain_text.size();i++)
{
if(isupper(plain_text[i]))
{
cipher_text+=char(int(plain_text[i]+key-65)%26+65);
}
else
{
cipher_text+= char(int(plain_text[i]+key-97)%26+97);
}
}
return cipher_text;
}
string decrypt(string cipher_text,int key)
{
string plain_text="";
for(int i=0;i<cipher_text.size();i++)
{
if(isupper(cipher_text[i]))
{
plain_text+=((int(cipher_text[i]-key-65)%26+26)%26+65);
}
else
{
plain_text+=char((int(cipher_text[i]-key-97)%26+26)%26+97);
}
}
return plain_text;
}
int main()
{
string plain_text;
cout<<"enter plain text:";
cin>>plain_text;
int key;
cout<<"enter key:";
cin>>key;
string cipher_text= encrypt(plain_text,key);
cout<<"\nEncryption:\n";
cout<<"Cipher:"<<cipher_text<<endl;
cout<<"\nDecryption:\n";
cout<<"plain text:"<<decrypt(cipher_text,key)<<endl;
}
