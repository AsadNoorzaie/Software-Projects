package Pieces;

import java.util.ArrayList;

import chess.Board;

public class Rook extends Piece {

	public Rook(boolean isWhitePlayer) {
		super("R", isWhitePlayer);
		this.isWhitePlayer = isWhitePlayer;
	}

	
	@Override
	public boolean isValidMove(Board board, Move source, Move dest) {
		if (source.i < 0 || source.j < 0 || source.i > 7 || source.j > 7 || dest.i < 0 || dest.j < 0 || dest.i > 7
				|| dest.j > 7)
			return false;

		this.possibleMoves = new ArrayList<Move>();
		this.possibleMoves = possibleMoves(board, source);
		for (Move possible_dest : this.possibleMoves) {
			if (possible_dest.i == dest.i && possible_dest.j == dest.j) {
				return true;
			}
		}

		return false;
	}

	@Override
	public ArrayList<Move> possibleMoves(Board board, Move source) {
		possibleMoves.clear();

		int j = source.j;
		// go down the respective row
		for (int i = source.i - 1; i > -1; i--) {
			// if spot is empty then that is a possible move
			if (board.matrix[i][j] == null) {
				possibleMoves.add(new Move(i, j));
			} else {
				// there is a piece, if not friendly --> add
				if (!this.isFriendly(board, new Move(i, j))) {
					possibleMoves.add(new Move(i, j));
					break;
				} else
					break;
			}
		}

		// go up the respective row
		for (int i = source.i + 1; i < 8; i++) {
			// if spot is empty then that is a possible move
			if (board.matrix[i][j] == null) {
				possibleMoves.add(new Move(i, j));
			} else {
				// there is a piece, if not friendly --> add
				if (!this.isFriendly(board, new Move(i, j))) {
					possibleMoves.add(new Move(i, j));
					break;
				} else
					break;
			}
		}

		// go sideways (left) with the respective row
		int i = source.i;
		for (j = source.j-1; j > -1; j--) {
			// if spot is empty then that is a possible move
			if (board.matrix[i][j] == null) {
				possibleMoves.add(new Move(i, j));
			} else {
				// there is a piece, if not friendly --> add
				if (!this.isFriendly(board, new Move(i, j))) {
					possibleMoves.add(new Move(i, j));
					break;
				} else
					break;
			}
		}

		// go sideways (right) with the respective row
		for (j = source.j+1; j < 8; j++) {
			// if spot is empty then that is a possible move
			if (board.matrix[i][j] == null) {
				possibleMoves.add(new Move(i, j));
			} else {
				// there is a piece, if not friendly --> add
				if (!this.isFriendly(board, new Move(i, j))) {
					possibleMoves.add(new Move(i, j));
					break;
				} else
					break;
			}
		}

		return possibleMoves;
	}

}
