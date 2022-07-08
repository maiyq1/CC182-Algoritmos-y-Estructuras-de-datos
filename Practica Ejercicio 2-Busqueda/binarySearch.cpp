#include <iostream>
#include <functional>
#include <array>

using namespace std;

template <typename G>
class Array{
    int n; //Primitiva como atributo
    array<G, 5> arr; //Container como atributo
    function<bool(G,G)> equals; //Funcion como atributo

    public:
    Array(int n, function<bool(G,G)> equals): n(n), equals(equals) { simulation(); }
    //Busqueda lineal
    long long linearSearch(G value){
        long long pos = -1;
        for(size_t index=0; index<n; index++){
            if(equals(arr[index], value))
                pos = index;
        }
        return pos;
    }

    //Busqueda binaria
    long long binarySearch(G val){}
    void simulation(){
        for(size_t i=0; i<5; ++i)
            arr[i] = i+1;
    }
};

int main(){
    function<bool(int,int)> igual = [](int a, int b) {
        if(a==b) return true;
        else return false;
    };
    Array<int> arr(5,igual);
    cout << arr.linearSearch(10) << endl;
    return 0;
}