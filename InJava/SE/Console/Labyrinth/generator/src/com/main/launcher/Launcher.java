package fr.supinfo.labyrinthgenerator.launcher;

import java.io.IOException;
import java.io.Serializable;

import fr.supinfo.labyrinthgenerator.io.WriteInFile;


enum TypeCell implements Serializable {
	VIDE, MUR, START, GOAL
};

public class Launcher {
	public static void main(String[] args) {
		// Test avec le tableau args[].
		//int nbColonne = 25, nbLigne = 25, compteur = 0;
		
		int compteur = 0, arguments[] = new int[args.length];
		int min = 5, max = 100;
		
		try {
			arguments[0] = Integer.parseInt(args[1]);
			arguments[1] = Integer.parseInt(args[2]);
		} catch (Exception e) {
			System.out.println("\n##################################################\n");
			System.out.print("\nErreur : Verifier que vous avez bien entre les parametres et avec le bon format.\n");
			System.out.println("\n##################################################\n");
			System.exit(1);
		}
		
		if(args[0].equals("single") && args[args.length - 1].endsWith(".laby") && args.length == 4) {
			if (arguments[0] >= min && arguments[0] <= max && arguments[1] >= min && arguments[1] <= max) {
				WriteInFile file = new WriteInFile();
				LabyrinthGenerator plateau = new LabyrinthGenerator(arguments[0], arguments[1]);
				plateau.initialise();
				plateau.create_path();
				file.write(plateau, args[3]);
				System.out.println("\nFichier cree avec success !\n");
			} else {
				System.out.println("\n##################################################\n");
				System.out.println("\nCoordonnees incorrectes...\nEntrer des coordonnees comprises entre "+min+" "+max+" (valeures incluses).\n");
				System.out.println("\n##################################################\n");
			}
		} else if(args[0].equals("multiple") && args[args.length - 1].endsWith(".zip") && arguments[0] <= 10000 && arguments[0] > 0 && args.length == 5){
			try {
			arguments[2] = Integer.parseInt(args[3]);
			} catch (Exception e) {
				System.out.println("\n##################################################\n");
				System.out.print("\nErreur : Verifier que vous avez bien entre les parametre et avec le bon format.\n");
				System.out.println("\n##################################################\n");
				System.exit(1);
			}
			if (arguments[1] >= min && arguments[1] <= max && arguments[2] >= min && arguments[2] <= max) {
				WriteInFile file = new WriteInFile();
				try {
					file.writezip(args[4]);
					while (compteur < arguments[0]) {
						LabyrinthGenerator plateau = new LabyrinthGenerator(arguments[1], arguments[2]);
						plateau.initialise();
						plateau.create_path();
						
						file.write(plateau, "Labyrinth"+(compteur + 1)+".laby");
						file.addzip(plateau, "Labyrinth"+(compteur + 1)+".laby");
						file.delete("Labyrinth"+(compteur + 1)+".laby");
						
						compteur++;
					}
					System.out.println("\nFichiers crees avec success !\n");
					file.close();
				} catch (IOException e) {
					System.out.println("\n##################################################\n");
					System.out.print("Erreur : ");
					e.printStackTrace();
					System.out.println("\n##################################################\n");
					System.exit(1);
				}
			} else {
				System.out.println("\n##################################################\n");
				System.out.println("\nCoordonnees incorrectes...\nEntrer des coordonnees comprises entre "+min+" "+max+" (valeures incluses).\n");
				System.out.println("\n##################################################\n");
			}
		} else {
			System.out.println("\n##################################################\n");
			System.out.println("\nErreur. Cela peut etre cause par :\n");
			System.out.println("- Mauvais choix pour le type. Veuillez choisir single ou multiple.\n");
			System.out.println("- Mauvaise extension de fichier. Veuillez choisir .laby pour le type single. Veuillez choisir .zip pour le type multiple.\n");
			System.out.println("- Mauvaise choix de parametre. Parametre dans ce format : \" single/multiple [nbre repetition] x y fichier.\n");
			System.out.println("\n##################################################\n");
		}
	}
}
