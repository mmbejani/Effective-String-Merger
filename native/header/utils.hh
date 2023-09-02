#include <string>
#include <locale>
#include <ranges>
#include <codecvt>
#include <pybind11/pybind11.h>

using namespace std;


namespace za {
    template <typename T>
    struct Pair {
        T first;
        T second;
    };

    string merge_string(const string&, const string&) noexcept;
    Pair<Pair<int>> most_similar_string(const u16string&, const u16string&) noexcept;
}