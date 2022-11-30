class Mult extends Thread {
    String threadname;
    int n;

    Mult(String threadname, int n) {
        super(threadname);
        this.threadname = threadname;
        this.n = n;
        System.out.println(threadname + " : ");
        start();
    }

    public void run() {
        try {
            for (int i = 1; i <= 10; i++) {
                System.out.println(n + "*" + i + "=" + (n * i));
                Thread.sleep(100);
            }
        } catch (InterruptedException e) {
            System.out.println(threadname + " Interrupted");
        }
        System.out.println("Exiting Child Thread");
    }
}

class Tables {
    String name;
    int n;

    Tables(String name, int n) {
        this.name = name;
        this.n = n;
        new Mult(name, n);
    }
}

class l9q1 {
    public static void main(String[] args) {
        new Tables("five", 5);
        new Tables("seven", 7);
        try {
            Thread.sleep(1100);
        } catch (InterruptedException e) {
            System.out.println("Interrupting Main Thread");
        }
        System.out.println("Exiting Main Thread");
    }
}