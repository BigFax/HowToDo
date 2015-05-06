package fr.supinfo.labyrinthgenerator.launcher;

import java.io.Serializable;
import java.util.HashMap;

public class LabyrinthGenerator implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private 
		int _id = 0, _nbColonne = 0, _nbLigne = 0, _min = 0, _max = 0, _random = 0, _s_ligne = 0, _s_colonne = 0;
		CellGenerator _array[][];

	LabyrinthGenerator(int nbColonne, int nbLigne) {
		this._nbColonne = nbColonne;
		this._nbLigne = nbLigne;
		this._id = 0;
		this._min = 1;
		this._max = this._nbColonne - 1;
		this._array = new CellGenerator[this._nbColonne][this._nbLigne];
	}
	
	public int getNbColonne(){ return this._nbColonne;}
	public int getNbLigne(){ return this._nbLigne;}
	public int getId(){ return this._id;}
	public int getMin(){ return this._min;}
	public int getMax(){ return this._max;}
	public CellGenerator[][] getArray(){ return this._array;}
	
	public void initialise() {
		int randomAbscisse = 0;
		int randomOrdonnee = 0;
		
		do {
			randomAbscisse = (int) (Math.random() * (this._max - this._min)) + this._min;
			this._max = _nbLigne - 1;
			randomOrdonnee = (int) (Math.random() * (this._max - this._min)) + this._min;
		} while(randomAbscisse == ((this._nbColonne - 1) / 2) && randomOrdonnee == ((this._nbLigne - 1) / 2));

		for (int y = 0; y < this._nbLigne; y++) {
			for (int x = 0; x < this._nbColonne; x++) {
				if (y == randomOrdonnee && x == randomAbscisse) {
					this._array[x][y] =  new CellGenerator(_id, x, y, TypeCell.START);
					this._s_ligne = y;
					this._s_colonne = x;
				} else if (y == this._nbLigne - 1 - randomOrdonnee && x == this._nbColonne - 1 - randomAbscisse) {
					this._array[x][y] = new CellGenerator(_id, x, y, TypeCell.GOAL);
				} else {
					this._array[x][y] = new CellGenerator(_id, x, y, TypeCell.MUR);
				}
			}
		}
	}
	
	public void create_path() {
		boolean lastLoop = true;
		int compteur = 0;
		CellGenerator compteur_id[] = new CellGenerator[this._nbColonne * this._nbLigne];
		this._min = 0;
		this._max = 4;

		//	Contient la liste des valeurs. Null si le test est négatif.
		HashMap<Integer, Integer> listRandom = new HashMap<Integer, Integer>();
		for (int i = this._min; i < this._max; i++) {
			listRandom.put(i, i);
		}
		// 0 NORD 1 EST 2 SUD 3 OUEST

		// 	Initialisation de i et de j en fonction des coordonnées de START.
		int y = this._s_ligne, x = this._s_colonne;

		// On va contenir dans le tableau "compteur_id[0]", un objet de coordonnées START.
		compteur_id[compteur] = this._array[x][y];

		// Boucle tant que compteur est supérieur à zéro, exécute le code au moins une fois !
		do {
			// Au début de tour de boucle, compteur > 0, on remplit les tests avec les bonnes valeures.
			// avec l'index et leur valeur (1-1 / 2-2 ...)

			// On fait un random
			this._random = (int) ((Math.random() * (this._max - this._min)) + this._min);
			if (this._random == listRandom.get(0)) {
				if ((y - 1) != 0 						
						&& this._array[x][y - 1].getEtat() != TypeCell.VIDE 	&& 	this._array[x][y - 2].getEtat() != TypeCell.VIDE
						&& this._array[x - 1][y - 1].getEtat() != TypeCell.VIDE && 	this._array[x + 1][y - 1].getEtat() != TypeCell.VIDE
						&& this._array[x][y - 1].getEtat() != TypeCell.START	&& 	this._array[x][y - 1].getEtat() != TypeCell.GOAL) {
					y--;
					this._array[x][y].setEtat(TypeCell.VIDE);
					compteur++;
					compteur_id[compteur] = this._array[x][y];
					for (int i = this._min; i < this._max; i++) {
						listRandom.put(i, i);
					}
				} else {
					listRandom.put(0, -1);
				}
			} else if (this._random == listRandom.get(1)) {
				if ((x + 1) != this._nbColonne - 1		
						&& this._array[x + 1][y].getEtat() != TypeCell.VIDE		&& this._array[x + 2][y].getEtat() != TypeCell.VIDE
						&& this._array[x + 1][y - 1].getEtat() != TypeCell.VIDE	&& this._array[x + 1][y + 1].getEtat() != TypeCell.VIDE
						&& this._array[x + 1][y].getEtat() != TypeCell.START	&& this._array[x + 1][y].getEtat() != TypeCell.GOAL) {
					x++;
					this._array[x][y].setEtat(TypeCell.VIDE);
					compteur++;
					compteur_id[compteur] = this._array[x][y];
					for (int i = this._min; i < this._max; i++) {
						listRandom.put(i, i);
					}
				} else {
					listRandom.put(1, -1);
				}
			} else if (this._random == listRandom.get(2)) {
				if ((y + 1) != this._nbLigne - 1		
						&& this._array[x][y + 1].getEtat() != TypeCell.VIDE		&& this._array[x][y + 2].getEtat() != TypeCell.VIDE
						&& this._array[x - 1][y + 1].getEtat() != TypeCell.VIDE	&& this._array[x + 1][y + 1].getEtat() != TypeCell.VIDE
						&& this._array[x][y + 1].getEtat() != TypeCell.START	&& this._array[x][y + 1].getEtat() != TypeCell.GOAL) {
					y++;
					this._array[x][y].setEtat(TypeCell.VIDE);
					compteur++;
					compteur_id[compteur] = this._array[x][y];
					for (int i = this._min; i < this._max; i++) {
						listRandom.put(i, i);
					}
				} else {
					listRandom.put(2, -1);
				}
			} else if (this._random == listRandom.get(3)) {
				if ((x - 1) != 0
						&& this._array[x - 1][y].getEtat() != TypeCell.VIDE		&& this._array[x - 2][y].getEtat() != TypeCell.VIDE
						&& this._array[x - 1][y - 1].getEtat() != TypeCell.VIDE	&& this._array[x - 1][y + 1].getEtat() != TypeCell.VIDE
						&& this._array[x - 1][y].getEtat() != TypeCell.START	&& this._array[x - 1][y].getEtat() != TypeCell.GOAL) {
					x--;
					this._array[x][y].setEtat(TypeCell.VIDE);
					compteur++;
					compteur_id[compteur] = this._array[x][y];
					for (int i = this._min; i < this._max; i++) {
						listRandom.put(i, i);
					}
				} else {
					listRandom.put(3, -1);
				}
			} else if(listRandom.get(0) == -1 && listRandom.get(1) == -1 && listRandom.get(2) == -1 && listRandom.get(3) == -1) {
				if(compteur > 0) {
					for (int i = this._min; i < this._max; i++) {
						listRandom.put(i, i);
					}
					compteur--;
					x = compteur_id[compteur].getAbscisse();
					y = compteur_id[compteur].getOrdonnee();
				}
				
				if (compteur <= 0 && lastLoop) {
					compteur++;
					lastLoop = false;
				}
			}
		} while (compteur > 0 || listRandom.get(0) == -1 || listRandom.get(1) == -1 || listRandom.get(2) == -1 || listRandom.get(3) == -1);
		
		this._min = 1;
		this._max = 100;
		this._random = 0;
		
		for (y = 1; y < this._nbLigne - 1; y++) {
			for (x = 1; x < this._nbColonne - 1; x++) {
				if(this._array[x][y].getEtat() == TypeCell.MUR){
					this._random = (int) ((Math.random() * (this._max - this._min)) + this._min);
					if(this._random < 10){
						this._array[x][y].setEtat(TypeCell.VIDE);
					}
				}
			}
		}
	}
	
	public String toString() {
		// TODO Auto-generated method stub
		String affichage = "";
		for(int y = 0; y < this._nbLigne; y++) {
			for(int x = 0; x < this._nbColonne; x++) {
				affichage += this._array[x][y].getAsString();
				affichage += " ";
			}
			affichage += "\n";
		}
		return affichage;
	}

}
