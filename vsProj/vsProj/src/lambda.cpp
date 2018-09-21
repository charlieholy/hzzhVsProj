#include <iostream>
#include <string>
#include <future> 
using namespace std;

int main() {
	auto lambda = [](std::string&& message) {
		std::cout << message << std::endl;
	};
	auto future = std::async(lambda, std::string{ "hello world" });
	future.get();
	return 0;
}

