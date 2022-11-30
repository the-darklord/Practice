import java.util.Scanner;
class ex2
{
    public static void main (String[] args)
    {
        int a,b,c;

        System.out.println("Enter 3 numbers : ");
        Scanner sc =new Scanner(System.in);
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();

        if(a<b && a<c)
        {
            System.out.println(a+" is least");
        }
        else if(b<a && b<c)
        {
            System.out.println(b+" is least");
        }
        else
        {
            System.out.println(c+" is least");
        }

    }
}
