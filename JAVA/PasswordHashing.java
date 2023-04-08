import java.util.*;
import java.math.*;
import java.nio.charset.*;
import java.security.*;

class Password {
    String password;
    String salt;

    Password(String p, String s) {
        password = p;
        salt = s;
    }
}

class PasswordHashing {
    static String pepper = "THEDARKLORD";

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Password to Hash :");
        String password = sc.next();
        String salt = genRandString(5);
        Password p = new Password(password, salt);
        String enc = hashit(p, pepper);
        System.out.println("Enter Password to confirm :");
        String pass1 = sc.next();
        Password p1 = new Password(pass1, salt);
        String verify = hashit(p1, pepper);
        if (verify.matches(enc)) {
            System.out.println("You are Successfully Logged in!!");
        } else {
            System.out.println("Bad Luck!!");
        }
    }

    public static String genRandString(int n) {
        Random r = new Random();
        String alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
        StringBuilder sb = new StringBuilder(n);
        for (int i = 0; i < n; i++) {
            int ind = (int) (alphanum.length() * Math.random());
            sb.append(alphanum.charAt(ind));
        }
        return sb.toString();
    }

    public static String hashit(Password p, String pepper) {
        String hash = pepper + p.password + p.salt;
        for (int i = 0; i < 5; i++) {
            try {
                hash = toHexString(getSHA(hash));
            } catch (NoSuchAlgorithmException e) {
                System.out.println("Exception thrown for incorrect algorithm: " + e);
            }
        }
        return hash.toString();
    }

    public static byte[] getSHA(String input) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-256");
        return md.digest(input.getBytes(StandardCharsets.UTF_8));
    }

    public static String toHexString(byte[] hash) {
        BigInteger number = new BigInteger(1, hash);
        StringBuilder hexString = new StringBuilder(number.toString(16));
        while (hexString.length() < 64) {
            hexString.insert(0, '0');
        }
        return hexString.toString();
    }
}