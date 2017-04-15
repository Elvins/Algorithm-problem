package com.NCBICrawler.crawler;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/**
 * 后缀自动机，用于LCS
 * 
 * @author Elvins
 *
 */
public class SuffixAutomaton {

	Node root, last, cnt;
	int size;

	SuffixAutomaton() {
		root = new Node(0, null);
		last = root;
		size = 1;
	}

	void expend(char c) {
		size++;
		cnt = new Node();
		cnt.len = last.len + 1;
		Node p;
		for (p = last; p != null && !p.trans.containsKey(c); p = p.pre) {
			p.trans.put(c, cnt);
		}
		if (p == null) {
			cnt.pre = root;
		} else {
			Node q = p.trans.get(c);
			if (q.len == (p.len + 1)) {
				cnt.pre = q;
			} else {
				size++;
				Node clone = new Node();
				clone.len = p.len + 1;
				clone.pre = q.pre;
				// map深度复制
				for (Iterator<Character> keyIt = q.trans.keySet().iterator(); keyIt.hasNext();) {
					Character key = keyIt.next();
					clone.trans.put(key, q.trans.get(key));
				}

				for (; p != null && p.trans.get(c) == q; p = p.pre) {
					p.trans.put(c, clone);
				}
				q.pre = cnt.pre = clone;
			}
		}
		last = cnt;
	}

	void build(String s) {
		int l = s.length();
		for (int i = 0; i < l; i++) {
			expend(s.charAt(i));
		}
	}

	int findLCS(String s) {
		int ans = 0, len = s.length(), t = 0;
		Node now = root;
		for (int i = 0; i < len; i++) {
			char x = s.charAt(i);
			if (now.trans.containsKey(x)) {
				now = now.trans.get(x);
				t++;
			} else {
				while (now != null && !now.trans.containsKey(x)) {
					now = now.pre;
				}
				if (now == null) {
					now = root;
					t = 0;
				} else {
					t = now.len + 1;
					now = now.trans.get(x);
				}
			}
			ans = ans > t ? ans : t;
		}
		return ans;
	}

}

class Node {
	Map<Character, Node> trans;
	Node pre;
	int len;

	Node() {
		this.len = 0;
		this.pre = null;
		trans = new HashMap<Character, Node>();
	}

	Node(int len, Node pre) {
		this.len = len;
		this.pre = pre;
		trans = new HashMap<Character, Node>();
	}
}
