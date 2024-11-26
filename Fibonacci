#include <iostream>
#include <vector>
#include <stdexcept>

class FibonacciGenerator {
public:
    // Создание чисел
    static std::vector<unsigned long long> generateFibonacci(int n) {
        if (n <= 0) {
            throw std::invalid_argument("n must be a natural number (greater than 0)");
        }
        
        std::vector<unsigned long long> fib(n);
        fib[0] = 0; //Первое значение
        if (n > 1) {
            fib[1] = 1; // Второе значение
            for (int i = 2; i < n; ++i) {
                fib[i] = fib[i - 1] + fib[i - 2]; // Заполнение вектора числами
            }
        }
        
        return fib;
    }
};

int main() {
    try {
        int n;
        std::cout << "Enter a NATURAL (>0) number n: ";
        std::cin >> n;

        std::vector<unsigned long long> fibNumbers = FibonacciGenerator::generateFibonacci(n);
        std::cout << "The first " << n << " Fibonacci numbers: "<<std::endl;
        for (size_t i = 0; i < fibNumbers.size(); ++i) {
            std::cout << fibNumbers[i] << " ";
        }
        std::cout << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Unknown error!" << std::endl;
    }

    return 0;
}
