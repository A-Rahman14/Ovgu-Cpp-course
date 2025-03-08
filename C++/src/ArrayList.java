public class ArrayList {
	private int siz;
	private final int capa = 10;
	private static int[] a;
	public int size() {
		return this.siz;
	}
	public int capacity() {
		return a.length;
	}
	public ArrayList() {
		a = new int[capa];
	}
	public void reserve(int newSize) {
		int[] b = a.clone();
		a = new int[a.length + newSize];
		for (int i = 0; i<b.length; i++) {
			a[i] = b[i];
		}
		return;
	}
	public void push_back(int element) {
		if (siz < a.length) {
			a[siz] = element;
			++this.siz;
		} else {
			this.reserve(capa);
			this.push_back(element);
		}
		
		return;
	}
	public void pop_back() {
		--this.siz;
		a[this.siz] = 0;
		return;
	}
	public int get_at(int index) {
		return a[index];
	}
	public void set_at(int index, int element) {
		a[index-1] = element;
		return;
	}
	public void insert(int index, int element) {
		int[] b = a.clone();
		a[index] = element;
		++this.siz;
		for (int i = index; i<a.length-1; i++) {
			a[i+1] = b[i];
		}
		return;
	}
	public void erase(int index, int length) {
		for (int i = length; length > 0; length--) {
			a[index] = a[index+i];
			a[index+i] = 0;
			--this.siz;
			index++;
		}
		return;
	}
	public static void main(String[] args) {
		
	}
}

//Bearbeitet bei Abdelhalim Abdelhalim & abdelrahman Abdelhalim