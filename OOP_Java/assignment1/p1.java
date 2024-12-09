// Write an algorithm and Java program to generate first 100 prime
// numbers using Sieve of Eratosthenes algorithm.

import java.util.Arrays;

public class p1 {
    public static void main(String[] args) {
        int n = 100;
        boolean[] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }   
        }
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                System.out.print(i + " ");
            }
        }
    }
}