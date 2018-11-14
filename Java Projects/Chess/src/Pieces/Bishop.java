package Pieces;

import java.util.ArrayList;

import chess.Board;

public class Bishop extends Piece{
	
	public Bishop(boolean isWhitePlayer) {
		super("B", isWhitePlayer);
		this.isWhitePlayer = isWhitePlayer;
		// this.piece = "B";
		// this.player = playerSymbol();
	}
	

	@Override
	public boolean isValidMove(Board board, Move source, Move dest) {
		// TODO Auto-generated method stub
		possibleMoves = possibleMoves(source);
		for(Move m : possibleMoves) {
			if(m.i == dest.i && m.j == dest.j) {
				return true;
			}
		}
		return false;
	}

	@Override
	public ArrayList<Move> possibleMoves(Move source) {
		// TODO Auto-generated method stub
		possibleMoves.clear();
		
		//right diagonal movement
		int i = source.i+1;
		int j = source.j+1;
		while(j <= 8 || i <= 8) {
			possibleMoves.add(new Move(i, j));
			i += 1;
			j += 1;
		}
		i = source.i-1;
		j = source.j-1;
		while(j >= 0 || i >= 0) {
			possibleMoves.add(new Move(i, j));
			i -= 1;
			j -= 1;
		}
		
		//left diagonal movement
		i = source.i+1;
		j = source.j-1;
		while(j <= 8 || i <= 8) {
			possibleMoves.add(new Move(i, j));
			i += 1;
			j -= 1;
		}
		i = source.i-1;
		j = source.j+1;
		while(j >= 0 || i >= 0) {
			possibleMoves.add(new Move(i, j));
			i -= 1;
			j += 1;
		}
		return possibleMoves;
	}

}
