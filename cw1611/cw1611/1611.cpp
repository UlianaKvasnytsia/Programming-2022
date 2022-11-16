#include <iostream>
using namespace std;
enum DogBreeds {
    SHPIC,//0
    HASKY,//1
    TAKSA,//2
    NOBREED = -1

};
struct ZooDog {
    DogBreeds breed;
    int age;
};

void add_elem(DogBreeds* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = DogBreeds(rand() % 3);
    }
}
void print_breed(DogBreeds d) {
    switch (d) {
    case 0:
        cout << "Breed -- " << "Shpic" << endl;
        break;
    case 1:
        cout << "Breed -- " << "Hasky" << endl;
        break;
    case 2:
        cout << "Breed -- " << "Taksa" << endl;
        break;
    }
}
void print_breeds(DogBreeds* array_1, int n) {
    for (int i = 0; i < n; ++i) {
        print_breed(array_1[i]);
    }
}
DogBreeds str_to_dogbreed(string a) {
    //tolower(a);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = tolower(a[i]);
    }
    if (a == "shpic") {
        return SHPIC;
    }
    else if (a == "hasky") {
        return HASKY;
    }
    else if (a == "taksa") {
        return TAKSA;
    }
    else {
        return NOBREED;
    }
}
void input(ZooDog &a) {
    string breed;
    DogBreeds res;
    do {
        cout << "enter a valid breed" << endl;
        cin >> breed;
        res = str_to_dogbreed(breed);
    } while (res == NOBREED);
    a.breed = res;
    cin >> a.age;
}
void printzoodog(ZooDog a) {
    print_breed(a.breed);
    cout << "age -- " << a.age << endl;
}
void sort(ZooDog* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].age > arr[j + 1].age) swap(arr[j], arr[j + 1]);
        }
    }
}
int main() {
    int n;
    bool res = false;
    DogBreeds result;
    string breed;
    cout << "Enter n: " << endl;
    cin >> n;
    /*DogBreeds* array_breeds = new DogBreeds[n];
    add_elem(array_breeds, n);
    print_breeds(array_breeds,n);
    while (res == false) {
        cout << "Enter a breed" << endl;
        cin >> breed;
        result = str_to_dogbreed(breed);
        for (int i = 0; i < n; ++i) {
            if (result == array_breeds[i]) {
                cout << "Breed is found" << endl;
                res = true;
                break;
            }
        }
        if (res == false) {
            cout << "Breed is not found" << endl;
        }
    }*/
    ZooDog* arr = new ZooDog[n];
    for (int i = 0; i < n; i++) {
        input(arr[i]);
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printzoodog(arr[i]);
    }
    return 0;
}