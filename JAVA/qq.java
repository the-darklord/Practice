class Result
{
    int[][] arr1 = new int[3][4];
    int[] arr2 = new int[3];
    void store(int[] rollnum,int[] sub1,int[] sub2,int[] sub3)
    {
        for(int i=0;i<arr1.length;i++)
        {
            arr1[i][0] = rollnum[i];
            arr1[i][1] = sub1[i];
            arr1[i][2] = sub2[i];
            arr1[i][3] = sub3[i];
        }
    }
    void total()
    {
        for(int i=0;i<arr2.length;i++)
        {
            arr2[i] = arr1[i][1] + arr1[i][2] + arr1[i][3];
        }
    }
    void subhigh()
    {
        int large1 = arr1[0][1],large2 = arr1[0][2],large3 = arr1[0][3],j1=0,j2=0,j3=0;
        for(int i=1;i<3;i++)
        {
            if(arr1[i][1] > large1)
            {
                large1 = arr1[i][1];
                j1=i;
            }
            if(arr1[i][2] > large2)
            {
                large2 = arr1[i][2];
                j2=i;
            }
            if(arr1[i][3] > large3)
            {
                large3 = arr1[i][3];
                j3=i;
            }
        }
        System.out.println("Roll Number and Marks of student who scored highest in sub1 are \t"+arr1[j1][0]+"\t, "+large1);
        System.out.println("Roll Number and Marks of student who scored highest in sub2 are \t"+arr1[j2][0]+"\t, "+large2);
        System.out.println("Roll Number and Marks of student who scored highest in sub3 are \t"+arr1[j3][0]+"\t, "+large3);
    }
    void tothigh()
    {
        int j=0,large=arr2[0];
        for(int i=1;i<3;i++)
        {
            if(arr2[i] > large)
            {
                large = arr2[i];
                j=i;
            }
        }
        System.out.println("Roll Number and Marks of student who scored highest total are \t\t"+arr1[j][0]+"\t, "+large);
    }
}
class qq
{
    public static void main(String[] args)
    {
        Result r1 = new Result();
        int[] rollnum = {368,143,252};
        int[] sub1 = {50,40,45};
        int[] sub2 = {40,30,45};
        int[] sub3 = {50,55,45};
        r1.store(rollnum,sub1,sub2,sub3);
        r1.total();
        r1.subhigh();
        r1.tothigh();
    }
}