public class palindromic_substring {
        static int countSubstrings(String s) {
            int count=0;
            for(int i=0;i<s.length();i++){
                count+=countPalindromeAroundCenter(s,i,i);
                count+=countPalindromeAroundCenter(s,i,i+1);
            }
            return count;
        }
        static int countPalindromeAroundCenter(String s, int left,int right){
            int count=0;
            while(left>=0 && right<s.length() && s.charAt(left)==s.charAt(right)){
                left--;
                right++;
                count++;
            }
            return count;
        }
        public static void main(String[] args) {
            String s="aaa";
            System.out.println(countSubstrings(s));
        }
}
