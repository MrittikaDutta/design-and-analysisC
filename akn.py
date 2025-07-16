def min_capacity_to_transfer_packages(T, test_cases):
    # Function to check if all packages can be transferred within D days
    def can_transfer_packages(weights, D, capacity):
        days_needed = 1
        current_capacity = 0
        for weight in weights:
            if current_capacity + weight > capacity:
                days_needed += 1
                current_capacity = 0
            current_capacity += weight
        return days_needed <= D

    # Binary search to find the minimum capacity
    def binary_search_min_capacity(weights, D):
        left = max(weights)
        right = sum(weights)
        while left < right:
            mid = left + (right - left) // 2
            if can_transfer_packages(weights, D, mid):
                right = mid
            else:
                left = mid + 1
        return left

    results = []
    for i in range(T):
        n, d = test_cases[i][0]
        weights = test_cases[i][1]
        min_capacity = binary_search_min_capacity(weights, d)
        results.append(min_capacity)

    return results

# Reading input
T = int(input())
test_cases = []
for _ in range(T):
    n, d = map(int, input().split())
    weights = list(map(int, input().split()))
    test_cases.append((n, d), weights)

result = min_capacity_to_transfer_packages(T, test_cases)


for res in result:
    print(res)
