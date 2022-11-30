import java.util.*;

class IntArr {
    int[] arr;

    IntArr() {
        arr = new int[100];
    }

    IntArr(int[] arr) {
        this.arr = arr;
    }

    void Display() {
        for (int i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    void search(int el) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == el) {
                System.out.println("Element found at index " + i);
                return;
            }
        }
        System.out.println("Element not found");
        ;
    }

    static void Compare(IntArr a1, IntArr a2) {
        if (a1.arr.length == a2.arr.length) {
            for (int i = 0; i < a1.arr.length; i++) {
                if (a1.arr[i] != a2.arr[i]) {
                    System.out.println("Not Equal");
                    return;
                }
            }
            System.out.println("Equal");
        } else {
            System.out.println("Not Equal");
        }
    }
}

class Customer {
    private int id;
    private String name;
    private Double crlimit;

    Customer(int id, String name, Double crlimit) {
        this.id = id;
        this.name = name;
        this.crlimit = crlimit;
    }

    void Display() {
        System.out.println("ID : " + id + "\t Name : " + name + "\t Credit Limit : " + crlimit);
    }
}

class l4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        IntArr a1 = new IntArr();
        int[] ar1 = { 5, 6, 1, 2, 4, 8, 3, 7, 9 };
        a1.arr = ar1;
        int[] ar2 = { 5, 2, 6, 4, 1, 3, 9 };
        IntArr a2 = new IntArr(ar2);
        a1.Display();
        a2.Display();
        a1.search(6);
        a2.search(10);
        IntArr.Compare(a1, a2);
        int n = 2;
        Customer[] c = new Customer[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter ID , Name , Credit Limit of Customer " + (i + 1));
            int id = sc.nextInt();
            String name = sc.next();
            Double cr = sc.nextDouble();
            c[i] = new Customer(id, name, cr);
        }
        for (Customer i : c) {
            i.Display();
        }
    }
}