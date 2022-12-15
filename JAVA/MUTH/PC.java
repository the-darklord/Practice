class Shop
{
    int n;
    boolean isAvailable=false;

    synchronized void put(int x)
    {
        while(isAvailable)
        {
            try
            {
                wait();
            }
            catch(Exception e){}
        }
        n=x;
        isAvailable=true;
        System.out.println("Produced : "+n);
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
        System.out.println("Consumed : "+n);
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
        while(true)
        {
            q.put(i++);
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
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
        while(true)
        {
            q.get();
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class PC
{
    public static void main(String[] args) {
        Shop q = new Shop();
        Producer p = new Producer(q);
        Consumer c = new Consumer(q);
        p.t.start();
        c.t.start();
    }
}