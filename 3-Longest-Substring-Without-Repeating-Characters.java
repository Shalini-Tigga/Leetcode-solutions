public class longest_substring_without_repeating_characters {
    public static void main(String[] args) {
        String s="abcabcbb";
        int maxlength=0;
        for(int i=0;i<s.length();i++){
            String s1="";
            s1+=s.charAt(i);
            int j=i+1;
            while(j<s.length()&& !s1.contains(String.valueOf(s.charAt(j)))){
                s1+=s.charAt(j);
                j++;
            }
            maxlength=Math.max(maxlength,s1.length());
        }
        System.out.println(maxlength);
    }
}
