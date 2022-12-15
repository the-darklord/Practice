import java.util.*;

class Stack <T>
{
    ArrayList<T> arr;
    int tos;
    int size;
    Stack(int size)
    {
        arr=new ArrayList<T>(size);
        this.size=size;
        tos=-1;
    }
    void push(T ele)
    {
        arr.add(ele);
        tos++;
    }
    T pop()
    {
        return arr.remove(tos--);
    }
    void Display()
    {
        for(T i:arr)
        {
            System.out.print(i+" ");
        }
    }
}

class q1
{
    public static void main(String[] args) {
        // int size=5;
        // Stack<Integer> si = new Stack<Integer>(size);
        // Stack<String> ss = new Stack<String>(size);
        // si.push(5);
        // si.push(6);
        // si.push(1);
        // si.Display();
        // ss.push("Hi");
        // ss.push("Hello");
        // ss.push("me");
        // ss.Display();
        Integer[] arr = {4,5,3,2,8};
        Display(arr);
        System.out.println();
        swap(arr,0,3);
        Display(arr);
    }
    static <T> void swap(T[] arr,int i,int j)
    {
        T temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    static <T> void Display(T[] arr)
    {
        for(T i:arr)
        {
            System.out.println(i + "\t");
        }
    }
}