import java.util.*;

class Counter {
    private static int count = 0;
    boolean isSet = false;

    synchronized void increment() {
        while(count == 3){
            try {
                System.out.println("Current count : " + count + "\tWaiting for Count to be less than 3");
                wait();
            } 
            catch (InterruptedException e) {}
        }
        count++;
        System.out.println("Current count : "+count);
        notify();
    }

    synchronized void decrement() {
        while(count == 0){
            try {
                System.out.println("Current count : " + count + "\tWaiting for Count to become greater than 0");
                wait();
            } 
            catch (InterruptedException e) {}
        }
        count--;
        System.out.println("Current count : "+count);
        notify();
    }
}


class inc20 implements Runnable {
    Counter c;

    inc20(Counter c) {
        this.c = c;
        Thread t = new Thread(this, "Increment");
        t.start();
    }

    public void run() {
        for (int i = 0; i < 20; i++) {
            c.increment();
            try {
                Thread.sleep(200);
            } catch (Exception e) {
            }
        }
    }
}

class dec20 implements Runnable {
    Counter c;

    dec20(Counter c) {
        this.c = c;
        Thread t = new Thread(this, "Decrement");
        t.start();
    }

    public void run() {
        for (int i = 0; i < 20; i++) {
            c.decrement();
            try {
                Thread.sleep(1000);
            } catch (Exception e) {
            }
        }
    }
}

class mihir {
    public static void main(String[] args) {
        Counter c = new Counter();
        new inc20(c);
        new dec20(c);
    }
}