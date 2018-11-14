package Pieces;

import java.util.ArrayList;


import chess.Board;

public abstract class Piece {
	
	
	public boolean isWhitePlayer;
	public String color = "";
	public String piece = "";
	
	public ArrayList<Move> possibleMoves = new ArrayList<Move>();
	
	public Piece(String piece, boolean isWhitePlayer){
		this.color = isWhitePlayer ? "w" : "b" ;
		this.piece = piece;
	}

	public boolean isOccupied(Board board, Move dest) {
		
		if (dest.i < 0 || dest.j < 0 || dest.i > 7 || dest.j > 7)
			return false;
		
		if(board.matrix[dest.i][dest.j] != null) {
			if(isFriendly(board, dest))
				return false;
			else
				return true;
		}
		else
			return true;
	}
	
	public boolean isFriendly(Board board, Move dest) {
		if(board.matrix[dest.i][dest.j].isWhitePlayer == this.isWhitePlayer) {
			return true;
		}
		else if(!board.matrix[dest.i][dest.j].isWhitePlayer == !this.isWhitePlayer){
			return true;
		}
		else{
			return false;
		}
	}

	

	public abstract boolean isValidMove(Board board, Move source, Move dest);
	

	public abstract ArrayList<Move> possibleMoves(Board board, Move source);

}
