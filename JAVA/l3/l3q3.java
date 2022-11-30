import java.util.Scanner;

class Mixer
{
    static int arr[];
    public static void accept(int array[])
    {
        for(int i=0;i<array.length;i++)
        {
            for(int j=0;j<array.length-i-1;j++)
            {
                if(array[j]>array[j+1])
                {
                    array[j]=array[j]+array[j+1];
                    array[j+1]=array[j]-array[j+1];
                    array[j]=array[j]-array[j+1];
                }
            }
        }
    }
    void display()
    {
        for(int i=0;i<arr.length;i++)
        {
            System.out.print(arr[i]+" ");
        }
    }
    public Mixer[] mix(Mixer A[])
    {
        return(A);
    }
}
class l3q3
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter array size : ");
        int n=sc.nextInt();
        int array[] = new int[n];
        System.out.println("Enter array elements : ");
        for(int i=0;i<n;i++)
        {
            array[i]=sc.nextInt();
        }
    }
}