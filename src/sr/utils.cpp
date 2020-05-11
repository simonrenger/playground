#include <vector>
#include <iostream>
#include <cmath>
#include <chrono>
#include <algorithm>

using namespace std;

/*
class Timer
{
public:
    void start()
    {
        startTime = std::chrono::system_clock::now();
        running = true;
    }

    void stop()
    {
        EndTime = std::chrono::system_clock::now();
        running = false;
    }

    double elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if (running)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    }

    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> EndTime;
    bool                                               running = false;
};
*/
int Sum(int a, int b) {
    if (a < 0) {
        return std::abs(a) + b;
    }
    else {
        return b - a;
    }
}

vector<int> sortedfillArray(int min, int max) {
    vector<int> vec{};
    vec.resize(Sum(min, max));
    auto upCounter{ 0 };
    for (auto& elm : vec) {
        elm = upCounter;
        ++upCounter;
    }
    return vec;
}


int findMaxConsecutiveOnes(vector<int>& nums) {
    auto result{ 0 };
    auto counter{ 0 };
    for (auto index{ 0 }; index < nums.size(); ++index) {
        counter += nums[index];
        if (nums[index] == 1) {
            if (counter > result)
            {
                result = counter;
            }
        }
        else {
            counter = 0;
        }
    }
    return counter;
}

int numberOfDigits(int n) {

    if (n <= 9) {
        return 1;
    }
    return 1 + numberOfDigits(n / 10);
}

int findNumbers(vector<int>& nums) {
    auto result{ 0 };
    for (auto num : nums)
        if ((numberOfDigits(num) % 2) == 0) ++result;
    return result;
}

// could be replaced with std::sort
void asort(vector<int>& input) {
    auto n{ input.size() };
    for (auto i{ 0 }; i < n; ++i) {
        for (auto j{ 0 }; j < n - 1 - i; ++j) {
            if (input[j] > input[j + 1]) {
                std::swap(input[j + 1], input[j]);
            }
        }
    }
}
void dsort(vector<int>& input) {
    auto n{ input.size() };
    for (auto i{ 0 }; i < n; ++i) {
        for (auto j{ 0 }; j < n - 1 - i; ++j) {
            if (input[j] > input[j + 1]) {
                std::swap(input[j], input[j + 1]);
            }
        }
    }
}

int partition(vector<int>& a, int start, int end)
{
    int pivot = a[end];

    int pidx = start;
    for (auto i{ start }; i < end; ++i)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pidx]);
            ++pidx;
        }
    }

    swap(a[end], a[pidx]);
    return pidx;
}

// could be replaced by std::sort is faster
void qsort(vector<int>& a, int start, int end)
{
    auto pidx{ start };
    if (start < end)
    {
        {
            int pivot = a[end];
            for (auto i{ start }; i < end; ++i)
            {
                if (a[i] <= pivot)
                {
                    swap(a[i], a[pidx]);
                    ++pidx;
                }
            }
            swap(a[end], a[pidx]);
        }
        qsort(a, start, pidx - 1);
        qsort(a, pidx + 1, end);
    }
}


void duplicateZeros(vector<int>& arr) {
    auto arrayLength{ arr.size() };
    for (auto idx{ 0 }; idx < arrayLength - 1; ++idx) {
        ++idx;
        if (arr[idx - 1] == 0) {
            auto nextIdx{ idx };
            auto insertIdx{ idx + 1 };
            if (insertIdx < arrayLength - 1) {
                memmove(&arr[insertIdx], &arr[0] + nextIdx, sizeof(int) * (arrayLength - insertIdx));
            }
            else {
                arr[arrayLength - 1] = arr[nextIdx];
            }
            arr[nextIdx] = 0;
            ++idx;
        }
        --idx;

    }
}

void unqiue(vector<int>& input) {
    auto size{ input.size() };
    auto changeCounter{ 0 };
    for (auto idx{ 0 }; idx < size - 2 - changeCounter; ++idx) {
        auto& elm{ input[idx] };
        auto& compElem{ input[idx + 1] };
        if (elm == compElem) {
            swap(input[size - 1 - changeCounter], elm);
            ++changeCounter;
        }
    }

    for (auto idx{ size - 1 }; idx > size - 1 - changeCounter; --idx) {
        input.pop_back();
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n > 0) {
        memcpy(nums1.data() + m, nums2.data(), n * sizeof(int));
        asort(nums1);
        unqiue(nums1);
        asort(nums1);
    }
}

