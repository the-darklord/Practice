class l1 {
    static int largest(int a, int b, int c) {
        int large;
        if (a > b && a > c) {
            large = a;
        } else if (b > a && b > c) {
            large = b;
        } else {
            large = c;
        }
        return large;
    }

    static void quadroot(Double a, Double b, Double c) {
        Double d = b * b - 4 * a * c;
        Double re = (-b) / (2 * a);
        int f;
        if (d > 0) {
            f = 1;
        } else if (d < 0) {
            f = -1;
        } else {

            f = 0;
        }
        switch (f) {
            case 0: {
                System.out.println("Roots are " + re + "\t" + re);
                break;
            }
            case 1: {
                Double r = Math.pow(d, 0.5) / (2 * a);
                Double r1, r2;
                r1 = -re + r;
                r2 = -re - r;
                System.out.println("Roots are " + r1 + "\t" + r2);
                break;
            }
            case -1: {
                Double im = Math.pow(-d, 0.5);
                System.out.println("Roots are " + re + "+" + im + "i" + "\t" + re + "" + (-im) + "i");
                break;
            }
        }
    }

    static int fact(int x) {
        int fact = 1;
        for (int i = 1; i <= x; i++) {
            fact *= i;
        }
        return fact;
    }

    static boolean isPrime(int n) {
        boolean flag = true;
        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    static boolean isArmstrong(int n) {
        int v = n, p = n, x, sum = 0, cc = 0;
        while (p > 0) {
            x = p % 10;
            cc++;
            p /= 10;
        }
        while (v > 0) {
            x = v % 10;
            sum += Math.pow(x, cc);
            v /= 10;
        }
        if (n == sum) {
            return true;
        }
        return false;
    }

    static int findSum(int n) {
        int sum = 0;
        while (n > 0) {
            int x = n % 10;
            sum += x;
            n /= 10;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("Largest of 5 , 9 , 2 is " + largest(5, 9, 2));
        System.out.println("Factorial of 10 is " + fact(10));
        int d = (fact(10)) / (fact(5) * fact(10 - 5));
        System.out.println("Value of 10C5 is " + d);
        System.out.println("5 is Prime : " + isPrime(5));
        System.out.println("10 is Prime : " + isPrime(10));
        int count = 0, n = 6, i = 2;
        System.out.println("First 6 Prime Numbers are : ");
        while (count != n) {
            if (isPrime(i)) {
                count++;
                System.out.print(i + " ");
            }
            i++;
        }
        System.out.println();
        System.out.println("371 is Armstrong : " + isArmstrong(371));
        System.out.println("143 is Armstrong : " + isArmstrong(143));
        System.out.println("Sum of Digits of 54646 : " + findSum(54646));
        quadroot(1.0, 1.0, 1.0);
    }
}