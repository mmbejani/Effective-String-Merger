#include "../header/utils.hh"

string za::merge_string(const string &s_lhs, const string &s_rhs) noexcept
{
    std::wstring_convert<std::codecvt_utf8<char16_t>, char16_t> convertor;
    auto u16s1 = convertor.from_bytes(s_lhs);
    auto u16s2 = convertor.from_bytes(s_rhs);
    if (u16s2.length() < 4)
        return convertor.to_bytes(u16s1);
    Pair<Pair<int>> pair;
    if (u16s1.length() > 40){
        const int substring_index = 20;
        auto substring_u16s1 = u16s1.substr(u16s1.length() - substring_index, substring_index);
        pair = most_similar_string(substring_u16s1, u16s2);
        pair.first.first += u16s1.length() - substring_index;
        pair.first.second += u16s1.length() - substring_index;
    }else {
        pair = most_similar_string(u16s1, u16s2);
    }

    std::u16string u16result;
    if (pair.first.second == 0){
        u16result.append(u16s1);
        u16result.append(u16s2);
        return convertor.to_bytes(u16result);
    }
    
    u16result.append(u16s1.substr(0, pair.first.first));
    u16result.append(u16s1.substr(pair.first.first, pair.first.second - pair.first.first));
    u16result.append(u16s2.substr(pair.second.second, u16s2.length() - pair.second.second));

    return convertor.to_bytes(u16result);
}

za::Pair<za::Pair<int>> za::most_similar_string(const u16string &s_lhs, const u16string &s_rhs) noexcept
{
    const size_t dim = (s_lhs.length() + 1) * (s_rhs.length() + 1);
    auto dp = Array2D<int>(s_lhs.length() + 1, s_rhs.length() + 1);
    int max_value = 0, max_i = 0, max_j = 0;

    for (unsigned int i = 1; i < dp.dims(0); i++)
        for (unsigned int j = 1; j < dp.dims(1); j++)
            if (s_lhs[i - 1] == s_rhs[j - 1]) {
                dp.set(dp(i - 1, j - 1) + 1, i, j);
                auto value = dp(i,j);
                if (value > max_value){
                    max_value = value;
                    max_i = i;
                    max_j = j;
                }             
            }

    // There is no more two characters match between two strings
    if (max_value < 3){
        Pair<Pair<int>> bound{Pair<int>{0, 0}, Pair<int>{0, 0}};
        return bound;
    }
        
    Pair<Pair<int>> bound{Pair<int>{max_i - max_value,max_i}, Pair<int>{max_j-max_value,max_j}};
    return bound;

}

PYBIND11_MODULE(za_string_merger, m)
{
    m.def("merge", &za::merge_string, "This function add two numbers");
}