package _003_LongestSubstringWithoutRepeatingCharacters;

import java.util.HashSet;
import java.util.Set;

public class Solutions {
	public static void main(String[] args) {
		Solution_p so = new Solution_p();
        String s = "abcabcbb";
		int res = so.lengthOfLongestSubstring(s);
		System.out.println(res);
	}
}

class Solution {
	public int lengthOfLongestSubstring(String s) {
		int len = s.length();
		Set<Character> set = new HashSet<>();
		int res = 0, i = 0, j = 0;
		while (i < len && j < len) {
			if (!set.contains(s.charAt(j))) {
				set.add(s.charAt(j++));
				res = Math.max(res, j - i);
			} else {
				set.remove(s.charAt(i++));
			}
		}
		return res;
	}
}