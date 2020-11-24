
class Incognizable {
public:
    Incognizable() {}

    Incognizable(int n) {
        a = n;
    }

    Incognizable(int n, int i) {
        a = n;
        b = i;
    }
private:
    int a;
    int b;
};

int main() {
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};
    
    return 0;
}
