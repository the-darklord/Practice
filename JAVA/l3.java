import java.util.*;

class ISBN {
    int[] isbnnum;
    Scanner sc = new Scanner(System.in);

    void inputISBN() {
        System.err.println("Enter ISBN Number Size : ");
        int n = sc.nextInt();
        isbnnum = new int[n];
        System.out.println("Enter ISBN Number : \n");
        for (int i = 0; i < n; i++) {
            isbnnum[i] = sc.nextInt();
        }
    }

    void checkISBN() {
        if (isbnnum.length != 10) {
            System.out.println("ISBN Should be a 10 Digit Number");
        } else {
            int sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += isbnnum[i] * (i + 1);
            }
            if (sum % 11 == 0) {
                System.err.println("Legal ISBN");
            } else {
                System.err.println("Illegal ISBN");
            }
        }
    }
}

class Die {
    int sup;

    int getsup() {
        return sup;
    }

    void roll() {
        Random r = new Random();
        sup = r.nextInt(6) + 1;
    }
}

class l3 {
    public static void main(String[] args) {
        // ISBN i1 = new ISBN();
        // i1.inputISBN();
        // i1.checkISBN();
        Die d1 = new Die(), d2 = new Die();
        d1.roll();
        d2.roll();
        System.out.println(d1.getsup() + "\n" + d2.getsup() + "\n" + (d1.getsup() + d2.getsup()));
    }
}