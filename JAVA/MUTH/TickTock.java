import java.util.*;

class Shop
{
    int max;
    boolean isAvailable=false;

    synchronized void put()
    {
        while(isAvailable)
        {
            try
            {
                wait();
            }
            catch(Exception e){}
        }
        isAvailable=true;
        System.out.print("Tick ");
        notify();
    }

    synchronized void get()
    {
        while(!isAvailable)
        {
            try
            {
                wait();
            }
            catch(Exception e){}
        }
        System.out.println("Tock");
        isAvailable=false;
        notify();
    }

}

class Producer implements Runnable
{
    Shop q;
    Thread t;
    Producer(Shop q)
    {
        this.q=q;
        t = new Thread(this);
    }
    public void run()
    {
        int i=0;
        while(i<q.max)
        {
            q.put();
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            i++;
        }
    }
}

class Consumer implements Runnable
{
    Shop q;
    Thread t;
    Consumer(Shop q)
    {
        this.q=q;
        t = new Thread(this);
    }
    public void run()
    {
        int i=0;
        while(i<q.max)
        {
            q.get();
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            i++;
        }
    }
}

class TickTock
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Shop q = new Shop();
        System.out.println("Enter Number of Times : \t");
        q.max=sc.nextInt();
        Producer p = new Producer(q);
        Consumer c = new Consumer(q);
        p.t.start();
        c.t.start();
    }
}