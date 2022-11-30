class l10aq {
    public static void main(String[] args) {
        Integer[] ar1 = { 5, 3, 2, 1, 6, 9, 7, 8 };
        String[] ar2 = { "Hi", "Hello", "This", "Is", "Mihir" };
        Display(ar1);
        Display(ar2);
        System.out.println(Largest(ar1[0], ar1[1], ar1[2]));
        System.out.println(Largest(ar2[0], ar2[1], ar2[2]));
    }

    static <T> void Display(T[] arr) {
        for (T i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    static <T extends Comparable<T>> T Largest(T a, T b, T c) {
        T L = a;
        if (b.compareTo(L) > 0)
            L = b;
        else if (c.compareTo(L) > 0)
            L = c;
        return L;
    }
}