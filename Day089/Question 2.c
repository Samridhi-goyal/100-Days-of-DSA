/*A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

int canShip(int weights[], int n, int days, int cap) {
    int requiredDays = 1;
    int currentLoad = 0;

    for (int i = 0; i < n; i++) {
        if (weights[i] > cap)
            return 0;

        if (currentLoad + weights[i] > cap) {
            requiredDays++;
            currentLoad = weights[i];

            if (requiredDays > days)
                return 0;
        } else {
            currentLoad += weights[i];
        }
    }

    return 1;
}

int shipWithinDays(int* weights, int weightsSize, int days) {
    int low = weights[0], high = 0;

    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > low)
            low = weights[i];
        high += weights[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canShip(weights, weightsSize, days, mid)) {
            ans = mid;        // possible answer
            high = mid - 1;   // try smaller capacity
        } else {
            low = mid + 1;    // increase capacity
        }
    }

    return ans;
}


 
