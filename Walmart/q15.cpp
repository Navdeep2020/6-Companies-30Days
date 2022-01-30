int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long a = abs(dividend), b = abs(divisor), ans = 0,x;
        while (a - b >= 0) {
            for (x = 0; a - (b << x << 1ll) >= 0; x++);
            ans += 1 << x;
            a -= b << x;
        }
        return (dividend > 0) == (divisor > 0) ? ans : -ans;
    }