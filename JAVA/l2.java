class l2 {
    static void asc(int[] arr) {
        int temp, n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    static void dsc(int[] arr) {
        int temp, n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] < arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    static void Display(int[] arr) {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    static int[] insert(int[] arr, int ele, int pos) {
        int[] ar = new int[arr.length + 1];
        for (int i = 0; i < pos; i++) {
            ar[i] = arr[i];
        }
        ar[pos] = ele;
        for (int i = pos + 1; i < ar.length; i++) {
            ar[i] = arr[i - 1];
        }
        return ar;
    }

    static int[] delete(int[] arr, int pos) {
        int[] ar = new int[arr.length - 1];
        for (int i = 0; i < pos; i++) {
            ar[i] = arr[i];
        }
        for (int i = pos; i < arr.length - 1; i++) {
            ar[i] = arr[i + 1];
        }
        return ar;
    }

    static int search(int[] arr, int ele) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == ele) {
                return i;
            }
        }
        return -1;
    }

    static void Display(int[][] c) {
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[0].length; j++) {
                System.out.print(c[i][j] + " ");
            }
            System.out.println();
        }
    }

    static void matr_add(int[][] a, int[][] b) {
        if (a.length != b.length && a[0].length != b[0].length) {
            System.out.println("Matrices can't be added");
        } else {
            int[][] c = new int[a.length][a[0].length];
            for (int i = 0; i < a.length; i++) {
                for (int j = 0; j < a[0].length; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            System.out.println("Matrix Addition");
            Display(c);
        }
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

    static void DisplayPrime(int[] arr) {
        System.out.println("Prime Numbers in Given Array are");
        for (int i = 0; i < arr.length; i++) {
            if (isPrime(arr[i])) {
                System.out.print(arr[i] + " ");
            }
        }
        System.out.println();
    }

    static void Tr_Nrm(int[][] a) {
        int tr = 0, nr = 0;
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                nr += Math.pow(a[i][j], 2);
            }
            tr += a[i][i];
        }
        Double nrm = Math.pow(nr, 0.5);
        System.out.println("Trace is " + tr + " Norm is " + nrm);
    }

    public static void main(String[] args) {
        int[] ar = { 5, 10, 6, 3, 2, 9, 7, 8, 1 };
        System.out.println("Ascending Order : ");
        asc(ar);
        Display(ar);
        System.out.println("Descending Order : ");
        dsc(ar);
        Display(ar);
        System.out.println("After Insertion");
        ar = insert(ar, 54, 6);
        Display(ar);
        System.out.println("After Deletion");
        ar = delete(ar, 9);
        Display(ar);
        int t = search(ar, 5);
        if (t == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at postion " + t);
        }
        int[][] a = { { 1, 2, 3 }, { 2, 3, 1 }, { 3, 1, 2 } };
        int[][] b = { { 4, 5, 6 }, { 5, 6, 4 }, { 6, 4, 5 } };
        System.out.println("Matrix A");
        Display(a);
        System.out.println("Matrix B");
        Display(b);
        matr_add(a, b);
        DisplayPrime(ar);
        Tr_Nrm(a);
    }
}