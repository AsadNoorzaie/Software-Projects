package Pieces;

public class Move {
	public int i;
	public int j;	
	public boolean valid;
	
	public Move(int i, int j) {
		this.i = i;
		this.j = j;
		this.valid = validPos();
	}
	
	public boolean validPos() {
		if(this.i < 0 || this.i > 7 || this.j < 0 || this.j > 7)
			return false;
		
		return true;
	}
	
}
