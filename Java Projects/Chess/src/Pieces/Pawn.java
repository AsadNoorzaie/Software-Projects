package Pieces;

import java.util.ArrayList;

import chess.Board;

public class Pawn extends Piece{
	
	public boolean doubleMove;

	public Pawn(boolean isWhitePlayer) {
		super("p", isWhitePlayer);
		this.isWhitePlayer = isWhitePlayer;
	}

	@Override
	public boolean isValidMove(Board board, Move source, Move dest) {
		// TODO Auto-generated method stub
		
		//if piece is a black piece
		if(!this.isWhitePlayer) {
			if(source.j != dest.j || source.j+1 != dest.j || source.j-1 != dest.j){
				return false;
			}else if(source.i == dest.i || source.i+1 != dest.i || source.i+2 != dest.i) {
				return false;
			}
			if(this.doubleMove == false) {
				this.doubleMove = true;
			}
			return true;
		}else { //if piece is a white piece
			if(source.j != dest.j || source.j+1 != dest.j || source.j-1 != dest.j){
				return false;
			}else if(source.i == dest.i || source.i-1 != dest.i || source.i-2 != dest.i) {
				return false;
			}
			if(this.doubleMove == false) {
				this.doubleMove = true;
			}
			return true;
		}
	}

	@Override
	public ArrayList<Move> possibleMoves(Move source) {
		possibleMoves.clear();
		
		if(!this.isWhitePlayer) {
			if(!this.doubleMove) {
				possibleMoves.add(new Move(source.i+2, source.j));
			}
			if(source.i+1 < 8 && source.j+1 < 8) {
				possibleMoves.add(new Move(source.i+1, source.j+1));
			}
			if(source.i+1 < 8 && source.j-1 < 0) {
				possibleMoves.add(new Move(source.i+1, source.j-1));
			}
			if(source.i+1 < 8) {
				possibleMoves.add(new Move(source.i+1, source.j));
			}
		}else {
			if(!this.doubleMove) {
				possibleMoves.add(new Move(source.i+2, source.j));
			}
			if(source.i-1 < 8 && source.j+1 < 8) {
				possibleMoves.add(new Move(source.i+1, source.j+1));
			}
			if(source.i-1 < 8 && source.j-1 < 0) {
				possibleMoves.add(new Move(source.i+1, source.j-1));
			}
			if(source.i-1 < 8) {
				possibleMoves.add(new Move(source.i+1, source.j));
			}
		}
		return possibleMoves;
	}
}
