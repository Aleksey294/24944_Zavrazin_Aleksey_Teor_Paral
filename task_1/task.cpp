#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#ifdef USE_DOUBLE
    using real_t = double;
#else
    using real_t = float;
#endif

int main(){
    const int N = 10000000;
    const real_t step = real_t(0.1);
    real_t sum = 0;

    vector<real_t> sin_values(N);

    for (int i = 0; i < N; i++)
    {
        real_t x = static_cast<real_t>(i) * step;
        sin_values[i] = sin(x);
        sum += sin_values[i];
    }
    
    cout << sum << endl;
    
    return 0;
}