#include <iostream>
#include <bitset>
#include <iomanip>
#include <cassert>
using namespace std;

// Function to print the bits of a float number
/**
 * 打印浮点数的二进制表示(IEEE 754 单精度/双精度浮点数)
 *
 * 本函数旨在展示浮点数在内存中的存储方式，通过将其内存内容解释为整数并转换为二进制字符串来实现
 * 此外，还展示了浮点数的十六进制表示，以便更好地理解其内存布局
 *
 * @param number 浮点数，其二进制和十六进制表示将被打印
 */
void printFloatBits(float number)
{
    // 将浮点数的内存视图转换为整数类型
    uint32_t bits = *reinterpret_cast<uint32_t *>(&number);
    // 双精度
    // uint64_t bits64 = *reinterpret_cast<uint64_t *>(&number);

    // 使用 bitset 将整数转换为二进制字符串
    bitset<32> binary(bits);

    // 打印浮点数的值
    cout << "Float value: " << number << endl;

    // 打印二进制表示
    cout << "Binary representation: " << binary << endl;

    // 打印十六进制表示
    cout << "Hexadecimal representation: 0x" << hex << setw(8) << setfill('0') << bits << endl
         << endl;
}

// Unit test for the printFloatBits function
// This function tests various float values to ensure correct bit representation
void testPrintFloatBits()
{
    // Test case: normal float number
    float normalFloat = 3.14f; // A typical float value
    cout << "Testing with normal float value: " << normalFloat << endl;
    printFloatBits(normalFloat);

    // Test case: zero float number
    float zeroFloat = 0.0f; // The float representation of zero
    cout << "Testing with zero float value: " << zeroFloat << endl;
    printFloatBits(zeroFloat);

    // Test case: negative float number
    float negativeFloat = -3.14f; // A negative float value
    cout << "Testing with negative float value: " << negativeFloat << endl;
    printFloatBits(negativeFloat);

    // Test case: smallest positive normal float number
    float smallestPositiveFloat = 1.175494351e-38f; // Smallest positive normal float, approximately 1.0 / (2^126)
    cout << "Testing with smallest positive normal float value: " << smallestPositiveFloat << endl;
    printFloatBits(smallestPositiveFloat);

    // Test case: largest positive normal float number
    float largestPositiveFloat = 3.402823466e+38f; // Largest positive normal float, approximately (1.0 - 2^-23) * 2^127
    cout << "Testing with largest positive normal float value: " << largestPositiveFloat << endl;
    printFloatBits(largestPositiveFloat);
}

int main()
{
    testPrintFloatBits();
    float number = -8.25;
    printFloatBits(number);
    return 0;
}
