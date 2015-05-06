package fr.supinfo.labyrinthsolver.launcher;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;

import fr.supinfo.labyrinthgenerator.launcher.LabyrinthGenerator;
import fr.supinfo.labyrinthsolver.io.ReadInFile;

enum TypeCell implements Serializable {
	VIDE, MUR, START, GOAL
};

public class Launcher {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		ReadInFile file = new ReadInFile();
		
		if(args.length == 1) {
			if(args[0].endsWith(".laby")) {
				LabyrinthGenerator lab = file.read(args[0]);
				System.out.println("\nAffichage du labyrinthe.\n");
				System.out.println("\n"+lab.toString());
			} else if (args[0].endsWith(".zip")){
				ArrayList<LabyrinthGenerator> tabLab = new ArrayList<LabyrinthGenerator>();
				
				tabLab = file.readZip(args[0], tabLab);
				
				System.out.println("\nAffichage du/des labyrinthes.\n");
				
				for(int compteur = tabLab.size() - 1 ; compteur >= 0 ; compteur--) {
					System.out.println("\n"+tabLab.get(compteur).toString());
				}
			}
		} else {
			System.out.println("\n##################################################\n");
			System.out.print("\nErreur : Verifier que vous avez bien entre les parametres et avec le bon format.\n");
			System.out.println("\n##################################################\n");
		}
		
		
	}
}
