#include "matrix_functions.h"
#include <iostream>
#include <thread>
#include <random>

std::vector<std::vector<int>> createMatrix(int size) {
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size));
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 5);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = distrib(gen);
        }
    }
    return matrix;
}

std::vector<std::vector<int>> simpleMultiply(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    int size = A.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

void multiplyPart(int start_i, int end_i, int start_j, int end_j,
    std::vector<std::vector<int>> A,
    std::vector<std::vector<int>> B,
    std::vector<std::vector<int>>& result) {
    
    int size = A.size();
    for (int i = start_i; i < end_i; i++) {
        for (int j = start_j; j < end_j; j++) {
            int sum = 0;
            for (int k = 0; k < size; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
}

std::vector<std::vector<int>> multiplyWithThreads(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B, int block) {
    int size = A.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));
    std::vector<std::thread> threads;
    
    for (int i = 0; i < size; i += block) {
        for (int j = 0; j < size; j += block) {
            int end_i = i + block;
            int end_j = j + block;
            if (end_i > size) end_i = size;
            if (end_j > size) end_j = size;
            
            threads.push_back(std::thread(multiplyPart, i, end_i, j, end_j, A, B, std::ref(result)));
        }
    }
    
    for (auto& thread : threads) {
        thread.join();
    }
    
    return result;
}

bool checkEqual(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B) {
    int size = A.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (A[i][j] != B[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(std::vector<std::vector<int>> matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
