// Compatible file (Epic Store):
// $ shasum ./Little\ Inferno
// 5bb3ab2e6416217d33d7964023bbc54b2cac946f  ./Little Inferno

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{
    fstream victim;

    victim.open("Little Inferno",  ios::out | ios::in | ios::binary);

    // Thank you Hop*er.
    // Function name: ProfileGetMoney(eItemMoneyType)
    victim.seekp(0x058c60);

    // this leads to unlimited money and coupons :)
    // mov rax, 0xffff
    const unsigned char magic_bytes[5] = { 0xb8, 0xff, 0xff, 0x00, 0x00 }; // 0xb8, 0x9f, 0x86, 0x01, 0x00, 0x90};
    victim.write((char *) &magic_bytes, sizeof(magic_bytes));

    victim.close();

    cout << "You... human.. has been h4cked! Enjoy the best game!" << endl;
    return 0;
}
