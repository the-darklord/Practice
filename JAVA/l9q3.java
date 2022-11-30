class Shop {
    int num;
    boolean isSet = false;

    synchronized void put(int num) {
        while (isSet) {
            try {
                wait();
            } catch (Exception e) {
            }
        }
        System.out.println("Produced : " + num);
        this.num = num;
        isSet = true;
        notify();
    }

    synchronized void get() {
        while (!isSet) {
            try {
                wait();
            } catch (Exception e) {
            }
        }
        System.out.println("Consumed : " + num);
        isSet = false;
        notify();
    }
}

class Producer implements Runnable {
    Shop s;

    Producer(Shop s) {
        this.s = s;
        Thread t = new Thread(this, "Producer");
        t.start();
    }

    public void run() {
        int i = 0;
        while (true) {
            s.put(i++);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
        }
    }

}

class Consumer implements Runnable {
    Shop s;

    Consumer(Shop s) {
        this.s = s;
        Thread t = new Thread(this, "Consumer");
        t.start();
    }

    public void run() {
        while (true) {
            s.get();
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
            }
        }
    }

}

class l9q3 {
    public static void main(String[] args) {
        Shop s = new Shop();
        new Producer(s);
        new Consumer(s);
    }
}