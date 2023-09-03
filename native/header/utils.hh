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

    template <typename T>
    struct Array2D {
        int m, n;
        T* data;

        Array2D(int m, int n) : m(m), n(n){
            data = (T*)malloc(sizeof(T) * m * n);
            for (unsigned int i = 0; i < m * n; i++)
                data[i] = 0;
        }
        
        inline T operator()(unsigned int i,unsigned int j){
            return data[i*n + j];
        }

        inline void set(T val, int i, int j){
            data[i*n + j] = val;
        }

        inline int dims(int dim){
            if (dim == 0)
                return m;
            else
                return n;
        }
    };

    string merge_string(const string&, const string&) noexcept;
    Pair<Pair<int>> most_similar_string(const u16string&, const u16string&) noexcept;
}