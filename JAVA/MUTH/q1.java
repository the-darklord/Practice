
// class NewThread implements Runnable
// {
//     Thread t;
//     String name;
//     int[] a,b;
//     NewThread(String name,int[] a,int[] b)
//     {
//         this.name=name;
//         this.a=a;
//         this.b=b;
//         t = new Thread(this,this.name);
//         System.out.println(this.name);
//         t.start();
//     }
//     public void run()
//     {
//         int c = 0;
//         for(int i=0;i<a.length;i++)
//         {
//             c=c+a[i]*b[i];
//         }
//         System.out.print(c+"\t");
//     }
// }

class NewThread extends Thread
{
    String name;
    int[] a,b;
    NewThread(String name,int[] a,int[] b)
    {
        this.name=name;
        this.a=a;
        this.b=b;
        new Thread(this,this.name);
        System.out.println(this.name);
        start();
    }
    public void run()
    {
        int c = 0;
        for(int i=0;i<a.length;i++)
        {
            c=c+a[i]*b[i];
        }
        System.out.print(c+"\t");
    }
}

class q1
{
    public static void main(String[] args) {
        int[][] a = {{1,2,3},{1,2,3},{1,2,3}};
        int[][] b = {{4,5},{4,5},{4,5}};
        NewThread[] t = new NewThread[a.length*b[0].length];
        int[][] c = new int[b[0].length][b.length];
        for(int i=0;i<c.length;i++)
        {
            for(int j=0;j<c[0].length;j++)
            {
                c[i][j]=b[j][i];
            }
        }
        for(int i=0;i<a.length;i++)
        {
            for(int j=0;j<b[0].length;j++)
            {
                String name = "Thread"+i+j;
                t[i+j] = new NewThread(name,a[i],c[j]);
            }
        }
    }
}