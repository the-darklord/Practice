import java.util.ArrayList;
import java.util.LinkedList;

class Swap<T> {
    void swap(T[] arr, int pos1, int pos2) {
        T temp;
        temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    void Display(T[] arr) {
        for (T i : arr) {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}

class Stack<T> {
    ArrayList<T> arr;
    int tos;

    void Initialize(int size) {
        this.arr = new ArrayList<T>(size);
        tos = -1;
    }

    void Push(T ele) {
        arr.add(ele);
        tos++;
    }

    void Pop() {
        System.out.print("\nPopped : " + arr.get(tos).toString());
        arr.remove(tos--);
    }

    void Display() {
        for (T i : arr) {
            System.out.print(i.toString());
        }
    }
}

class Student {
    String name;
    int rollnum;
    Double grade;

    Student(String name, int rollnum, Double grade) {
        this.name = name;
        this.rollnum = rollnum;
        this.grade = grade;
    }

    public String toString() {
        return "\nName : " + name + "\t Roll Number : " + rollnum + "\t Grade : " + grade + "\n";
    }
}

class Employee {
    String name;
    int empid;

    Employee(String name, int empid) {
        this.name = name;
        this.empid = empid;
    }

    public String toString() {
        return "\nName : " + name + "\t Employee I'D : " + empid + "\n";
    }
}

class l10 {
    public static void main(String[] args) {
        Swap<Integer> i = new Swap<Integer>();
        Integer[] ari = { 5, 3, 2, 4, 1, 9, 7, 8 };
        i.Display(ari);
        i.swap(ari, 2, 6);
        i.Display(ari);
        Student s1, s2;
        s1 = new Student("Mihir", 57, 8.75);
        s2 = new Student("TDL", 27, 9.75);
        Stack<Student> s = new Stack<Student>();
        s.Initialize(5);
        s.Push(s1);
        s.Push(s2);
        Employee e1, e2;
        e1 = new Employee("PGM", 368);
        e2 = new Employee("KODI", 252);
        Stack<Employee> e = new Stack<Employee>();
        e.Initialize(5);
        e.Push(e1);
        e.Push(e2);
        s.Display();
        e.Display();
        s.Pop();
        e.Pop();
        s.Display();
        e.Display();
        LinkedList<Integer> li = new LinkedList<Integer>();
        li.addFirst(5);
        li.addFirst(4);
        li.addLast(6);
        li.addLast(7);
        System.out.println(li);
        li.removeFirst();
        li.removeLast();
        System.out.println(li);
        LinkedList<Double> ld = new LinkedList<Double>();
        ld.addFirst(5.0);
        ld.addFirst(4.0);
        ld.addLast(6.0);
        ld.addLast(7.0);
        System.out.println(ld);
        ld.removeFirst();
        ld.removeLast();
        System.out.println(ld);
    }
}