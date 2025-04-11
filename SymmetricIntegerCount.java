public class SymmetricIntegerCounter {

    public static int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; i++) {
            String s = Integer.toString(i);
            int len = s.length();

            if (len % 2 == 0) {
                int half = len / 2;
                int leftSum = 0, rightSum = 0;

                for (int j = 0; j < half; j++) {
                    leftSum += s.charAt(j) - '0';
                }

                for (int j = half; j < len; j++) {
                    rightSum += s.charAt(j) - '0';
                }

                if (leftSum == rightSum) {
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        System.out.println(countSymmetricIntegers(1, 100));        // Output: 9
        System.out.println(countSymmetricIntegers(1200, 1230));    // Output: 4
    }
}
