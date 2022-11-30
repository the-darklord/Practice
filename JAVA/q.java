class q
{
    static double add(int x,double y)
    {
        return x+y;
    }
    static double add(double x,int y)
    {
        return x+y+1;
    }
    public static void main(String[] args)
    {
        System.out.println(add(3,3));
    }
}