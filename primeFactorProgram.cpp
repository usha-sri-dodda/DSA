vector<int> computeSPF(int N) {
    vector<int> spf(N + 1);
    for (int i = 0; i <= N; ++i) {
        spf[i] = i;
    }

    for (int i = 2; i * i <= N; ++i) {
        // i is prime
        if (spf[i] == i) { 
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
    return spf;
}

// Function to get unique prime factors using precomputed SPF
vector<int> primeFac(int n, const vector<int>& spf) {
    set<int> uniqueFactors;
    while (n > 1) {
        uniqueFactors.insert(spf[n]);
        n /= spf[n];
    }
    return vector<int>(uniqueFactors.begin(), uniqueFactors.end());
}