void move(vector<int>& nums, size_t begin) {
    for (auto idx{ begin }; idx < nums.size() - 1; ++idx) {
        swap(nums[idx + 1], nums[idx]);
    }
}

int removeDuplicates(vector<int>& nums) {
    int left = 0;

    for (int index = 0; index < (int)nums.size(); ++index) {

        if (index < (int)nums.size() - 1) {
            if (nums[index] == nums[index + 1]) continue;
            else {
                nums[left] = nums[index];
                ++left;
            }
        }
        else {
            nums[left] = nums[index];
            ++left;
        }

    }

    return left;

    /**
    for (auto idx{ 0 }; idx < nums.size() && nums.size() > idx + 1; ++idx) {
        if (nums[idx] == nums[idx+1]) {
            swap(nums[nums.size() - 1], nums[idx]);
            nums.pop_back();
            move(nums,idx);
            idx = -1;
        }
    }
    return nums.size();
    **/
}

int removeElement(vector<int>& nums, int val) {
    for (auto idx{ 0 }; idx < nums.size(); ++idx) {
        if (nums[idx] == val) {
            swap(nums[nums.size() - 1], nums[idx]);
            nums.pop_back();
            idx = -1;
        }
    }
    return nums.size();
}

vector<int> sortedSquares(vector<int>& A) {
    for (auto& num : A)
        num = std::abs(num) * std::abs(num);
    qsort(A, 0, A.size() - 1);
    return A;
}


template<typename T>
struct Node {
    T data{};
    Node<T>* next{ nullptr };
};

template<typename T>
using Node_ptr = Node<T>*;

template<typename T>
struct List {
    Node_ptr<T> head{ nullptr };
    Node_ptr<T> tail{ nullptr };
    size_t size{ 0 };
    Node_ptr<T> insert(T&& data) {
        Node_ptr<T> node{
            new Node<T>{
                std::move(data),
                head
            }
        };
        if (head == nullptr) {
            tail = node;
        }
        head = node;
        return node;
    }
    Node_ptr<T> insert(T&& data, Node_ptr<T> node) {
        Node_ptr<T> newNode{
           new Node<T>{
               std::move(data),
               head
           }
        };
        newNode->next = node->next;
        node->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
        return newNode;
    }
};

using ivec = vector<int>;
int main2()
{

    List<int> list{};
    list.insert(8);
    auto p = list.insert(9);
    list.insert(10);
    list.insert(11, p);
    return 9;
    /*
    auto data{ ivec{ 1,0,1,1,0,1} };
    findMaxConsecutiveOnes(data);
    findNumbers(ivec{ 12, 345, 2, 6, 7896 });
    data = sortedfillArray(-10000, 100);
    //auto vec{ sortedSquares(data)};
    data = ivec{ 1,0,2,3,0,4,5,0 };//1,5,2,0,6,8,0,6,0 };//0,1,9,2,6,0,0,4,1,0 };//
    duplicateZeros(data);
    auto nums1 {ivec{ 1,2,3,0,0,0 }};//1,2,3,0,0,0 };
    auto nums2 { ivec{ 2,5,6 } };
    merge(nums1, 3, nums2, nums2.size());
    auto nums{ ivec{3,2,2,3,2,3} };
    auto val{ removeElement(nums, 3) };
    auto ival{ ivec{-50,-50,-49,-49,-48,-48,-45,-44,-43,-43,-43,-43,-42,-42,-42,-41,-41,-40,-40,-39,-39,-37,-37,-37,-36,-36,-34,-34,-32,-31,-31,-30,-30,-30,-29,-28,-28,-25,-24,-23,-23,-22,-21,-20,-20,-20,-19,-18,-17,-17,-16,-16,-15,-15,-14,-12,-12,-12,-11,-11,-11,-10,-10,-10,-10,-10,-9,-9,-8,-8,-7,-7,-6,-6,-6,-6,-6,-6,-5,-4,-4,-4,-3,-3,-2,-1,-1,0,2,3,3,3,3,3,3,6,7,8,9,11,11,11,11,11,12,12,12,13,13,13,15,15,16,16,16,17,17,18,19,19,19,20,20,21,21,21,22,22,23,23,24,25,25,27,28,29,29,30,30,30,30,30,31,31,31,32,33,34,34,34,35,35,36,36,36,38,38,39,39,39,40,40,40,41,41,42,43,43,43,43,43,44,45,46,46,46,47,48,49,49,50,50,50} };
    auto val2{ removeDuplicates(ival) };
    */
}

