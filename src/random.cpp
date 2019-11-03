#include "random.h"

using namespace std;

RandomNumbers::RandomNumbers(unsigned long int s)
{
	if (s == 0) {
        random_device rd;
        seed = rd();
    } else {
		seed = s;
		rng = mt19937(s);
	}
}

void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper)
{
	for(size_t n; n < tab.size(); ++n) {	
		tab[n] = uniform_double(lower, upper);
	}
}


double RandomNumbers::uniform_double(double lower, double upper)
{
    uniform_real_distribution<> unif(lower, upper);
    return unif(rng);
}


void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd)
{
	for(size_t n; n < tab.size(); ++n) {	
		tab[n] = normal(mean, sd);
	}
}


double RandomNumbers::normal(double mean, double sd)
{
	normal_distribution<> norm(mean, sd);
	return norm(rng);
}


void RandomNumbers::poisson(std::vector<int>& tab, double mean)
{
	for(size_t n; n < tab.size(); ++n) {	
		tab[n] = poisson(mean);
	}	
}


int RandomNumbers::poisson(double mean)
{
	poisson_distribution<> pois_distrib(mean);
	return pois_distrib(rng);
}
