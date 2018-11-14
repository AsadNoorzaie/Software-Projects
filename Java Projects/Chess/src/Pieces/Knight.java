package Pieces;

import java.util.ArrayList;

import chess.Board;

public class Knight extends Piece {

	public Knight(boolean isWhitePlayer) {
		super("N", isWhitePlayer);
		this.isWhitePlayer = isWhitePlayer;

	}

	@Override
	public boolean isValidMove(Board board, Move source, Move dest) {
		if (source.i < 0 || source.j < 0 || source.i > 7 || source.j > 7 || dest.i < 0 || dest.j < 0 || dest.i > 7
				|| dest.j > 7)
			return false;
		
		this.possibleMoves = new ArrayList<Move>();
		this.possibleMoves = possibleMoves(board, source);
		for(Move possible_dest : this.possibleMoves) {
			if(possible_dest.i == dest.i && possible_dest.j == dest.j) {
				return true;
			}
		}
		return false;
	}

	@Override
	public ArrayList<Move> possibleMoves(Board board, Move source) {
		possibleMoves.clear();
		if(this.isOccupied(board, new Move(source.i + 2, source.j + 1)))
			possibleMoves.add(new Move(source.i + 2, source.j + 1));
		
		if(this.isOccupied(board, new Move(source.i + 2, source.j - 1)))
			possibleMoves.add(new Move(source.i + 2, source.j - 1));
		
		if(this.isOccupied(board, new Move(source.i + 1, source.j + 2)))
			possibleMoves.add(new Move(source.i + 1, source.j + 2));
		
		if(this.isOccupied(board, new Move(source.i + 1, source.j - 2)))
			possibleMoves.add(new Move(source.i + 1, source.j - 2));
		
		if(this.isOccupied(board, new Move(source.i - 2, source.j - 1)))
			possibleMoves.add(new Move(source.i - 2, source.j - 1));
		
		if(this.isOccupied(board, new Move(source.i - 2, source.j + 1)))
			possibleMoves.add(new Move(source.i - 2, source.j + 1));
		
		
		if(this.isOccupied(board, new Move(source.i - 1, source.j + 2)))
			possibleMoves.add(new Move(source.i - 1, source.j + 2));
		
		if(this.isOccupied(board, new Move(source.i - 1, source.j - 2)))
			possibleMoves.add(new Move(source.i - 1, source.j - 2));
		
		return possibleMoves;
	}

}
