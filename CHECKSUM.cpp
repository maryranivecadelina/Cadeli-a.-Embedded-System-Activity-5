#include <bits/stdc++.h>
using namespace std;

string Ones_complement(string data)
{
    for (int x = 0; x < data.length(); x++) {
        if (data[x] == '0')
            data[x] = '1';
        else
            data[x] = '0';
    } 
    return data;
}

string checksum(string data, int block_size)
{
    int a = data.length();
    if (a % block_size != 0) {
        int pad_size = block_size - (a % block_size);
        for (int x = 0; x < pad_size; x++) {
            data = '0' + data;
        }
    }
    string result = "";
    for (int x = 0; x < block_size; x++) {
        result += data[x];
    }

    for (int x = block_size; x < a; x += block_size) {
        string next_block = "";
 
        for (int r = x; r < x + block_size; r++) {
            next_block += data[r];
        }
        
        string additions = "";
        int sum = 0, carry = 0;
        for (int t = block_size - 1; t >= 0; t--) {
            sum += (next_block[t] - '0')
                   + (result[t] - '0');
            carry = sum / 2;

            if (sum == 0) {
                additions = '0' + additions;
                sum = carry;
            }
            else if (sum == 1) {
                additions = '1' + additions;
                sum = carry;
            }
            else if (sum == 2) {
                additions = '0' + additions;
                sum = carry;
            }
            else {
                additions = '1' + additions;
                sum = carry;
            }
        }
 
        string final = "";
 
        if (carry == 1) {
            for (int l = additions.length() - 1; l >= 0;
                 l--) {
                if (carry == 0) {
                    final = additions[l] + final;
                }
                else if (((additions[l] - '0') + carry) % 2
                         == 0) {
                    final = "0" + final;
                    carry = 1;
                }
                else {
                    final = "1" + final;
                    carry = 0;
                }
            }
 
            result = final;
        }
        else {
            result = additions;
        }
    }
 
    return Ones_complement(result);
}
 
bool checker(string sent_message, string rec_message, int block_size)
{
    string sender_checksum = checksum(sent_message, block_size);
    string receiver_checksum = checksum(rec_message + sender_checksum, block_size);
 
    if (count(receiver_checksum.begin(), receiver_checksum.end(), '0') == block_size) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    string sent_v;
    string receive_v;
    int block_size = 8;
 
	cout<< "Enter sent message  ";
	cin>> sent_v;

	cout<< "Enter receive message  ";
	cin>> receive_v; 
	
    if (checker(sent_v, receive_v, block_size)) {
        cout << "No Error";
    }
    else {
        cout << "Error";
    }
 
    return 0;
}