#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <cassert>
#include <cstddef>

using namespace std;
class B

{

public:

    virtual ~B();

    int getA() const { return a; }



private:

    int a;
};

class String

{

public:

    String() :m_str{ new char[1]{0} } {
       //*m_str = 0; moved to universial initlization
    }

    ~String() {
        delete(m_str);
    }

    String(const char* str) :m_str{ new char[1]{0} } {
        memcpy(m_str, str, sizeof(char));
    }

    String(const String& other) {
        memcpy(m_str, other.m_str, sizeof(char));
    }

    String& operator= (const String& other) {
        memcpy(m_str, other.m_str, sizeof(char));
        return *this;
    }

private:

    char* m_str{nullptr};

};


class Node

{

public:
    
    int data{ 0 };

    Node* prev{ nullptr };

    Node* next{ nullptr }; // Is NULL if this is the last element



};



class LinkedList

{

public:

    // Implement this! If insertAfter is null then the element is

    // inserted at the beginning of the list. You can assume

    // that insertAfter is an existing element of the list and

    // nodeToInsert is not already a member of the list.

    void Insert(Node* insertAfter, Node* nodeToInsert) {
        assert(nodeToInsert != nullptr && "nodeToInsert cannot be a nullptr!");
        if (insertAfter != nullptr) { // more common case train the bp to be true
            nodeToInsert->next = insertAfter->next;
            nodeToInsert->prev = insertAfter;
            insertAfter->next = nodeToInsert;
            tail = nodeToInsert;
        }
        else if(head != nullptr){
            nodeToInsert->next = head;
            nodeToInsert->prev = head->prev;
            head->prev = nodeToInsert;
            head = nodeToInsert;
        }
        else {
            head = nodeToInsert;
            tail = head;
        }
    }



    // ...

private:

    Node* head{ nullptr }; // Points to first element

    Node* tail{ nullptr }; // Points to last element

};


class BitArray
{

public:

    BitArray(std::size_t size) : blob{ new uint8_t[size] {} }, size{size} {
    }

    ~BitArray() {
        delete blob;
    }

    bool GetBit(std::size_t index) const noexcept{
        assert(index < size && "Out of bounce");
        return (blob[index / std::numeric_limits<uint8_t>::digits] >> (index % std::numeric_limits<uint8_t>::digits)) & 1;
    }

    void SetBit(std::size_t index, bool value) noexcept {
            assert(index < size && "Out of bounce");
            if (value) {
                blob[index / std::numeric_limits<uint8_t>::digits] |= 1 << (index % std::numeric_limits<uint8_t>::digits);
            }
            else {
                blob[index / std::numeric_limits<uint8_t>::digits] &= ~(1 << (index % std::numeric_limits<uint8_t>::digits));
            }
    }

private:
    uint8_t* blob{ nullptr };
    std::size_t size{ 0 };
};


int ConvertStringToInt(const char* str) {
    auto count{ 0 };

    while (str[count] != '\0')
    {
        ++count;
    }
    auto getDigit = [](char s) {
        auto num{ 0 };
        switch (s)
        {
        case '0':
            num = 0;
            break;

        case '1':
            num = 1;
            break;

        case '2':
            num = 2;
            break;

        case '3':
            num = 3;
            break;

        case '4':
            num = 4;
            break;

        case '5':
            num = 5;
            break;

        case '6':
            num = 6;
            break;

        case '7':
            num = 7;
            break;

        case '8':
            num = 8;
            break;

        case '9':
            num = 9;
            break;

        default:
            num = 0;
            break;
        }
        return num;
    };
    int result{ 0 };
        switch (count)
        {
        case 0:
            result += getDigit(str[0]) * 0;
            break;
        case 1:
            result += getDigit(str[0]) * 1;
            break;

        case 2:

            result += getDigit(str[0]) * 10;
            result += getDigit(str[1]) * 1;
            break;

        case 3:
            result += getDigit(str[0]) * 100;
            result += getDigit(str[1]) * 10;
            result += getDigit(str[2]) * 1;
            break;

        case 4:
            result += getDigit(str[0]) * 1000;
            result += getDigit(str[1]) * 100;
            result += getDigit(str[2]) * 10;
            result += getDigit(str[3]) * 1;
            break;

        case 5:
            result += getDigit(str[0]) * 10000;
            result += getDigit(str[1]) * 1000;
            result += getDigit(str[2]) * 100;
            result += getDigit(str[3]) * 10;
            result += getDigit(str[4]) * 1;
            break;

        case 6:
            result += getDigit(str[0]) * 100000;
            result += getDigit(str[1]) * 10000;
            result += getDigit(str[2]) * 1000;
            result += getDigit(str[3]) * 100;
            result += getDigit(str[4]) * 10;
            result += getDigit(str[5]) * 1;
            break;

        case 7:
            result += getDigit(str[0]) * 1000000;
            result += getDigit(str[1]) * 100000;
            result += getDigit(str[2]) * 10000;
            result += getDigit(str[3]) * 1000;
            result += getDigit(str[4]) * 100;
            result += getDigit(str[5]) * 10;
            result += getDigit(str[6]) * 1;
            break;

        case 8:
            result += getDigit(str[0]) * 10000000;
            result += getDigit(str[1]) * 1000000;
            result += getDigit(str[2]) * 100000;
            result += getDigit(str[3]) * 10000;
            result += getDigit(str[4]) * 1000;
            result += getDigit(str[5]) * 100;
            result += getDigit(str[6]) * 10;
            result += getDigit(str[7]) * 1;
            break;

        default:
            result = 0;
            break;
        }

        return result;

}



using ivec = vector<int>;
int main()
{


    auto v{ ConvertStringToInt("-456") };


    int* p = new int{ 0x0A000000 };
    
    auto pp = p + 10;

    Node* n = nullptr;
    assert(n != nullptr);

    Node n1{1};
    Node n2{2};
    Node n3{3};
    Node n4{4};
    Node n5{0};
    
    LinkedList list{};
    list.Insert(nullptr, &n1);
    list.Insert(&n1, &n2);
    list.Insert(&n2, &n3);
    list.Insert(nullptr, &n5);


    BitArray bitArray{ 10 };
    bitArray.SetBit(10, true);
    auto t{ bitArray.GetBit(0) };

}

