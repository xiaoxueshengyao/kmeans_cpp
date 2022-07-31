#include <iostream>
#include <vector>
#include "points.hpp"
#include "kmeans.hpp"


int main(int argc, char** argv)
{
    if(argc < 3)
    {
        std::cout<<"Usage ./kmeas fielename k"<<std::endl;
        return -1;
    }

    const std::string filepath = argv[1];
    const int num_cluster = atoi(argv[2]);

    std::vector<Points> points;

    kmeans::loadPoints(filepath, &points);
    for(const auto& p:points)
    {
        std::cout<<p<<std::endl;
    }

    kmeans kmeans(num_cluster);
    kmeans.init(points);
    kmeans.run();
    kmeans.PrintMeans();

    kmeans.writeMeans("test_mean.txt");
    
    std::cout<<"Done!"<<std::endl;
    
    return 0;
    
}