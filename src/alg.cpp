// Copyright 2021 NNTU-CS
#include "alg.h"
int countPairs1(int* arr, int len, int value) {
    if (arr == 0 || len < 2)
        return 0;
    int count = 0;
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value)
                ++count;
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    if (arr == 0 || len < 2)
        return 0;
    int count = 0;

    for (int left = 0; left < len - 1; ++left) {
        if (arr[left]*2 > value) {
            break;
        }
        int right = len - 1;

        while (right > left && arr[left] + arr[right] > value)
            --right;

        while (right > left && arr[left] + arr[right] == value) {
            ++count;
            --right;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    if (arr == 0 || len < 2)
        return 0;
    int count = 0;
    int i = 0;

    while (i < len - 1) {
        int current = arr[i];
        int leftCount = 1;
        while (i + leftCount < len && arr[i + leftCount] == current) 
            ++leftCount;
        int target = value - current;
        if (target == current) {
            count += leftCount * (leftCount - 1) / 2;
            i += leftCount;
            continue;
        }
        int left = i + leftCount;
        int right = len - 1;
        int first = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else if (arr[mid] > target) {
                right = mid - 1;
            } else {
                first = mid;
                right = mid - 1;
            }
        }

        if (first != -1) {
            left = first;
            right = len - 1;
            int last = first;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] < target){
                    left = mid + 1;
                } else if (arr[mid] > target) {
                    right = mid - 1;
                } else{
                    last = mid;
                    left = mid + 1;
                }
            }
            int rightCount = last - first + 1;
            count += leftCount * rightCount;
        }
        i += leftCount;
    }
    return count;
}
