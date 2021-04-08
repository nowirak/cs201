

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using std::map;
#include <random>
#include <cmath>
#include <cstdlib>
using std::rand;

int RandomBetweenU(int first, int last) {
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random number
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(first, last);
	return uniform_dist(e1);
}

int RandomBetweenN(int first, int last) {
	// Seed with a real random value, if available
	std::random_device r;

	// Generate a normal distribution around that mean
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist((first + last)/2.0, std::round(abs(first-last)/6.0));

	return std::round(normal_dist(e2));
}

int RandomBetween(int first, int last) {
	
	return rand() % (abs(first-last)+1) + first;
}

void PrintDistribution(const map<int, int>& numbers) {
	for (const auto &p : numbers) {
		std::cout << std::fixed << std::setprecision(1) << std::setw(2)
			<< p.first << ' ' << std::string(p.second, '*') << '\n';
	}

	return;
}


#if 1
int main()
{
	map<int, int> numbersU;
	map<int, int> numbersN;
	map<int, int> numbers;
	const int first = 1;
	const int last = 17;
	const int iterations = 10'000;
	const int divider = 25;

	for (int n = 0; n < iterations; ++n) {
		++numbersU[RandomBetweenU(first, last)];
	}
	for (auto& p : numbersU) {
		p.second = p.second / divider;
	}

	for (int n = 0; n < iterations; ++n) {
		++numbersN[RandomBetweenN(first, last)];
	}
	for (auto& p : numbersN) {
		p.second = p.second / divider;
	}

	for (int n = 0; n < iterations; ++n) {
		++numbers[RandomBetween(first, last)];
	}
	for (auto& p : numbers) {
		p.second = p.second / divider;
	}

	std::cout << "Uniform distribution: [" << first << "," << last << "]" << "\n";
	for (const auto &p : numbersU) {
		if (p.second != 0) {
			std::cout << std::fixed << std::setprecision(1) << std::setw(2)
				<< p.first << ' ' << std::string(p.second, '*') << '\n';
		}
	}

	std::cout << '\n' << '\n';

	std::cout << "Normal distribution: mean = " << (first + last) / 2.0 << ", std = " << std::round(abs(first - last) / 6.0) << "\n";
	for (const auto& p : numbersN) {
		if (p.second != 0) {
			std::cout << std::fixed << std::setprecision(1) << std::setw(2)
				<< p.first << ' ' << std::string(p.second, '*') << '\n';
		}
	}

	std::cout << '\n' << '\n';

	std::cout << "Rand() distribution: [" << first << "," << last << "]" << "\n";
	for (const auto& p : numbers) {
		if (p.second != 0) {
			std::cout << std::fixed << std::setprecision(1) << std::setw(2)
				<< p.first << ' ' << std::string(p.second, '*') << '\n';
		}
	}

	return 0;
}
#endif



//original source code used for adaptation
#if 0

int main()
{
	// Seed with a real random value, if available
	std::random_device r;

	// Choose a random mean between 1 and 6
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	std::cout << "Randomly-chosen mean: " << mean << '\n';

	// Generate a normal distribution around that mean
	std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist(mean, 2);
	std::map<int, int> hist;
	for (int n = 0; n < 10'000; ++n) {
		++hist[std::round(normal_dist(e2))];
	}
	std::cout << "Normal distribution around " << mean << ":\n";
	for (auto p : hist) {
		std::cout << std::fixed << std::setprecision(1) << std::setw(2)
			<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	}
}

#endif
