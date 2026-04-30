/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.*/


int canEat(int piles[], int n, int h, int k) {
    long long hours = 0;

    for (int i = 0; i < n; i++) {
        hours += (piles[i] + k - 1) / k;  // ceil division
        if (hours > h)
            return 0;
    }

    return 1;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = piles[0];

    // find max pile
    for (int i = 1; i < pilesSize; i++) {
        if (piles[i] > high)
            high = piles[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canEat(piles, pilesSize, h, mid)) {
            ans = mid;        // valid speed
            high = mid - 1;   // try slower speed
        } else {
            low = mid + 1;    // need faster speed
        }
    }

    return ans;
}
