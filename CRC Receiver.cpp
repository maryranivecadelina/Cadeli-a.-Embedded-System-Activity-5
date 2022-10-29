#include <iostream>
using namespace std;

int main(){
string crc, decoded;

cout << "Enter the message: ";
getline(cin, decoded);

cout << "Enter the divisor: ";
getline(cin, crc);

for(int a=0; a <= decoded.length() - crc.length(); ){
    for(int j=0; j < crc.length(); j++)
        decoded[a+j] = decoded[a+j] == crc[j] ? '0':'1';
        for(; a < decoded.length() && decoded[a] != '1'; i++);
}
	for (char a : decoded.substr(decoded.length() - crc.length() ) )
		if(a != '0'){
		cout <<"Status: Error communication";
	return 0;
}
		cout <<"Status: No error!";
	return 0;
}