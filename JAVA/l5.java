class l5 {
    public static void main(String[] args) {
        String str = "helloslkhellodjladfjhello";
        String findStr = "hello";
        int count = 0;
        while (str.contains(findStr)) {
            str = str.replaceFirst(findStr, "-");
            count++;
        }
        System.out.println(str);
        System.out.println("Number of Occurances : " + count);
    }
}
