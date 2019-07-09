package _705_DesignHashSet;


public class Solutions {
	/*
	using boolean array
	table_style = [
    [0, 1000, 10000, ..., 1000000],
    [1, 1001, 10001, ..., 0],
    .
    .
    [999, 1999, 19999, ..., 0]
	 */

    public static void main(String[] args) {
        Solutions so = new Solutions();
        so.add(1);
        so.add(9);
        so.add(5);
        System.out.println(so.contains(1));
        System.out.println(so.contains(9));
        System.out.println(so.contains(5));

        so.remove(9);
        System.out.println(so.contains(1));
        System.out.println(so.contains(9));
        System.out.println(so.contains(5));
    }

    private int buckets = 1000;
    private int itemsPerBucket = 1001;
    private boolean[][] table;

    public Solutions() {
        table = new boolean[buckets][];
    }

    public int hash(int key) {
        return key % buckets;
    }

    public int pos(int key) {
        return key / buckets;
    }

    public void add(int key) {
        int hashkey = hash(key);

        if (table[hashkey] == null) {
            table[hashkey] = new boolean[itemsPerBucket];
        }
        table[hashkey][pos(key)] = true;
    }

    public void remove(int key) {
        int hashkey = hash(key);

        if (table[hashkey] != null)
            table[hashkey][pos(key)] = false;
    }

    public boolean contains(int key) {
        int hashkey = hash(key);
        return table[hashkey] != null && table[hashkey][pos(key)];
    }
}
