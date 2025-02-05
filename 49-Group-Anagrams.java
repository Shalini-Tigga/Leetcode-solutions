
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
public class group_anagrams {
    public static void main(String args[]){
        String strs[]={"eat","tea","tan","ate","nat","bat"};
        HashMap <String,List<String>> map=new HashMap<>();
        for(String i:strs){
            char arr[]=i.toCharArray();
            Arrays.sort(arr);
            String s=Arrays.toString(arr);
            if(!map.containsKey(s)){
                map.put(s,  new ArrayList<String>());
            }
            map.get(s).add(i);
        }
        System.out.println(map.values());
    }
}
