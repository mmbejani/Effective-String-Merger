#include "../header/utils.hh"

string za::merge_string(const string &s_lhs, const string &s_rhs) noexcept
{
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convertor;
    auto u16_lhs = convertor.from_bytes(s_lhs);
    auto u16_rhs = convertor.from_bytes(s_rhs);

    auto pair = most_similar_string(u16_lhs, u16_rhs);

    u16_lhs = u16_lhs.substr(pair.first.first, pair.first.second - pair.first.first);
    u16_rhs = u16_rhs.substr(pair.second.first, pair.second.second - pair.second.first);
    auto u16_merged_string = u16_lhs + u16_rhs;

    auto merged_string = convertor.to_bytes(u16_merged_string);
    return merged_string;
}

za::Pair<za::Pair<int>> za::most_similar_string(const u16string &s_lhs, const u16string &s_rhs) noexcept
{
    za::Pair<za::Pair<int>> p;
    uint16_t score = 0, max_score = 0;
    bool contagius = false;
    for (size_t i = 0; i < min<size_t>(s_rhs.size(), s_lhs.size()); i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            if (s_rhs[])
        }
        
    }
    return p;
}

PYBIND11_MODULE(za_string_merger, m)
{
    m.def("merge", &za::merge_string, "This function add two numbers");
}