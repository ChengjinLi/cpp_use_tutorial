// Author: MJ
// Date:: 2017/10/25
// Description: 利用 remove_if() 和 erase() 从Vector中移除指定Set中包含的元素

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

std::unordered_set<std::string> replace_str_set{",", "."};
bool IsReplaceStr(std::string str) {
    if (replace_str_set.find(str) != replace_str_set.end()) {
        return true;
    }
    return false;
}

int main() {
    std::vector<std::string> string_vector{"a", ",", "b", ".", "c"};
    std::vector<std::string>::iterator it;
    std::cout << "before replace: " << std::endl;
    for (it = string_vector.begin(); it != string_vector.end(); it++) {
        std::cout << *it << std::endl;
    }
    string_vector.erase(remove_if(string_vector.begin(), string_vector.end(), IsReplaceStr), string_vector.end());
    std::cout << "after replace: " << std::endl;
    for (it = string_vector.begin(); it != string_vector.end(); it++) {
        std::cout << *it << std::endl;
    }
    return 0;
}

/* 
输出结果：
before replace:
a
,
b
.
c
after replace:
a
b
c
*/