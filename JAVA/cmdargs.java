class cmdargs
{
    public static void main(String[] args) {
        Double sum=0.0;
        for(String i:args)
        {
            System.out.print(i+" ");
            sum+=Integer.valueOf(i);
        }
        Double res=(sum)/(args.length);
        System.out.println("\nAverage is "+res);
    }
}