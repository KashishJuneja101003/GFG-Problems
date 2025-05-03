class Solution {
  public:
    vector<int> primes;
    
    void generatePrimes(int maxLimit) {
        vector<bool> isPrime(maxLimit+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= maxLimit; ++i) {
            if(isPrime[i]) {
                for(int j = i*i; j <= maxLimit; j += i)
                    isPrime[j] = false;
            }
        }

        for(int i = 2; i <= maxLimit; ++i) {
            if(isPrime[i]) primes.push_back(i);
        }
    }

    int getClosestPrime(int num) {
        // Edge case: if num <= 2
        if (num <= 2) return 2;

        // Binary search
        int l = 0, r = primes.size() - 1;
        int closest = primes[0];

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (primes[mid] == num) return num;
            else if (primes[mid] < num) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        int lower = primes[r], upper = primes[l];
        if ((num - lower) <= (upper - num)) return lower;
        else return upper;
    }

    Node* primeList(Node* head) {
        generatePrimes(100005); // you can increase this limit as needed

        Node* temp = head;
        while(temp != nullptr) {
            temp->val = getClosestPrime(temp->val);
            temp = temp->next;
        }
        return head;
    }
};
