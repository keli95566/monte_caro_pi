
#include <iostream>
#include <omp.h>
#include <random>

using namespace std;
  
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    uniform_real_distribution<double> zero_to_one{0.0, 1.0};

    double rand_x, rand_y, origin_dist;
    int circle_points = 0;
    int square_points = 0;
    int num_sample_per_thread= 10000000;

#pragma opm parallel

    {
        double local_cirlce = 0.0;
        double local_square = 0.0;
        for (int i = 0; i < (num_sample_per_thread); i++) {

            rand_x = zero_to_one(gen);
            rand_y = zero_to_one(gen);

            origin_dist = rand_x * rand_x + rand_y * rand_y;

            if (origin_dist <= 1)
                local_cirlce++;

            local_square++;
        }
#pragma omp atomic

        circle_points += local_cirlce;
        square_points += local_square;
    }


    auto pi = 4 * (double(circle_points) / square_points);
    cout << "\nFinal Estimation of Pi = " << pi;
  
    return 0; 
} 