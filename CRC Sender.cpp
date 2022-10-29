#include <iostream>
using namespace std;

int main(){ 
string mssg,crc,encoded="";

cout <<"Enter the mssg: ";
getline(cin,mssg);

cout <<"Enter the divisor: ";
getline(cin,crc);

int m=message.length(),n=crc.length();
encoded+=mssg;

for(int a=1;a<=n-1;a++)
    encoded+='0';
    for(int a=0;a<=encoded.length()-n; ){
        for(int j=0;j<n; j ++)
            encoded [a+j] = encoded[a+j] == crc[j]? '0':'1';
            for(;a<encoded.length() && encoded[a]!='1';i++); 
    }
    cout << "Final Encoded CRC:" << mssg+encoded.substr(encoded.length()-n+1);
    return 0;
}