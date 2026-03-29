// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value)
{
    if (arr == nullptr || len < 2)
        return 0;

    int count = 0;

    for (int i = 0; i < len - 1; ++i)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (arr[i] + arr[j] == value)
                ++count;
        }
    }

    return count;
}

int countPairs2(int *arr, int len, int value)
{
    if (arr == nullptr || len < 2)
        return 0;

    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum < value)
        {
            ++left;
        }
        else if (sum > value)
        {
            --right;
        }
        else
        {
            if (arr[left] == arr[right])
            {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }

            int leftValue = arr[left];
            int rightValue = arr[right];

            int leftCount = 0;
            int rightCount = 0;

            while (left <= right && arr[left] == leftValue)
            {
                ++left;
                ++leftCount;
            }

            while (right >= left && arr[right] == rightValue)
            {
                --right;
                ++rightCount;
            }

            count += leftCount * rightCount;
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value)
{
    if (arr == nullptr || len < 2)
        return 0;

    int count = 0;

    for (int i = 0; i < len - 1; ++i)
    {
        int target = value - arr[i];

        int left = i + 1;
        int right = len - 1;
        int first = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else if (arr[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                first = mid;
                right = mid - 1;
            }
        }

        if (first == -1)
            continue;

        left = first;
        right = len - 1;
        int last = first;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                last = mid;
                left = mid + 1;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        count += (last - first + 1);
    }

    return count;
}