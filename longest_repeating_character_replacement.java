public class longest_repeating_character_replacement {
    public static void main(String args[]){
        String s="ABAB";
        int arr[]=new int[26];
        int k=2;
        int maxLength=0;
        int maxCount=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            arr[s.charAt(right)-'A']++;
            maxCount=Math.max(maxCount,arr[s.charAt(right)-'A']);
            while((right-left+1)-maxCount>k){
                arr[s.charAt(left)-'A']--;
                left++;
            }
            maxLength=Math.max(maxLength,right-left+1);
        }
        System.out.println(maxLength);
    }
}
