import myPackages.pIntegers.*;

class l7q2m {
    public static void main(String[] args) {
        int[] ar = { 5, 6, 1, 2, 3, 4, 9, 7, 8 };
        for (int i : ar) {
            System.out.print(i + " ");
        }
        System.out.println();
        l7q2p.IntSort(ar);
        for (int i : ar) {
            System.out.print(i + " ");
        }
        System.out.println();
        l7q2p.BinSearch(ar, 0, ar.length - 1, 6);
    }
}
