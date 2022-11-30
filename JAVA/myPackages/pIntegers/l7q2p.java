package myPackages.pIntegers;

public class l7q2p {
    public static void IntSort(int[] arr) {
        int temp;
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    public static void BinSearch(int[] arr, int first, int last, int ele) {
        int mid = (first + last) / 2;
        if (arr[mid] == ele) {
            System.out.println("Element Found at Index " + mid);
            return;
        } else if (ele < arr[mid]) {
            last = mid - 1;
            BinSearch(arr, first, last, ele);
        } else {
            first = mid + 1;
            BinSearch(arr, first, last, ele);
        }
        if (first > last) {
            System.out.println("Element Not Found");
        }
    }
}