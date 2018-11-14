package chess;

import java.util.Arrays;
import java.util.Hashtable;
import java.util.Scanner;

import java.util.*;

import Pieces.Piece;
import Pieces.Bishop;
import Pieces.King;
import Pieces.Knight;
import Pieces.Pawn;
import Pieces.Queen;
import Pieces.Rook;

public class Board {
	private Hashtable<String, Integer> input_to_number = new Hashtable<String, Integer>();
	public Piece[][] matrix = new Piece[8][8];

	public Board() {

		this.UpdateHashTable();
		this.initializePieces();
		this.printInitialBoard();
		this.startGame();
		
	

	}
	
	private void startGame() {
		boolean whitePlayerMove = true;
		boolean drawOffered = false;
		boolean check = false;
		
		
		/*
		 Keep iterating until end of game or specific use case:
		 1. Read input from user.
		 2. Check if the user entered resign, if so other player wins.
		 3. Check if the user entered a draw?
		 		- place his move and make sure to get next player input
		 		- if he puts draw, then end of game
		 		- if not, set drawOfferred back to false
		 4. Conduct the move of the player
		 		- If valid
		 				- make sure to erase position of his source and place it into respective index
		 				- check if that move will result in "checkmate"
		 				- also check if it is a pawn promotion via that move
		 					- if pawn promotion, then set to Queen as default if not indicated in scanner input
		 				- also check if that move has placed his opponent in "check"
		 		- If not valid
		 			- print error message
		 			- let him try again
		 		
		 
		 */
		
		System.out.println();
		System.out.print("White's move: ");
		
		while(true) {
			Scanner sc = new Scanner(System.in);
			String command = sc.nextLine();
		    String[] items = command.split(" ");
		    if(drawOffered) {
		    	if(items[0].equalsIgnoreCase("draw")) {
		    		break;
		    	}
		    	else {  // draw has not been accepted, so keep playing and set drawOfered to false
		    		drawOffered = false;
		    	}
		    	// keep on going with the game and place the current player move to wherever he likes
		    }
		    if(items[0].equalsIgnoreCase("resign")) {
		    	this.printWinnerforResignation(whitePlayerMove);
		    	break;
		    }
		    // third index is "draw?" so conduct the move and turn boolean draw on
		    else if(items.length == 3) {
		    	// conduct move
		    	// ...
		    	
		    	drawOffered = true;
		    }
			
		    whitePlayerMove = !whitePlayerMove;
			this.printBoard(whitePlayerMove);
		}
		
		
	}
	
	private void printWinnerforResignation(boolean isWhitePlayer) {
		if(isWhitePlayer) {
			System.out.println("Black wins");
		}
		else
			System.out.println("White wins");
	}
	
	private void printBoard(boolean whitePlayerMove) {
		System.out.println();
		System.out.println();
		int count = 8;
		boolean hashtag = false;
		for(int i=7; i > -1; i--) {
			for(int j=0; j < 8; j++) {
				// occupied by a piece
				if(matrix[i][j]!=null) {
					System.out.print(matrix[i][j].color + matrix[i][j].piece);
				}
				// empty but cell is a dark spot, so fill with hashtag
				else if(hashtag) {
					System.out.print("##");
				}
				else {
					System.out.print("  ");
				}
				// empty cell and light cell, do nothing
				// flip hashtag
				System.out.print(" ");
				hashtag = !hashtag;
			}
			System.out.print(count);
			System.out.println();
			hashtag = !hashtag;
			count--;
		}
		System.out.print("a  b  c  d  e  f  g  h");
		System.out.println();
		System.out.println();
		if(whitePlayerMove)
			System.out.print("White's move: ");
		else
			System.out.print("Black's move: ");
		
		
		
		
	}
	private void printInitialBoard() {
		boolean hashtag = false;
		int count = 8;
		for(int i = 7; i > -1; i--) {
			for(int j = 0; j < 8; j++) {
				if(i > 5 || i < 2) {
					System.out.print(matrix[i][j].color + matrix[i][j].piece);
				}
				else if(hashtag) {
					System.out.print("##");
					hashtag = false;
				}
				else {
					System.out.print("  ");
					hashtag = true;
				}
				System.out.print(" ");
			}
			hashtag = !hashtag;

			System.out.print(count);
			System.out.println();
			count--;
		}
		System.out.print("a  b  c  d  e  f  g  h");
		System.out.println();
	}

	// use this to convert user input to matrix indices
	private void UpdateHashTable() {
		this.input_to_number.put("a", 0);
		this.input_to_number.put("b", 1);
		this.input_to_number.put("c", 2);
		this.input_to_number.put("d", 3);
		this.input_to_number.put("e", 4);
		this.input_to_number.put("f", 5);
		this.input_to_number.put("g", 6);
		this.input_to_number.put("h", 7);
		this.input_to_number.put("1", 0);
		this.input_to_number.put("2", 1);
		this.input_to_number.put("3", 2);
		this.input_to_number.put("4", 3);
		this.input_to_number.put("5", 4);
		this.input_to_number.put("6", 5);
		this.input_to_number.put("7", 6);
		this.input_to_number.put("8", 7);
	}

	private void initializePieces() {
		// Going to place white pieces first
		// Pawn
		matrix[1][0] = new Pawn(true);
		matrix[1][1] = new Pawn(true);
		matrix[1][2] = new Pawn(true);
		matrix[1][3] = new Pawn(true);
		matrix[1][4] = new Pawn(true);
		matrix[1][5] = new Pawn(true);
		matrix[1][6] = new Pawn(true);
		matrix[1][7] = new Pawn(true);
		// Rook
		matrix[0][0] = new Rook(true);
		matrix[0][7] = new Rook(true);
		// Knight
		matrix[0][1] = new Knight(true);
		matrix[0][6] = new Knight(true);
		// Bishop
		matrix[0][2] = new Bishop(true);
		matrix[0][5] = new Bishop(true);
		// Queen
		matrix[0][3] = new Queen(true);
		// King
		matrix[0][4] = new King(true);

		// Black Pieces
		// Pawn
		matrix[6][0] = new Pawn(false);
		matrix[6][1] = new Pawn(false);
		matrix[6][2] = new Pawn(false);
		matrix[6][3] = new Pawn(false);
		matrix[6][4] = new Pawn(false);
		matrix[6][5] = new Pawn(false);
		matrix[6][6] = new Pawn(false);
		matrix[6][7] = new Pawn(false);
		// Rook
		matrix[7][0] = new Rook(false);
		matrix[7][7] = new Rook(false);
		// Knight
		matrix[7][1] = new Knight(false);
		matrix[7][6] = new Knight(false);
		// Bishop
		matrix[7][2] = new Bishop(false);
		matrix[7][5] = new Bishop(false);
		// Queen
		matrix[7][3] = new Queen(false);
		// King
		matrix[7][4] = new King(false);

	}

}
