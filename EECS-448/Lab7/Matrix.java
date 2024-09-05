import java.lang.Math;
import java.io.*;

public class Matrix {
	
	public static void main(String[] args){
		
		try{
			FileReader reader = new FileReader("input.txt");
			BufferedReader bufReader = new BufferedReader(reader);
			FileWriter writer = new FileWriter("output.txt");
			BufferedWriter bufWriter = new BufferedWriter(writer);
			String currentLine;
			
			while((currentLine = bufReader.readLine()) != null){
				if(currentLine.length() == 1 && Integer.parseInt(currentLine) == 0){
					System.out.println("Done!");
				}if(currentLine.length() == 1 && Integer.parseInt(currentLine) != 0){
					int size = Integer.parseInt(currentLine);
					double[][] matrix = new double[size][size];
					System.out.println("M = ");
					for(int i=0; i < size; i++){
						String splitLine[] = bufReader.readLine().split(" ");
						matrix[i] = new double[splitLine.length];
						for(int j=0; j<size; j++){
							matrix[i][j] = Integer.parseInt(splitLine[j]);
						}
					}
					
					for(int i=0; i< size; i++){
						for(int j=0; j< size; j++){
							bufWriter.write((int) matrix[i][j]);
							bufWriter.write(" ");
						}
						bufWriter.newLine();
					}
					
					//print array
					for(int i=0; i< size; i++){
						for(int j=0; j< size; j++){
							System.out.print(matrix[i][j]);
							System.out.print(" ");
						}
						System.out.println();
					}
					double det = determinant(size, matrix);
					System.out.println("det(M) = " + det);
					System.out.println("Minv =");
					double[][] inv = new double[size][size];
					inv = inverse(size, matrix);
					for(int i=0; i< size; i++){
						for(int j=0; j< size; j++){
							System.out.print(inv[i][j]);
							System.out.print(" ");
						}
						System.out.println();
					}
					
				}
			}
		}catch(Exception e){
			System.out.println("Error: File doesn't exist!");
		}
		
	}
	
	double determinant(int size, double[][]matrix){
		
		double det = 0;
		if(size == 1){
			det = matrix[0][0];
		}else if(size == 2){
			det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		}else{
			for(int i=0; i<size; i++){
				det += Math.pow(-1.0, (double)i) * matrix[0][i] * subMatrix(0,i).determinant();
			}
		}
		return 0;
	}
	
	double[][] subMatrix(int size, int r, int c, double[][] matrix){
		
		double[][] sub = new double[size-1][size-1];
		int row = 0;
		for(int i=0; i<size; i++){
			if(i == r) continue;
			int col = 0;
			for(int j=0; j<size; j++){
				if(j == c) continue;
				sub[row][col] = matrix[i][j];
				col++;
			}
			row++;
		}
		return sub;
	}
	
	static double[][] inverse(int size, double[][] matrix){
		double[][] inverse = new double[size][size];
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				inverse[i][j] = Math.pow(-1.0, (double) i +j) * determinant(size, subMatrix(size, j, i, matrix)) / determinant(size, matrix);
			}
		}
		return inverse;
	}
}
