package Pieces;

import java.util.ArrayList;

import chess.Board;

public class King extends Piece {

	public King(boolean isWhitePlayer) {
		super("K", isWhitePlayer);
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

		if (board.matrix[source.i + 1][source.j] == null) {
			possibleMoves.add(new Move(source.i + 1, source.j));
		} else {
			if (this.isFriendly(board, new Move(source.i + 1, source.j)))
				possibleMoves.add(new Move(source.i + 1, source.j));
		}

		if (board.matrix[source.i - 1][source.j] == null) {
			possibleMoves.add(new Move(source.i - 1, source.j));
		} else {
			if (!this.isFriendly(board, new Move(source.i - 1, source.j)))
				possibleMoves.add(new Move(source.i - 1, source.j));
		}

		if (board.matrix[source.i][source.j + 1] == null) {
			possibleMoves.add(new Move(source.i, source.j + 1));
		} else {
			if (!this.isFriendly(board, new Move(source.i, source.j + 1)))
				possibleMoves.add(new Move(source.i, source.j + 1));
		}

		if (board.matrix[source.i + 1][source.j - 1] == null) {
			possibleMoves.add(new Move(source.i + 1, source.j - 1));
		} else {
			if (!this.isFriendly(board, new Move(source.i + 1, source.j - 1)))
				possibleMoves.add(new Move(source.i + 1, source.j - 1));
		}

		if (board.matrix[source.i - 1][source.j - 1] == null) {
			possibleMoves.add(new Move(source.i - 1, source.j - 1));
		} else {
			if (!this.isFriendly(board, new Move(source.i - 1, source.j - 1)))
				possibleMoves.add(new Move(source.i - 1, source.j - 1));
		}

		if (board.matrix[source.i + 1][source.j - 1] == null) {
			possibleMoves.add(new Move(source.i + 1, source.j - 1));
		} else {
			if (!this.isFriendly(board, new Move(source.i + 1, source.j - 1)))
				possibleMoves.add(new Move(source.i + 1, source.j - 1));
		}

		if (board.matrix[source.i + 1][source.j + 1] == null) {
			possibleMoves.add(new Move(source.i + 1, source.j + 1));
		} else {
			if (!this.isFriendly(board, new Move(source.i + 1, source.j + 1)))
				possibleMoves.add(new Move(source.i + 1, source.j + 1));
		}

		if (board.matrix[source.i - 1][source.j + 1] == null) {
			possibleMoves.add(new Move(source.i + 1, source.j + 1));
		} else {
			if (!this.isFriendly(board, new Move(source.i - 1, source.j + 1)))
				possibleMoves.add(new Move(source.i - 1, source.j + 1));
		}

		return possibleMoves;
	}

}
