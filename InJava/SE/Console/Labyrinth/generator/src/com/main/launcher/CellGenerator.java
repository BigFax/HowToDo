package fr.supinfo.labyrinthgenerator.launcher;

import java.io.Serializable;

public class CellGenerator implements Serializable{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private 
		int _id, _abscisse, _ordonnee;
		TypeCell _etat;
	
	CellGenerator(int id, int abscisse, int ordonnee, TypeCell typeCell) {
		this._id = id;
		this._abscisse = abscisse;
		this._ordonnee = ordonnee;
		this._etat = typeCell;
	}

	public int getId() { return _id; }
	public 	TypeCell getEtat() { return _etat; }
	public 	int getAbscisse() { return _abscisse; }
	public 	int getOrdonnee() { return _ordonnee; }

	public 	void setId(int id) { this._id = id; }
	public 	void setAbscisse(int abscisse) { this._abscisse = abscisse; }
	public 	void setOrdonnee(int ordonnee) { this._ordonnee = ordonnee; }
	public 	void setEtat(TypeCell etat) { this._etat = etat; }
	 	
	public String getAsString(){
 			if(this._etat == TypeCell.VIDE)
 				return "_";
 			else if(this._etat == TypeCell.MUR)
 				return "X";
 			else if(this._etat == TypeCell.START)
 				return "S";
 			else if(this._etat == TypeCell.GOAL)
 				return "G";
 			else
 				return "-1";
	 	}
	 	
		
}
